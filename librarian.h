#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <QString>
#include "common.h"
#include "user.h"
#include "transaction.h"
#include "userio.h"
#include "transactionio.h"
#include "bookio.h"

extern QVector <Book> library;
extern QVector <User> listUser;
extern QVector <Transaction> transaction;

class Librarian: public User
{
public:
    Librarian();
    Librarian(int, QString, QString, QString, int, QString);
    int add_user(QString userFilePath, User user);
    int add_book(QString bookFilePath, Book book);
    int delete_user(QString userFilePath, int id);
    int delete_book(QString bookFilePath, int id);
//    int update_transaction(QString transactionFilePath, Transaction transaction);
    ~Librarian();

private:
    UserIO *m_userio;
    BookIO *m_bookio;
};


#endif // LIBRARIAN_H
