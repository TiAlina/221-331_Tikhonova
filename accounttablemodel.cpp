#include "accounttablemodel.h"

AccountTableModel::AccountTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int AccountTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_accounts.size();
}

int AccountTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return 3;
}

QVariant AccountTableModel::data(const QModelIndex &index, int role)
    const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() < 0 || index.row() >= m_accounts.size()) {
        return QVariant();
    }

    const Account &account = m_accounts[index.row()];

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return account.site;
        case 1:
            return QString(account.login.length(), '*');
        case 2:
            return QString(account.password.length(), '*');
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QVariant AccountTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "Сайт";
        case 1:
            return "Логин";
        case 2:
            return "Пароль";
        default:
            return QVariant();
        }
    }

    return QVariant();
}

void AccountTableModel::setAccounts(const QList<Account> &newAccounts)
{
    beginResetModel();
    m_accounts = newAccounts;
    endResetModel();
}
