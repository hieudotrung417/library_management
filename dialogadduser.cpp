#include "dialogadduser.h"
#include "ui_dialogadduser.h"

DialogAddUser::DialogAddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddUser)
{
    ui->setupUi(this);
}

DialogAddUser::~DialogAddUser()
{
    delete ui;
}

void DialogAddUser::on_pushButton_cancel_clicked()
{
    emit destroyed();
    delete this;
}


void DialogAddUser::on_pushButton_ok_clicked()
{

    int check = -1;
    for(int i = 0; i < listUser.size(); ++i)
    {
        if(ui->lineEdit_accountName->text() == listUser[i].get_accountName())
        {
            QMessageBox::information(this, "warning", "This account name is exist");
            check = i;
            break;
        }
    }
    if(check < 0)
    {
        int id_tmp = listUser[listUser.size()-1].get_id() + 1;
        QString accountName_tmp = ui->lineEdit_accountName->text();
        QString password_tmp = ui->lineEdit_password->text();
        QString name_tmp = ui->lineEdit_name->text();
        int age_tmp = ui->lineEdit_age->text().toInt();
        QString address_tmp = ui->lineEdit_address->text();
        int permission_tmp = 0;
        User user_tmp(id_tmp, accountName_tmp, password_tmp, name_tmp, age_tmp, address_tmp, permission_tmp);
        Librarian *librarian = new Librarian();
        librarian->add_user(userFilePath, user_tmp);
        delete librarian;
        QMessageBox::information(this, "information", "Thêm user thành công");
        emit destroyed();
        delete this;
    }
}

