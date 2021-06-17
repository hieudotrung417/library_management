#ifndef TRANSACTIONIO_H
#define TRANSACTIONIO_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "transaction.h"

extern QVector <Transaction> transaction;

class TransactionIO
{
public:
    TransactionIO();
    int readDataFromFile(QString);
    int WriteDataToFile(QString, Transaction);
    int deleteSingleTransaction(QString, int, int);
};

#endif // TRANSACTIONIO_H
