#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QtNetwork>
#include <QMessageBox>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    //explicit LoginForm(QWidget *parent = nullptr);
    explicit LoginForm(QTcpSocket *main_tcpSocket = nullptr, QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void registerRequested();

private slots:
    void on_registrationPushButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::LoginForm *ui;

    QTcpSocket *tcpSocket;
    QByteArray _data;
};

#endif // LOGINFORM_H
