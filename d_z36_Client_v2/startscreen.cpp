#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QTcpSocket *main_tcpSocket, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    if(main_tcpSocket != nullptr)
    {
        this->tcpSocket = main_tcpSocket;

        //ui->LoginWidget = new LoginForm(this->tcpSocket);
        //ui->RegistrationWidget = new RegistrationForm(this->tcpSocket);
    }

    connect(ui->LoginWidget, &LoginForm::registerRequested, this, &StartScreen::setRegistrationForm);
    connect(ui->RegistrationWidget, &RegistrationForm::loginRequested, this, &StartScreen::setLoginForm);
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::setLoginForm()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void StartScreen::setRegistrationForm()
{
    ui->stackedWidget->setCurrentIndex(1);
}
