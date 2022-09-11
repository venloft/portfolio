#include "test.h"
#include "phoneb.h"
#include <QtTest/QTest>

test::test(QObject *parent) : QObject(parent) {}

void test::add()
{
    phoneB p;
    p.add("ivan", "+1234567890");
    QMultiMap<QString, QString> res;
    res.insert("ivan", "+1234567890");
    QCOMPARE(res, p.getPhoneBook());

    res.insert("iv", "+1234567890");
    bool check = res == p.getPhoneBook();
    QCOMPARE(false, check);
}

void test::del() {
    phoneB p;
    p.add("ivan", "+1234567890");
    p.add("ivan1", "+1234567890");
    int res = 2;
    QCOMPARE(res, p.getPhoneBook().size());
    p.del("ivan");
    res = 1;
    QCOMPARE(res, p.getPhoneBook().size());
}

void test::clear()
{
    phoneB p;
    p.add("ivan", "+1234567890");
    p.add("ivan1", "+1234567890");

    bool res = true;
    p.clear();
    QCOMPARE(res, p.getPhoneBook().isEmpty());
}

void test::isUniqueName()
{
    phoneB p;
    p.add("ivan", "+1234567890");
    p.add("ivan1", "+1234567890");

    bool res = true;
    QCOMPARE(res, p.isUniqueName("ivan"));

    res = false;
    QCOMPARE(res, p.isUniqueName("petr"));
}

void test::find()
{
    phoneB p;
    p.add("petr", "+242342323423");
    p.add("ivan1", "+1234567890");
    p.add("ivan", "+1234567890");

    int index = 2;
    QCOMPARE(index, p.find("petr"));

    index = 0;
    QCOMPARE(index, p.find("ivan"));

    index = -1;
    QCOMPARE(index, p.find("iv"));
}
