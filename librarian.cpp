#include "librarian.h"

Librarian::Librarian()
{
    set_permission(1);
    m_userio = new UserIO();
    m_bookio = new BookIO();
}

Librarian::Librarian(int id, QString accountName, QString password, QString name, int age, QString address)
{
   set_id(id);
   set_accountName(accountName);
   set_password(password);
   set_name(name);
   set_age(age);
   set_address(address);
   set_permission(1);
   m_userio = new UserIO();
   m_bookio = new BookIO();
}

Librarian::~Librarian()
{
    delete m_userio;
    delete m_bookio;
}
int Librarian::add_user(QString userFilePath, User user)
{
   if(this->get_permission() == 0)
   {
       qDebug() << "No permission to add_user\n";
       return -1;
   }
   listUser.push_back(user); //add user to global user list
   m_userio->WriteDataToFile(userFilePath, user); //add user to user list file
   return 1;
}
int Librarian::add_book(QString bookFilePath, Book book)
{
    if(this->get_permission() == 0)
    {
        qDebug() << "No permission to add_book\n";
        return -1;
    }
    library.push_back(book);//add book to global library

    m_bookio->WriteDataToFile(bookFilePath, book); // add book to library file
    return 1;
}
int Librarian::delete_user(QString userFilePath, int id)
{
    if(this->get_permission() == 0)
    {
        qDebug() << "no permission to delete user\n";
        return -1;
    }
    for(int i = 0; i < listUser.size();i++)
    {
        if(listUser[i].get_id() == id)
        {
            listUser.erase(listUser.begin() + i); // delete user from userlist global
        }
    }
    m_userio->deleteSingleUser(userFilePath, id);// delete user from user file
    return 1;
}
int Librarian::delete_book(QString bookFilePath, int id)
{
    if(this->get_permission() == 0)
    {
        qDebug() << "no permission to delete book\n";
        return 1;
    }
    for(int i = 0; i < library.size(); ++i)
    {
        if(library[i].get_id() == id)
        {
            library.erase(library.begin() + i); // delete book from library global
        }
    }
    m_bookio->deleteSingleBook(bookFilePath, id);
    return 1;
}
//int Librarian::add_transaction(QString transactionFilePath, Transaction transaction)
//{
//    if(this->get_permission() == 0)
//    {
//        qDebug() << "no permission to update list loaned book\n";
//        return -1;
//    }

//}
