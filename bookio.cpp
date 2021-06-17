#include "bookio.h"

BookIO::BookIO()
{

}

int BookIO::readDataFromFile(QString path)
{
    QFile file (path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "book file open fail\n";
        return -1;
    }

    if(file.size() <= 0)
    {
        qDebug() << "book file has no data\n";
        return -2;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        Book tmp;
        QString line = in.readLine();
        QStringList list;
        list = line.split("_");
        tmp.set_id(list[0].split(";")[1].toInt());
        tmp.set_name(list[1].split(";")[1]);
        tmp.set_price(list[2].split(";")[1].toInt());
        tmp.set_numberOfPage(list[3].split(";")[1].toInt());
        tmp.set_status(list[4].split(";")[1].toInt());
        tmp.set_addedDate(list[5].split(";")[1].split("/")[0].toInt(), list[5].split(";")[1].split("/")[1].toInt(), list[5].split(";")[1].split("/")[2].toInt());
        tmp.set_loanedDate(list[6].split(";")[1].split("/")[0].toInt(), list[6].split(";")[1].split("/")[1].toInt(), list[6].split(";")[1].split("/")[2].toInt());
        tmp.set_returnedDate(list[7].split(";")[1].split("/")[0].toInt(), list[7].split(";")[1].split("/")[1].toInt(), list[7].split(";")[1].split("/")[2].toInt());
        library.push_back(tmp);
    }
    file.close();
    qDebug() << "read book file successfully\n";
    return 1;
}


int BookIO::WriteDataToFile(QString path, Book book)
{
    QFile file (path);
    if(!file.open(QIODevice::WriteOnly |QIODevice::Append))
    {
        qDebug() << "book file open fail\n";
        return -1;
    }
    QTextStream out(&file);
    out << "id;" << book.get_id() << "_name;" << book.get_name() << "_price;" << book.get_price() << "_numberPage;" << book.get_numberOfPage() << "_status;" << book.get_status() << "_addedDate;" << book.get_addedDate().day << "/" << book.get_addedDate().month << "/" << book.get_addedDate().year << "_loanedDate;" << book.get_loanedDate().day << "/" << book.get_loanedDate().month << "/" << book.get_loanedDate().year << "_returnedDate;" << book.get_returnedDate().day << "/" << book.get_returnedDate().month << "/" << book.get_returnedDate().year << "\n";
    file.close();
    qDebug() << "write to book file successfully\n";
    return 1;
}

int BookIO::deleteSingleBook(QString path, int book_id)
{
    QFile f(path);
    if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "open book file failed\n";
        return -1;
    }
    QString s;
    QTextStream t(&f);
    while(!t.atEnd())
    {
        QString line = t.readLine();
        if(!line.contains("id;" + QString::number(book_id)))
            s.append(line + "\n");
    }
    f.resize(0);
    t << s;
    f.close();
    return 1;
}
