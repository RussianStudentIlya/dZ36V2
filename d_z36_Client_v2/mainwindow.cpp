#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscreen.h"

MainWindow::MainWindow(QTcpSocket *main_tcpSocket, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->tcpSocket = main_tcpSocket;
    //this->tcpSocket = new QTcpSocket();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::slotReadSocket);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::disardSocket);

    //this->tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 2323);

    if(this->tcpSocket->waitForConnected(30000))
    {
        ui->statusbar->showMessage("Client connected!");
    }else
    {
        ui->statusbar->showMessage("Client not connected: " + this->tcpSocket->errorString());
    }
}

MainWindow::~MainWindow()
{
    if(this->tcpSocket->isOpen())
        this->tcpSocket->close();
    delete ui;
}

MainWindow *MainWindow::createClient(QTcpSocket *tcpSocket)
{
    if(tcpSocket != nullptr)
    {
        //MainWindow mw(tcpSocket);
        //mw.show();

        LoginForm lF(tcpSocket);
        RegistrationForm rF(tcpSocket);

        StartScreen s(tcpSocket);
        s.show();

        auto result = s.exec();

        if(result == QDialog::Rejected)
        {
            return nullptr;
        }

        return new MainWindow(tcpSocket);
    }else
    {
        qDebug() << "Error";
    }

    return nullptr;
}

void MainWindow::slotReadSocket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());

    QDataStream in(socket); // с помощью объекта in работаем с данными находящимеся в socket
    in.setVersion(QDataStream::Qt_6_5);

    //Проверяем состояние объекта in если все в порядке продолжаем дальше
    if(in.status() == QDataStream::Ok)
    {
        QString str;
        in >> str;
        ui->privateChatBrowser->append(QString::number(socket->socketDescriptor()) + " ---> " + str);
    }else
    {
        QMessageBox::warning(this, tr("DataStream"), tr("Error"));
    }
}

void MainWindow::disardSocket()
{
    this->tcpSocket->deleteLater();
}

void MainWindow::sendMessageServer(QTcpSocket *socket, QString str_msg)
{
    this->_data.clear();
    QDataStream out(&this->_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);
    out << str_msg;
    socket->write(this->_data);
}


void MainWindow::on_messagesLineEdit_returnPressed()
{
    on_sendMessageButton_clicked();
}


void MainWindow::on_sendMessageButton_clicked()
{
    this->sendMessageServer(this->tcpSocket, ui->messagesLineEdit->text());
}


void MainWindow::on_actionCloseClient_triggered()
{
    createClient();
}

