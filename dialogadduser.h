#ifndef DIALOGADDUSER_H
#define DIALOGADDUSER_H

#include <QDialog>
#include <QMessageBox>
#include <user.h>
#include "librarian.h"
extern QVector <User> listUser;;
extern QString userFilePath;
extern QString bookFilePath;
extern QString transactionFilePath;

namespace Ui {
class DialogAddUser;
}

class DialogAddUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddUser(QWidget *parent = nullptr);
    ~DialogAddUser();

signals:
    void destroyed();
private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::DialogAddUser *ui;
};

#endif // DIALOGADDUSER_H
