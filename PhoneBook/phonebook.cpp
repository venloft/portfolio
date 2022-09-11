#include "phonebook.h"
#include "ui_phonebook.h"

PhoneBook::PhoneBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhoneBook)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->lEditPhoneNumber->setValidator(new QRegExpValidator(QRegExp("\\+?[0-9]+"), this));
    ui->lEditFullname->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+"), this));
    pbObj = new phoneB;
}

PhoneBook::~PhoneBook()
{
    delete ui;
    delete pbObj;
    pbObj = NULL;
}

bool PhoneBook::isUserInputValid(const QString &fullname, const QString &phoneNumber)
{
    if (fullname.isEmpty() || phoneNumber.isEmpty())
    {
        ui->lblError->setText("You need to fill in both fields!");
        return false;
    }
    ui->lblError->setText("");
    return true;
}

void PhoneBook::clearInputFields()
{
    ui->lEditFullname->clear();
    ui->lEditPhoneNumber->clear();
}

void PhoneBook::on_btnAdd_clicked()
{
    QString fullname = ui->lEditFullname->text();
    QString phone = ui->lEditPhoneNumber->text();
    if (pbObj->isUniqueName(fullname))
    {
        ui->lblError->setText("Fullname must be unique!");
        return;
    }
    else
    {
        ui->lblError->setText("");
    }

    if (isUserInputValid(fullname, phone))
    {
        pbObj->add(fullname, phone);
        ui->listWidget->addItem(fullname + "\t" + phone);
        ui->listWidget->sortItems();
        clearInputFields();
    }
}

void PhoneBook::open(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        pbObj->clear();
        ui->listWidget->clear();

        QTextStream in(&file);
        QStringList lines = in.readAll().split("\n");
        for(int i = 0, length = lines.length(); i < length; i++)
        {
            if(!lines[i].isEmpty())
            {
                QStringList list = lines[i].split(" ; ");
                pbObj->add(list[0], list[1]);
                ui->listWidget->addItem(list[0] + "\t" + list[1]);
            }
        }
        ui->lblError->setText("");
        file.close();
    }
    else
    {
        ui->lblError->setText("Error opening file");
    }
}

void PhoneBook::on_btnOpen_clicked()
{
    filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
    open(filename);
}

void PhoneBook::save(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        QMultiMap<QString, QString> phoneBoox = pbObj->getPhoneBook();
        for(QMultiMap<QString, QString>::iterator it = phoneBoox.begin(); it != phoneBoox.end(); it++)
        {
            out << it.key() << " ; " << it.value() << "\n";
        }
        ui->lblError->setText("");
        file.close();
    }
    else
    {
        ui->lblError->setText("Error writing to file");
    }
}

void PhoneBook::on_btnSave_clicked()
{
    filename = QFileDialog::getSaveFileName(0, "Save File", "", "*.txt");
    save(filename);
}

void PhoneBook::on_btnFind_clicked()
{
    int index = pbObj->find(ui->lEditFullname->text());
    if (index == -1)
    {
        ui->lblError->setText("Cannot find the name");
    }
    else
    {
        ui->listWidget->setCurrentRow(index);
    }
}

void PhoneBook::on_btnEdit_clicked()
{
    QString fullname = ui->lEditFullname->text();
    QString phone = ui->lEditPhoneNumber->text();

    if (pbObj->isUniqueName(fullname))
    {
        ui->lblError->setText("Fullname must be unique!");
        ui->lEditFullname->setFocus();
        return;
    }

    if (isUserInputValid(fullname, phone))
    {
        deleteItem();
        pbObj->add(fullname, phone);
        ui->listWidget->addItem(fullname + "\t" + phone);
        ui->listWidget->sortItems();
    }
}

void PhoneBook::deleteItem()
{
    QList<QListWidgetItem *> selectedItems = ui->listWidget->selectedItems();
    for (int i = 0; i < selectedItems.size(); ++i)
    {
        QStringList fields = selectedItems[i]->text().split('\t');
        QString name = fields[0];
        pbObj->del(name);
        ui->listWidget->removeItemWidget(selectedItems[i]);
        delete selectedItems[i];
    }
    clearInputFields();
}

void PhoneBook::on_btnDelete_clicked()
{
    deleteItem();
}

void PhoneBook::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int position = item->text().toStdString().find("\t");

    std::string name = item->text().toStdString().erase(position, item->text().toStdString().length());
    std::string phoneNumber = item->text().toStdString().erase(0, position + 1);

    ui->lEditFullname->setText(QString::fromStdString(name));
    ui->lEditPhoneNumber->setText(QString::fromStdString(phoneNumber));
}

void PhoneBook::on_btnClear_clicked()
{
    ui->listWidget->clear();
    pbObj->clear();
    clearInputFields();
}
