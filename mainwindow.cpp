#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Lab 1 Passwird Manager");
    resize(800, 600);

    ui->labelMessage->setText("");
    ui->stackedWidgetPages->setCurrentWidget(ui->pageLogin);

    connect(ui->pushButtonLogin, &QPushButton::clicked, this, [this]() {
        QString pin = ui->lineEditPin->text();

        if (pin == "1234") {
            ui->stackedWidgetPages->setCurrentWidget(ui->pageAccounts);
        } else {
            ui->labelMessage->setText("Неверный PIN-код");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
