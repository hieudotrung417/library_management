#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "user.h"
#include "mainwindowclient.h"
#include "dialogcreateadminaccount.h"

extern QVector <User> listUser;
extern MainWindow *mainwindow;
namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void recieveDestroyedSignal();

    void on_pushButton_clicked();

    void on_pushButton_createAccount_clicked();

private:
    Ui::DialogLogin *ui;
    MainWindowClient *mainwindowclient;
    DialogCreateAdminAccount *dialogCreateAdminAccount;
};

#endif // DIALOGLOGIN_H
