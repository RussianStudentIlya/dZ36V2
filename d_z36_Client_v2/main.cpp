#include "mainwindow.h"
#include "loginform.h"
#include "registrationform.h"
#include "startscreen.h"
#include <QtNetwork>
//#include "startscreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //StartScreen s;
    //s.show();
    //MainWindow w;
    //w.show();

    QTcpSocket *main_tcpSocket = new QTcpSocket();
    main_tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 2323);

    //MainWindow mw(main_tcpSocket);
    //mw.show();

    auto win = MainWindow::createClient(main_tcpSocket);
    win->show();


    //StartScreen start(main_tcpSocket);
    //start.show();

    return a.exec();
}
