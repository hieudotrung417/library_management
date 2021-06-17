#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogaddbook.h"
#include "dialogadduser.h"


#include <QStandardItemModel>
#include <QHeaderView>

class MainWindow;
extern MainWindow *mainwindow;
extern QVector <Book> library;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void fillTable();
private slots:

    void ObjectDestroyed();

    void on_pushButton_addUser_clicked();
    void on_pushButton_addBook_clicked();


    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    DialogAddUser *adduser;
    DialogAddbook *addbook;


    QStandardItemModel model;
    QModelIndex modelIndex;

    QStringList horizontalHeader;
    QStringList verticalHeader;
};
#endif // MAINWINDOW_H
