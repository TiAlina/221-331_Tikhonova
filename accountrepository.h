  #ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include <QList>
#include <QString>

#include "account.h"

class AccountRepository
{
public:
    QList<Account> loadAccounts(const QString &filePath, QString *errorMessage = nullptr) const;
};

#endif // ACCOUNTREPOSITORY_H
