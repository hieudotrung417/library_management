#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    horizontalHeader.append("Tên sách");
    horizontalHeader.append("Giá tiền");
    horizontalHeader.append("Số Trang");
    horizontalHeader.append("Tình trạng");
    horizontalHeader.append("Ngày thêm");
    horizontalHeader.append("Ngày mượn");
    horizontalHeader.append("Ngày trả");
    model.setHorizontalHeaderLabels(horizontalHeader);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::fillTable()
{
    verticalHeader.clear();
    model.removeRows(0,model.rowCount());
    if(ui->radioButton_all->isChecked() == true )
    {
        for(int i = 1; i <= library.size(); ++i)
        {
            verticalHeader.append(QString::number(i));
            QStandardItem *item1 = new QStandardItem(library[i-1].get_name());
            model.setItem(i-1,0,item1);


            QStandardItem *item2 = new QStandardItem(QString::number(library[i-1].get_price()));
            model.setItem(i-1,1,item2);


            QStandardItem *item3 = new QStandardItem(QString::number(library[i-1].get_numberOfPage()));
            model.setItem(i-1,2,item3);


            QStandardItem *item4 = new QStandardItem(QString::number(library[i-1].get_status()));
            model.setItem(i-1,3,item4);


            QStandardItem *item5 = new QStandardItem(QString::number(library[i-1].get_addedDate().day) + "/" + QString::number(library[i-1].get_addedDate().month) + "/" + QString::number(library[i-1].get_addedDate().year));
            model.setItem(i-1,4,item5);


            QStandardItem *item6 = new QStandardItem(QString::number(library[i-1].get_loanedDate().day) + "/" + QString::number(library[i-1].get_loanedDate().month) + "/" + QString::number(library[i-1].get_loanedDate().year));
            model.setItem(i-1,5,item6);


            QStandardItem *item7 = new QStandardItem(QString::number(library[i-1].get_returnedDate().day) + "/" + QString::number(library[i-1].get_returnedDate().month) + "/" + QString::number(library[i-1].get_returnedDate().year));
            model.setItem(i-1,6,item7);

        }
        model.index(1,1,model.index(0,0));
        model.setVerticalHeaderLabels(verticalHeader);
        ui->tableView->setModel(&model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();

    }
    else if(ui->radioButton_available->isChecked() == true)
    {
        verticalHeader.clear();
        model.removeRows(0,model.rowCount());
        QList <Book> tmp;
        for(int i = 0; i < library.size(); ++i)
        {
            if(library[i].get_status() != 0)
            {
                tmp.push_back(library[i]);
            }
        }
        for(int i = 1; i <= tmp.size(); ++i)
        {
            verticalHeader.append(QString::number(i));
            QStandardItem *item1 = new QStandardItem(tmp[i-1].get_name());
            model.setItem(i-1,0,item1);


            QStandardItem *item2 = new QStandardItem(QString::number(tmp[i-1].get_price()));
            model.setItem(i-1,1,item2);


            QStandardItem *item3 = new QStandardItem(QString::number(tmp[i-1].get_numberOfPage()));
            model.setItem(i-1,2,item3);


            QStandardItem *item4 = new QStandardItem(QString::number(tmp[i-1].get_status()));
            model.setItem(i-1,3,item4);


            QStandardItem *item5 = new QStandardItem(QString::number(tmp[i-1].get_addedDate().day) + "/" + QString::number(tmp[i-1].get_addedDate().month) + "/" + QString::number(tmp[i-1].get_addedDate().year));
            model.setItem(i-1,4,item5);


            QStandardItem *item6 = new QStandardItem(QString::number(tmp[i-1].get_loanedDate().day) + "/" + QString::number(tmp[i-1].get_loanedDate().month) + "/" + QString::number(tmp[i-1].get_loanedDate().year));
            model.setItem(i-1,5,item6);


            QStandardItem *item7 = new QStandardItem(QString::number(tmp[i-1].get_returnedDate().day) + "/" + QString::number(tmp[i-1].get_returnedDate().month) + "/" + QString::number(tmp[i-1].get_returnedDate().year));
            model.setItem(i-1,6,item7);

        }
        model.index(1,1,model.index(0,0));
        model.setHorizontalHeaderLabels(horizontalHeader);
        model.setVerticalHeaderLabels(verticalHeader);
        ui->tableView->setModel(&model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
    }

    else if(ui->radioButton_lend->isChecked())
    {
        verticalHeader.clear();
        model.removeRows(0,model.rowCount());
        QList <Book> tmp;
        for(int i = 0; i < library.size(); ++i)
        {
            if(library[i].get_status() == 0)
            {
                tmp.push_back(library[i]);
            }
        }
        for(int i = 1; i <= tmp.size(); ++i)
        {
            verticalHeader.append(QString::number(i));
            QStandardItem *item1 = new QStandardItem(tmp[i-1].get_name());
            model.setItem(i-1,0,item1);


            QStandardItem *item2 = new QStandardItem(QString::number(tmp[i-1].get_price()));
            model.setItem(i-1,1,item2);


            QStandardItem *item3 = new QStandardItem(QString::number(tmp[i-1].get_numberOfPage()));
            model.setItem(i-1,2,item3);


            QStandardItem *item4 = new QStandardItem(QString::number(tmp[i-1].get_status()));
            model.setItem(i-1,3,item4);


            QStandardItem *item5 = new QStandardItem(QString::number(tmp[i-1].get_addedDate().day) + "/" + QString::number(tmp[i-1].get_addedDate().month) + "/" + QString::number(tmp[i-1].get_addedDate().year));
            model.setItem(i-1,4,item5);


            QStandardItem *item6 = new QStandardItem(QString::number(tmp[i-1].get_loanedDate().day) + "/" + QString::number(tmp[i-1].get_loanedDate().month) + "/" + QString::number(tmp[i-1].get_loanedDate().year));
            model.setItem(i-1,5,item6);


            QStandardItem *item7 = new QStandardItem(QString::number(tmp[i-1].get_returnedDate().day) + "/" + QString::number(tmp[i-1].get_returnedDate().month) + "/" + QString::number(tmp[i-1].get_returnedDate().year));
            model.setItem(i-1,6,item7);

        }
        model.index(1,1,model.index(0,0));
        model.setHorizontalHeaderLabels(horizontalHeader);
        model.setVerticalHeaderLabels(verticalHeader);
        ui->tableView->setModel(&model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
    }
    else
    {
        QMessageBox::information(this,"Warning", "check only one check box plzzzzz");
    }
}

void MainWindow::ObjectDestroyed()
{
    this->setEnabled(true);
}

void MainWindow::on_pushButton_addUser_clicked()
{
    this->setEnabled(false);
    adduser = new DialogAddUser();
    adduser->show();
    connect(adduser, SIGNAL(destroyed()), this, SLOT(ObjectDestroyed()));
}


void MainWindow::on_pushButton_addBook_clicked()
{
    this->setEnabled(false);
    addbook = new DialogAddbook();
    addbook->show();
    connect(addbook, SIGNAL(destroyed()), this, SLOT(ObjectDestroyed()));
}


void MainWindow::on_pushButton_clicked()
{
    mainwindow->fillTable();
}



