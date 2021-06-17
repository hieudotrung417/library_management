#include "dialogaddbook.h"
#include "ui_dialogaddbook.h"

DialogAddbook::DialogAddbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddbook)
{
    ui->setupUi(this);
}

DialogAddbook::~DialogAddbook()
{
    delete ui;
}


void DialogAddbook::on_pushButton_cancel_clicked()
{
    emit destroyed();
    delete this;
}


void DialogAddbook::on_pushButton_ok_clicked()
{
    int id_tmp = library[library.size()-1].get_id() + 1;
    QString name_tmp = ui->lineEdit_bookName->text();
    int price_tmp = ui->lineEdit_price->text().toInt();
    int numberOfPage_tmp = ui->lineEdit_numberPage->text().toInt();
    int m_status = ui->lineEdit_status->text().toInt();
    Date addedDate_tmp;
    addedDate_tmp.day = ui->comboBox_day->currentText().toInt();
    addedDate_tmp.month = ui->comboBox_month->currentText().toInt();
    addedDate_tmp.year = ui->comboBox_year->currentText().toInt();
    Date loanedDate_tmp;
    Date returnedDate_tmp;
    Book book_tmp(id_tmp, name_tmp,price_tmp, numberOfPage_tmp,m_status,addedDate_tmp, loanedDate_tmp, returnedDate_tmp);

    Librarian *librarian = new Librarian();
    librarian->add_book(bookFilePath, book_tmp);
    delete librarian;
    emit destroyed();
    delete this;
}

