#include "dialoglogin.h"
#include <QApplication>
#include "book.h"
#include "transaction.h"
#include "bookio.h"
#include "transactionio.h"
#include "userio.h"
#include "librarian.h"

QString userFilePath = "E:/Documents/library_project/user.txt";
QString bookFilePath = "E:/Documents/library_project/book.txt";
QString transactionFilePath = "E:/Documents/library_project/transaction.txt";
QVector <Book> library;
QVector <User> listUser;
QVector <Transaction> transaction;
MainWindow *mainwindow;
int main(int argc, char *argv[])
{
    UserIO *userio = new UserIO();
    userio->readDataFromFile(userFilePath);
    delete userio;

    BookIO * bookio = new BookIO();
    bookio->readDataFromFile(bookFilePath);
    delete bookio;

    TransactionIO *transactionio = new TransactionIO();
    transactionio->readDataFromFile(transactionFilePath);
    delete transactionio;


    QApplication a(argc, argv);

    DialogLogin *dialoglogin = new DialogLogin();
    dialoglogin->show();


    return a.exec();
}
