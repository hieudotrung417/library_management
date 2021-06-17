#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include <QMessageBox>
DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::recieveDestroyedSignal()
{
    this->setEnabled(true);
}

void DialogLogin::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    int check = -1;
    for(int i = 0; i < listUser.size(); ++i)
    {
        if(username == listUser[i].get_accountName() && password == listUser[i].get_password() && listUser[i].get_permission() != 0)
            check = 1;
        if(username == listUser[i].get_accountName() && password == listUser[i].get_password() && listUser[i].get_permission() == 0)
            check = 2;
    }
    if(check == -1)
    {
        QMessageBox::information(this, "warning", "incorrect username or password");
    }
    else if(check == 1)
    {
        QMessageBox::information(this, "Information", "login as admin");
        hide();
        mainwindow = new MainWindow(this);
        mainwindow->show();
    }
    else if(check == 2)
    {
        QMessageBox::information(this, "Information", "login as client");
        hide();
        mainwindowclient = new MainWindowClient(this);
        mainwindowclient->show();
    }
}


void DialogLogin::on_pushButton_createAccount_clicked()
{
    this->setEnabled(false);
    dialogCreateAdminAccount = new DialogCreateAdminAccount();
    dialogCreateAdminAccount->show();
    connect(dialogCreateAdminAccount, SIGNAL(destroyedSignal()), this, SLOT(recieveDestroyedSignal()));
}

