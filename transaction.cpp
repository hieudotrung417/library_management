#include "transaction.h"

Transaction::Transaction()
{

}

Transaction::Transaction(int id_user, int id_book, Date loanedDate, Date returnedDate):
    m_id_user(id_user), m_id_book(id_book), m_loanedDate(loanedDate), m_returnedDate(returnedDate)
{
}
void Transaction::set_id_user(int id_user)
{
    m_id_user = id_user;
}
void Transaction::set_id_book(int id_book)
{
    m_id_book = id_book;
}
void Transaction::set_loanedDate(int day, int month, int year)
{
    m_loanedDate.day = day;
    m_loanedDate.month = month;
    m_loanedDate.year = year;
}
void Transaction::set_returnedDate(int day, int month,int year)
{
    m_returnedDate.day = day;
    m_returnedDate.month = month;
    m_returnedDate.year = year;
}


int Transaction::get_id_user()
{
    return m_id_user;
}
int Transaction::get_id_book()
{
    return m_id_book;
}
Date Transaction::get_loanedDate()
{
    return m_loanedDate;
}
Date Transaction::get_returnedDate()
{
    return m_returnedDate;
}
