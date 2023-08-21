/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose_this_cliend;
    QAction *actionCloseClient;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *messagesLineEdit;
    QPushButton *sendMessageButton;
    QTextBrowser *privateChatBrowser;
    QMenuBar *menubar;
    QMenu *menuMain_menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(793, 376);
        MainWindow->setMinimumSize(QSize(793, 0));
        actionClose_this_cliend = new QAction(MainWindow);
        actionClose_this_cliend->setObjectName("actionClose_this_cliend");
        actionCloseClient = new QAction(MainWindow);
        actionCloseClient->setObjectName("actionCloseClient");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        messagesLineEdit = new QLineEdit(centralwidget);
        messagesLineEdit->setObjectName("messagesLineEdit");

        horizontalLayout->addWidget(messagesLineEdit);

        sendMessageButton = new QPushButton(centralwidget);
        sendMessageButton->setObjectName("sendMessageButton");
        sendMessageButton->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(sendMessageButton);


        verticalLayout->addLayout(horizontalLayout);

        privateChatBrowser = new QTextBrowser(centralwidget);
        privateChatBrowser->setObjectName("privateChatBrowser");

        verticalLayout->addWidget(privateChatBrowser);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 793, 26));
        menuMain_menu = new QMenu(menubar);
        menuMain_menu->setObjectName("menuMain_menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMain_menu->menuAction());
        menuMain_menu->addAction(actionCloseClient);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionClose_this_cliend->setText(QCoreApplication::translate("MainWindow", "Close this cliend", nullptr));
        actionCloseClient->setText(QCoreApplication::translate("MainWindow", "Close this client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Message text: ", nullptr));
        sendMessageButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        menuMain_menu->setTitle(QCoreApplication::translate("MainWindow", "Main menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
