#ifndef BOOKIO_H
#define BOOKIO_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "book.h"

extern QVector <Book> library;
class BookIO
{
public:
    BookIO();
    int readDataFromFile(QString path);
    int WriteDataToFile(QString path, Book book);
    int deleteSingleBook(QString path, int book_id);
};

#endif // BOOKIO_H
