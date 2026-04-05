/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidgetPages;
    QWidget *pageAccounts;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditFilter;
    QTableView *tableViewAccounts;
    QWidget *pageLogin;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelHint;
    QLabel *labelTitle;
    QLineEdit *lineEditPin;
    QPushButton *pushButtonLogin;
    QLabel *labelMessage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(562, 292);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidgetPages = new QStackedWidget(centralwidget);
        stackedWidgetPages->setObjectName("stackedWidgetPages");
        pageAccounts = new QWidget();
        pageAccounts->setObjectName("pageAccounts");
        gridLayout_2 = new QGridLayout(pageAccounts);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEditFilter = new QLineEdit(pageAccounts);
        lineEditFilter->setObjectName("lineEditFilter");

        verticalLayout_3->addWidget(lineEditFilter);

        tableViewAccounts = new QTableView(pageAccounts);
        tableViewAccounts->setObjectName("tableViewAccounts");

        verticalLayout_3->addWidget(tableViewAccounts);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidgetPages->addWidget(pageAccounts);
        pageLogin = new QWidget();
        pageLogin->setObjectName("pageLogin");
        gridLayout_3 = new QGridLayout(pageLogin);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelHint = new QLabel(pageLogin);
        labelHint->setObjectName("labelHint");
        labelHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelHint);

        labelTitle = new QLabel(pageLogin);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelTitle);

        lineEditPin = new QLineEdit(pageLogin);
        lineEditPin->setObjectName("lineEditPin");
        lineEditPin->setEchoMode(QLineEdit::EchoMode::Password);
        lineEditPin->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(lineEditPin);

        pushButtonLogin = new QPushButton(pageLogin);
        pushButtonLogin->setObjectName("pushButtonLogin");

        verticalLayout_2->addWidget(pushButtonLogin);

        labelMessage = new QLabel(pageLogin);
        labelMessage->setObjectName("labelMessage");
        labelMessage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelMessage);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidgetPages->addWidget(pageLogin);

        gridLayout->addWidget(stackedWidgetPages, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditFilter->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\320\276 URL \321\201\320\260\320\271\321\202\320\260", nullptr));
        labelHint->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \321\203\321\207\320\265\321\202\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 PIN-\320\272\320\276\320\264 \320\264\320\273\321\217 \321\200\320\260\320\267\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\270 \321\205\321\200\320\260\320\275\320\270\320\273\320\270\321\211\320\260", nullptr));
        lineEditPin->setPlaceholderText(QCoreApplication::translate("MainWindow", "PIN-\320\272\320\276\320\264", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        labelMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
