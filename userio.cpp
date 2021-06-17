#include "userio.h"

UserIO::UserIO()
{

}

int UserIO::readDataFromFile(QString path)
{
    QFile file (path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "user file open fail\n";
        return -1;
    }
    if(file.size() <= 0)
    {
        qDebug() << "User file have no data\n";
        return -2;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        User tmp;
        QString line = in.readLine();
        QStringList list;
        list = line.split("_");
        tmp.set_id(list[0].split(";")[1].toInt());
        tmp.set_accountName(list[1].split(";")[1]);
        tmp.set_password(list[2].split(";")[1]);
        tmp.set_name(list[3].split(";")[1]);
        tmp.set_age(list[4].split(";")[1].toInt());
        tmp.set_address(list[5].split(";")[1]);
        tmp.set_permission(list[6].split(";")[1].toInt());
        listUser.push_back(tmp);
    }
    qDebug() << "read user file successfully\n";
    file.close();
    return 1;

}


int UserIO::WriteDataToFile(QString path, User user)
{
    QFile file (path);
    if(!file.open(QIODevice::WriteOnly |QIODevice::Append))
    {
        qDebug() << "user file open fail\n";
        return -1;
    }
    QTextStream out(&file);
    out << "id;" << user.get_id() << "_accountName;" << user.get_accountName() << "_password;" << user.get_password() << "_name;" << user.get_name() << "_age;" << user.get_age() << "_address;" << user.get_address() << "_permission;" << user.get_permission() << "\n";
    file.close();
    qDebug() << "write to user file successfully\n";
    return 1;
}

int UserIO::deleteSingleUser(QString path, int user_id)
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
        if(!line.contains("idUser;" + user_id))
            s.append(line + "\n");
    }
    f.resize(0);
    t << s;
    f.close();
    return 1;
}
