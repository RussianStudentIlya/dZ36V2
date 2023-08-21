#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QString>
#include <QList>
//#include <QtGui>
//#include <QtCore>
#include <QtWidgets>

#include "myClassChat/Chat.h"
#include "myClassChat/mySQL_db.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSocket();
    void discardSocket();

    void newConnection();

    void addToSocketList(QTcpSocket *socket);
    void sendMessage(QTcpSocket* socket, QString str_msg);

private:
    Ui::MainWindow *ui;

    QTcpServer *tcpServer;
    QList<QTcpSocket*> listClient;

    QByteArray _data; // для передачи данных между клиентом и сервером

    mySQL_db dbConnect;
    Chat dbChat;



    void databaseQuery(QString requests, QTcpSocket *socket); // метод для отправления запросов в бд
    int get_commandIndex(QString request);
};
#endif // MAINWINDOW_H
