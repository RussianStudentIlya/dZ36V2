#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tcpServer = new QTcpServer(); // Инициализируем сервер

    if(this->tcpServer->listen(QHostAddress::LocalHost, 2323)) // сервер прослушивает порт 2323
    {
        connect(this->tcpServer, &QTcpServer::newConnection, this, &MainWindow::newConnection);
        ui->statusbar->showMessage("Server Start");

        /*---Подключение к БД---*/
        std::string host = "localhost";
        std::string user = "root";
        std::string password = "admin_password23";
        std::string dbName = "db_chat_dz25";

        this->dbConnect = mySQL_db(host, user, password, dbName);

        this->dbChat = Chat(this->dbConnect);
        this->dbChat.startChat();

        if(this->dbChat.get_ChatStart()) QMessageBox::information(this, tr("DB Status"), "Connect");
    }else
    {
        QMessageBox::warning(this, tr("TCP Server Error"), this->tcpServer->errorString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSocket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());

    QDataStream in(socket); // с помощью объекта in работаем с данными находящимеся в socket
    in.setVersion(QDataStream::Qt_6_5);

    //Проверяем состояние объекта in если все в порядке продолжаем дальше
    if(in.status() == QDataStream::Ok)
    {
        QString str;
        in >> str;
        //ui->textBrowser->append(QString::number(socket->socketDescriptor()) + " ---> " + str);
        //this->sendMessage(socket, str);
        this->databaseQuery(str, socket);
    }else
    {
        QMessageBox::warning(this, tr("DataStream"), tr("Error"));
    }
}

void MainWindow::discardSocket()
{
    //удалить клиента из списка при отключении клиента
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    int idx = this->listClient.indexOf(socket);

    if(idx > -1)
    {
        this->listClient.removeAt(idx);
    }

    //Обновление списка подключенных клиентво в combobox
    ui->comboBox->clear();

    for(QTcpSocket *socket_temp : this->listClient)
    {
        ui->comboBox->addItem(QString::number(socket_temp->socketDescriptor()));
    }

    socket->deleteLater();
}

void MainWindow::newConnection()
{
    // hasPendingConnections() Возвращает, true если сервер имеет ожидающее соединение; в противном случае возвращает false.
    while(this->tcpServer->hasPendingConnections())
    {
        // nextPendingConnection() Возвращает следующее ожидающее соединение как подключенный QTcpSocket объект.
        this->addToSocketList(this->tcpServer->nextPendingConnection()); // добавляем сокет нового клиент в список сокетов
    }
}

void MainWindow::addToSocketList(QTcpSocket *socket)
{
    this->listClient.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
    ui->textBrowser->append("Socket ID: " + QString::number(socket->socketDescriptor()));
    ui->comboBox->addItem(QString::number(socket->socketDescriptor()));
}

void MainWindow::sendMessage(QTcpSocket *socket, QString str_msg)
{
    this->_data.clear();
    QDataStream out(&this->_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);
    out << str_msg;

    //socket->write(this->_data);
    for(int i = 0; i < this->listClient.size(); ++i)
    {
        this->listClient[i]->write(this->_data);
    }
}

void MainWindow::databaseQuery(QString requests, QTcpSocket *socket)
{
    // 1 - вход; 2 - регистрация; 3 - Входящие и отправленные сообщения;
    // 4 - Отправить сообщение; 5 - список пользователей; 0 - выход

    int index = this->get_commandIndex(requests);

    switch (index) {
    case 1:
        //Авторизация в чат(вход)
        ui->textBrowser->append("Авторизация" + QString::number(socket->socketDescriptor()));
        break;
    case 2:
        // регистрация
        ui->textBrowser->append("регистрация " + QString::number(socket->socketDescriptor()));
        break;
    case 3:
        ui->textBrowser->append("отправленыые сообщения " + QString::number(socket->socketDescriptor()));
        break;
    case 4:
        ui->textBrowser->append("отправить " + QString::number(socket->socketDescriptor()));
        break;
    case 5:
        ui->textBrowser->append("список пользователей " + QString::number(socket->socketDescriptor()));
        break;
    case 0:
        ui->textBrowser->append("выход " + QString::number(socket->socketDescriptor()));
        break;
    default:
        break;
    }
}

int MainWindow::get_commandIndex(QString request)
{
    if(request.contains("log")) // вход
        return 1;
    if(request.contains("reg")) // регистрация
        return 2;
    if(request.contains("incom")) //получить сообщения
        return 3;
    if(request.contains("send"))//отправить сообщение
        return 4;
    if(request.contains("list"))// список пользователей
        return 5;
    if(request.contains("exit")) // выход
        return 0;
}


