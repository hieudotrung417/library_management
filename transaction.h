#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include "common.h"
class Transaction
{
public:
    Transaction();
    Transaction(int, int, Date, Date);
    void set_id_user(int);
    void set_id_book(int);
    void set_loanedDate(int, int, int);
    void set_returnedDate(int, int,int);

    int get_id_user();
    int get_id_book();
    Date get_loanedDate();
    Date get_returnedDate();
private:
    int m_id_user;
    int m_id_book;
    Date m_loanedDate;
    Date m_returnedDate;
};

#endif // TRANSACTION_H
