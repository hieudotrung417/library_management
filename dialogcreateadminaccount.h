#ifndef DIALOGCREATEADMINACCOUNT_H
#define DIALOGCREATEADMINACCOUNT_H

#include <QDialog>
#include <QMessageBox>
#include "user.h"
#include "librarian.h"
extern QVector <User> listUser;
extern QString userFilePath;
namespace Ui {
class DialogCreateAdminAccount;
}

class DialogCreateAdminAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateAdminAccount(QWidget *parent = nullptr);
    ~DialogCreateAdminAccount();

signals:
    void destroyedSignal();

private slots:

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DialogCreateAdminAccount *ui;
};

#endif // DIALOGCREATEADMINACCOUNT_H
