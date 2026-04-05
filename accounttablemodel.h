#ifndef ACCOUNTTABLEMODEL_H
#define ACCOUNTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "account.h"

    class AccountTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccountTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setAccounts(const QList<Account> &newAccounts);

private:
    QList<Account> m_accounts;
};

#endif // ACCOUNTTABLEMODEL_H
