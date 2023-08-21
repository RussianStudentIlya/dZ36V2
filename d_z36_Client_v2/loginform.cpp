#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QTcpSocket *main_tcpSocket, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    if(main_tcpSocket != nullptr)
    {
        this->tcpSocket = main_tcpSocket;

        if(this->tcpSocket->waitForConnected(30000))
        {
            //ui->statusbar->showMessage("Client connected!");
            QMessageBox::information(this, "LoginForm", "Connect");
            ui->status_connect_Label->setText("Connect");
        }else
        {
            //ui->statusbar->showMessage("Client not connected: " + this->tcpSocket->errorString());
            ui->status_connect_Label->setText("Client not connected: " + this->tcpSocket->errorString());
        }
    }
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_registrationPushButton_clicked()
{
    emit registerRequested();
}


void LoginForm::on_buttonBox_accepted()
{

}


void LoginForm::on_buttonBox_rejected()
{
}

