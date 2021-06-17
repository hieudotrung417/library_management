#ifndef LIBRARY_H
#define LIBRARY_H
#include <QVector>
#include "book.h"
class Library
{
public:
    Library();

private:
    QVector <Book> allBook;
};

#endif // LIBRARY_H
