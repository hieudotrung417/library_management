#include "dialogcreateadminaccount.h"
#include "ui_dialogcreateadminaccount.h"

DialogCreateAdminAccount::DialogCreateAdminAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateAdminAccount)
{
    ui->setupUi(this);
}

DialogCreateAdminAccount::~DialogCreateAdminAccount()
{
    delete ui;
}

void DialogCreateAdminAccount::on_pushButton_ok_clicked()
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
        User *admin = new Librarian(id_tmp, accountName_tmp, password_tmp, name_tmp, age_tmp, address_tmp);
        Librarian *librarian = new Librarian();
        librarian->add_user(userFilePath, *admin);
        delete librarian;
        delete admin;
        QMessageBox::information(this, "information", "Thêm user thành công");
        emit destroyedSignal();
        delete this;
    }
}


void DialogCreateAdminAccount::on_pushButton_cancel_clicked()
{
    emit destroyedSignal();
    delete this;
}

