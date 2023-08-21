#include "registrationform.h"
#include "ui_registrationform.h"

RegistrationForm::RegistrationForm(QTcpSocket *main_tcpSocketm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
    if(main_tcpSocketm != nullptr)
        this->tcpSocket = main_tcpSocketm;
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::on_LoginButton_clicked()
{
    emit loginRequested();
}


void RegistrationForm::on_buttonBox_accepted()
{

}


void RegistrationForm::on_buttonBox_rejected()
{

}

