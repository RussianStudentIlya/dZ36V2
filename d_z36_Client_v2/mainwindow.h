#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <memory>
//#include <QTcpSocket>

#include "loginform.h"
#include "registrationform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = nullptr);
    MainWindow(QTcpSocket *main_tcpSocket = nullptr, QWidget *parent = nullptr);
    ~MainWindow();

    static MainWindow* createClient(QTcpSocket *tcpSocket = nullptr);

private slots:
    void slotReadSocket();
    void disardSocket();
    void sendMessageServer(QTcpSocket *socket, QString str_msg);
    /*------------------*/
    void on_messagesLineEdit_returnPressed();
    void on_sendMessageButton_clicked();
    void on_actionCloseClient_triggered();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    QByteArray _data;
};
#endif // MAINWINDOW_H
