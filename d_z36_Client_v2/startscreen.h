#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    //explicit StartScreen(QWidget *parent = nullptr);
    explicit StartScreen(QTcpSocket *main_tcpSocket = nullptr, QWidget *parent = nullptr);
    ~StartScreen();

    void setLoginForm();
    void setRegistrationForm();

private:
    Ui::StartScreen *ui;
    QTcpSocket *tcpSocket;
    QByteArray _data;
};

#endif // STARTSCREEN_H
