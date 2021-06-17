#include "transactionio.h"

TransactionIO::TransactionIO()
{

}

int TransactionIO::readDataFromFile(QString path)
{
    QFile file (path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "open transaction file fail\n";
        return -1;
    }
    if(file.size() <= 0)
    {
        qDebug() << "transaction file has no data\n";
        return -2;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        Transaction tmp;
        QString line = in.readLine();
        QStringList list;
        list = line.split("_");
        tmp.set_id_user(list[0].split(";")[1].toInt());
        tmp.set_id_book(list[1].split(";")[1].toInt());
        tmp.set_loanedDate(list[2].split(";")[1].split("/")[0].toInt(), list[2].split(";")[1].split("/")[1].toInt(), list[2].split(";")[1].split("/")[2].toInt());
        tmp.set_returnedDate(list[3].split(";")[1].split("/")[0].toInt(), list[3].split(";")[1].split("/")[1].toInt(), list[3].split(";")[1].split("/")[2].toInt());
        transaction.push_back(tmp);
    }
    qDebug() << "read transaction successfully\n";
    file.close();
    return 1;
}

int TransactionIO::WriteDataToFile(QString path, Transaction transaction)
{
    QFile file (path);
    if(!file.open(QIODevice::WriteOnly |QIODevice::Append))
    {
        qDebug() << "transaction file open fail\n";
        return -1;
    }
    QTextStream out(&file);
    out << "idUser;" << transaction.get_id_user() << "_idBook;" << transaction.get_id_book() << "_loanedDate;" << transaction.get_loanedDate().day << "/" << transaction.get_loanedDate().month << "/" << transaction.get_loanedDate().year << "_returnedDate;" << transaction.get_returnedDate().day << "/" << transaction.get_returnedDate().month << "/" << transaction.get_returnedDate().year << "\n";
    file.close();
    qDebug() << "write to transaction file successfully\n";
    return 1;
}

int TransactionIO::deleteSingleTransaction(QString path, int user_id, int book_id)
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
        if(!line.contains("idUser;" + QString::number(user_id) + "_idBook;" + QString::number(book_id)))
            s.append(line + "\n");
    }
    f.resize(0);
    t << s;
    f.close();
    return 1;
}
