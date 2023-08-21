#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QtNetwork>
#include <memory>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    //explicit RegistrationForm(QWidget *parent = nullptr);
    explicit RegistrationForm(QTcpSocket *main_tcpSocket = nullptr, QWidget *parent = nullptr);
    ~RegistrationForm();

signals:
    void loginRequested();

private slots:
    void on_LoginButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::RegistrationForm *ui;

    QTcpSocket *tcpSocket;
    QByteArray _data;
};

#endif // REGISTRATIONFORM_H
