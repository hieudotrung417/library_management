#include "book.h"

Book::Book()
{
    m_id = 123;
    m_name = "null";
    m_price = 0;
    m_numberOfPage = 0;
    m_status = 0;
}


Book::Book(int id, QString name, int price, int numberPage, int status, Date addedDate, Date loanedDate, Date returnedDate):
    m_id(id), m_name(name), m_price(price), m_numberOfPage(numberPage), m_status(status), m_addedDate(addedDate), m_loanedDate(loanedDate), m_returnedDate(returnedDate)
{

}


void Book::set_id(int id)
{
    m_id = id;
}
void Book::set_name(QString name)
{
    m_name = name;
}
void Book::set_price(int price)
{
    m_price = price;
}
void Book::set_numberOfPage(int numberOfPage)
{
    m_numberOfPage = numberOfPage;
}

void Book::set_status(int status)
{
    m_status = status;
}
void Book::set_addedDate(int day, int month, int year)
{
    m_addedDate.day = day;
    m_addedDate.month = month;
    m_addedDate.year = year;
}
void Book::set_loanedDate(int day, int month, int year)
{
    m_loanedDate.day = day;
    m_loanedDate.month = month;
    m_loanedDate.year = year;
}
void Book::set_returnedDate(int day, int month, int year)
{
    m_returnedDate.day = day;
    m_returnedDate.month = month;
    m_returnedDate.year = year;
}


int Book::get_id()
{
    return m_id;
}
QString Book::get_name()
{
    return m_name;
}
int Book::get_price()
{
    return m_price;
}
int Book::get_numberOfPage()
{
    return m_numberOfPage;
}

int Book::get_status( )
{
    return m_status;
}
Date Book::get_addedDate()
{
    return m_addedDate;
}
Date Book::get_loanedDate()
{
    return m_loanedDate;
}
Date Book::get_returnedDate()
{
    return m_returnedDate;
}
