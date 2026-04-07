#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include <QList>
#include <QString>
#include <QByteArray>


#include "account.h"

class AccountRepository
{
public:
    QList<Account> loadAccounts(const QString &filePath, QString *errorMessage = nullptr) const;
private:
    QByteArray deriveKey(const QString &pinCode) const;
    QByteArray decryptToJson (const QString &filePath, const QString &pinCode, QString *errorMessage) const;
    QList<Account> parseAccountsJson(QByteArray *jsonData, QString *errorMessage) const;
};

#endif // ACCOUNTREPOSITORY_H
