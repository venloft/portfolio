#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QListWidgetItem>
#include "phoneb.h"

namespace Ui
{
    class PhoneBook;
}

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhoneBook(QWidget *parent = 0);
    ~PhoneBook();

    bool isUserInputValid(const QString &fullname, const QString &phoneNumber);
    void open(const QString &filename);
    void save(const QString &filename);
    void clearInputFields();
    void deleteItem();

private slots:
    void on_btnAdd_clicked();
    void on_btnOpen_clicked();
    void on_btnSave_clicked();
    void on_btnFind_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnClear_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::PhoneBook *ui;
    phoneB *pbObj = NULL;
    QString filename;
};

#endif // PHONEBOOK_H
