/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include "loginform.h"
#include "registrationform.h"

QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    LoginForm *LoginWidget;
    RegistrationForm *RegistrationWidget;

    void setupUi(QDialog *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName("StartScreen");
        StartScreen->resize(560, 381);
        verticalLayout = new QVBoxLayout(StartScreen);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(StartScreen);
        stackedWidget->setObjectName("stackedWidget");
        LoginWidget = new LoginForm();
        LoginWidget->setObjectName("LoginWidget");
        stackedWidget->addWidget(LoginWidget);
        RegistrationWidget = new RegistrationForm();
        RegistrationWidget->setObjectName("RegistrationWidget");
        stackedWidget->addWidget(RegistrationWidget);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(StartScreen);

        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QDialog *StartScreen)
    {
        StartScreen->setWindowTitle(QCoreApplication::translate("StartScreen", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
