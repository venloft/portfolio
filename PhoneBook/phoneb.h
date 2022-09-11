#ifndef PHONEB_H
#define PHONEB_H
#include <QMultiMap>
#include <QString>

class phoneB
{
    QMultiMap <QString, QString> phoneBook;
public:
    phoneB();
    void add(const QString &fullname, const QString &phone);
    int find(const QString &fullname);
    void del(const QString &fullname);
    bool isUniqueName(const QString &fullname);
    void clear();
    ~phoneB();
    QMultiMap<QString, QString> getPhoneBook() const;
    void setPhoneBook(const QMultiMap<QString, QString> &value);
};

#endif // PHONEB_H
