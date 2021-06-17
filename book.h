#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include "common.h"

class Book
{
public:
    Book();
    Book(int, QString, int, int, int, Date, Date, Date);
    void set_id(int);
    void set_name(QString);
    void set_price(int);
    void set_numberOfPage(int);
    void set_status(int);
    void set_addedDate(int, int, int);
    void set_loanedDate(int, int, int);
    void set_returnedDate(int, int, int);

    int get_id();
    QString get_name();
    int get_price();
    int get_numberOfPage();
    int get_status();
    Date get_addedDate();
    Date get_loanedDate();
    Date get_returnedDate();
private:
    int m_id;
    QString m_name;
    int m_price;
    int m_numberOfPage;
    int m_status;  // 1 = available    0 = unavailable

    Date m_addedDate;
    Date m_loanedDate;
    Date m_returnedDate;

};

#endif // BOOK_H
