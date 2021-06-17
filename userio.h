#ifndef USERIO_H
#define USERIO_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "user.h"


extern QVector <User> listUser;

class UserIO
{
public:
    UserIO();
    int readDataFromFile(QString );
    int WriteDataToFile(QString , User);
    int deleteSingleUser(QString , int);
};

#endif // USERIO_H
