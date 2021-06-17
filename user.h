#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include <QDebug>
#include "book.h"


class User
{
public:
    User();
    User(int, QString, QString, QString, int, QString, int);
    void set_id(int);
    void set_accountName(QString);
    void set_password(QString);
    void set_name(QString);
    void set_age(int);
    void set_address(QString);
    void set_permission(int); // 1 = librarian   0 = client

    int get_id();
    QString get_accountName();
    QString get_password();
    QString get_name();
    int get_age();
    QString get_address();
    int get_permission();

private:
    int m_id;
    QString m_accountName;
    QString m_password;
    QString m_name;
    int m_age;
    QString m_address;
    int m_permission;
    QVector <QString> m_listLoanedBook;
};

#endif // USER_H
