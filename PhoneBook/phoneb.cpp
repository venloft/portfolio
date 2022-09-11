#include "phoneb.h"

phoneB::phoneB()
{

}

QMultiMap<QString, QString> phoneB::getPhoneBook() const
{
    return phoneBook;
}

void phoneB::setPhoneBook(const QMultiMap<QString, QString> &value)
{
    phoneBook = value;
}

void phoneB::clear()
{
    phoneBook.clear();
}

bool phoneB::isUniqueName(const QString &fullname)
{
    auto result = phoneBook.find(fullname);
    if (result == phoneBook.end())
    {
        return false;
    }
    return true;
}

void phoneB::add(const QString &fullname, const QString &phone)
{
    phoneBook.insert(fullname, phone);
}

int phoneB::find(const QString &fullname)
{
    int i = 0;
    for(QMultiMap<QString, QString>::iterator it = phoneBook.begin(); it != phoneBook.end(); it++, i++)
    {
        if(it.key().contains(fullname))
        {
            return i;
        }
    }
    return -1;
}

void phoneB::del(const QString &fullname)
{
    phoneBook.remove(fullname);
}

phoneB::~phoneB()
{

}
