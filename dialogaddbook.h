#ifndef DIALOGADDBOOK_H
#define DIALOGADDBOOK_H

#include <QDialog>
#include "book.h"
#include "common.h"
#include "librarian.h"
extern QVector <Book> library;
extern QString bookFilePath;
namespace Ui {
class DialogAddbook;
}

class DialogAddbook : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddbook(QWidget *parent = nullptr);
    ~DialogAddbook();

signals:
    void destroyed();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::DialogAddbook *ui;
};

#endif // DIALOGADDBOOK_H
