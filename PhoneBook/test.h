#ifndef TEST_H
#define TEST_H
#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = 0);

private slots:
    void add();
    void del();
    void clear();
    void isUniqueName();
    void find();
};

#endif // TEST_H
