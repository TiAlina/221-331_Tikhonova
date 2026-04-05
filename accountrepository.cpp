#include "accountrepository.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

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

