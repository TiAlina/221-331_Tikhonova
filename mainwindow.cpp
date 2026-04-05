#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAbstractItemView>
#include <QHeaderView>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new AccountTableModel(this))
    , proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);

    setWindowTitle("Lab 1 Password Manager");
    resize(800, 600);

    ui->labelMessage->setText("");
    ui->stackedWidgetPages->setCurrentWidget(ui->pageLogin);

    QString errorMessage;
    accounts = repository.loadAccounts("accounts.json", &errorMessage);


    model->setAccounts(accounts);

    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(0);

    ui->tableViewAccounts->setModel(proxyModel);


    ui->tableViewAccounts->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableViewAccounts->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableViewAccounts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewAccounts->setAlternatingRowColors(true);
    ui->tableViewAccounts->verticalHeader()->setVisible(false);

    ui->tableViewAccounts->horizontalHeader()->setStretchLastSection(true);

    ui->tableViewAccounts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->pushButtonLogin, &QPushButton::clicked, this, [this]
            () {
                QString pin = ui->lineEditPin->text();

                if (pin == "1234") {
                    ui->labelMessage->setText("");

                    ui->stackedWidgetPages->setCurrentWidget(ui->pageAccounts);
                } else {
                    ui->labelMessage->setText("Неверный PIN-код");
                }
            });

    connect(ui->lineEditFilter, &QLineEdit::textChanged, this, [this]
            (const QString &text) {
                proxyModel->setFilterFixedString(text);
            });

    if (!errorMessage.isEmpty()) {
        ui->labelMessage->setText(errorMessage);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}