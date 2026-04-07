#include "accountrepository.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <openssl/sha.h>
#include <cstring>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/sha.h>


namespace {
constexpr char kVaultMagic[] = {'A', 'T', 'P', 'M'};
constexpr quint8 kVaultVersion = 1;
constexpr qint64 kHeaderSize = 4 + 1 + 16;
constexpr qint64 kChunkSize = 4096;

QString invalidPinMessage()
{
    return QStringLiteral("Неверный код или файл");
}
}

QList<Account> AccountRepository::loadAccounts(const QString &filePath, QString *errorMessage) const
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        if (errorMessage) {
            *errorMessage = "Не удалось открыть файл: " + filePath;
        }
        return {};
    }

    QByteArray rawData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(rawData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        if (errorMessage) {
            *errorMessage = "Ошибка JSON: " + jsonError.errorString();
        }
        return {};
    }

    if (!document.isArray()) {
        if (errorMessage) {
            *errorMessage = "JSON должен содержать массив записей.";
        }
        return {};
    }

    QList<Account> result;
    QJsonArray array = document.array();

    for (const QJsonValue &value : array) {
        if (!value.isObject()) {
            continue;
        }

        QJsonObject obj = value.toObject();

        QString site = obj.value("site").toString();
        QString login = obj.value("login").toString();
        QString password = obj.value("password").toString();

        if (site.isEmpty() || login.isEmpty() || password.isEmpty())
        {
            continue;
        }

        result.append({site, login, password});
    }

    if (result.isEmpty() && errorMessage) {
        *errorMessage = "Файл прочитан, но корректных записей не найдено.";
    }

    return result;
}

QByteArray AccountRepository::deriveKey(const QString &pinCode) const
{
    const QByteArray pinBytes = pinCode.toUtf8();

    QByteArray key(SHA256_DIGEST_LENGTH, Qt::Uninitialized);

    SHA256(reinterpret_cast<const unsigned char *>(pinBytes.constData()),
        static_cast<size_t>(pinBytes.size()),
        reinterpret_cast<unsigned char *>(key.data()));

    return key;
}


QByteArray AccountRepository::decryptToJson(const QString &filePath, const QString &pinCode, QString *errorMessage) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Не открылся файл хранилища =(");
        }
        return {};
    }

    const QByteArray header = file.read(kHeaderSize);
    if (header.size() != kHeaderSize || std::memcmp(header.constData(), kVaultMagic, sizeof(kVaultMagic)) != 0 || static_cast<quint8>(header.at(4)) != kVaultVersion) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Некорректный формат хранилища >(");
        }
        return {};
    }

    const QByteArray iv = header.mid(5,16);
    QByteArray key = deriveKey(pinCode);

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        OPENSSL_cleanse(key.data(), static_cast<size_t>(key.size()));
            if (errorMessage) {
            *errorMessage = QStringLiteral("Ошибка инициализации");
        }
            return {};
    }

    const int initResult = EVP_DecryptInit_ex(
        ctx,
        EVP_aes_256_cbc(),
        nullptr,
        reinterpret_cast<const unsigned char *>(key.constData()),
        reinterpret_cast<const unsigned char *>(iv.constData()));
    OPENSSL_cleanse(key.data(), static_cast<size_t>(key.size()));

    if (initResult != 1) {
        EVP_CIPHER_CTX_free(ctx);
        if (errorMessage) {
            *errorMessage = QStringLiteral("Ошибка AES-256 дешифрования");
          }
        return {};
    }
}















