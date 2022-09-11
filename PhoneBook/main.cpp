#include "phonebook.h"
#include <QApplication>
#include "test.h"
#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new test, argc, argv);
    PhoneBook w;
    w.show();

    return a.exec();
}
