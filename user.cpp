#include "user.h"

User::User()
{
    m_id = 123;
    m_accountName = "admin";
    m_password = "123456";
    m_name = "noname";
    m_age = 0;
    m_address = "null";
    m_permission = 0;
}

User::User(int id, QString accountName, QString password, QString name, int age, QString address, int permission):
    m_id(id), m_accountName(accountName), m_password(password), m_name(name), m_age(age), m_address(address), m_permission(permission)
{

}

void User::set_id(int id)
{
    m_id = id;
}
void User::set_accountName(QString accountName)
{
    m_accountName = accountName;
}

void User::set_password(QString password)
{
    m_password = password;
}
void User::set_name(QString name)
{
    m_name = name;
}
void User::set_age(int age)
{
    m_age = age;
}
void User::set_address(QString address)
{
    m_address = address;
}
void User::set_permission(int permission)
{
    m_permission = permission;
}

int User::get_id()
{
    return m_id;
}
QString User::get_accountName()
{
    return m_accountName;
}
QString User::get_password()
{
    return m_password;
}
QString User::get_name()
{
    return m_name;
}
int User::get_age()
{
    return m_age;
}
QString User::get_address()
{
    return m_address;
}
int User::get_permission()
{
    return m_permission;
}
