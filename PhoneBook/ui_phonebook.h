/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneBook
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameTop;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QLabel *lblTitle;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblFullName;
    QLineEdit *lEditFullname;
    QLineEdit *lEditPhoneNumber;
    QLabel *lblPhoneNumber;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnAdd;
    QPushButton *btnFind;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblTitleLab1;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblHeader;
    QListWidget *listWidget;
    QLabel *lblError;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnClear;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnDelete;
    QPushButton *btnEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *PhoneBook)
    {
        if (PhoneBook->objectName().isEmpty())
            PhoneBook->setObjectName(QStringLiteral("PhoneBook"));
        PhoneBook->resize(800, 900);
        PhoneBook->setStyleSheet(QLatin1String("QScrollBar:vertical { \n"
"	background: white; \n"
"	width: 8px; \n"
"	border: 1px solid transparent;\n"
"	border-radius: 4px; \n"
"}\n"
"QScrollBar:handle:vertical { \n"
"	background: qlineargradient(spread:pad, x1:0.463, y1:1, x2:0.453353, y2:0, stop:0 rgba(103, 102, 103, 255), stop:1 rgba(0, 0, 0, 255));\n"
"\n"
"	min-height: 0; \n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar:handle:hover { background: rgb(45, 78, 93); }\n"
"QScrollBar:add-line:vertical { border: none; background: none; }\n"
"QScrollBar:sub-line:vertical { border: none; background: none; }\n"
"QScrollBar:horizontal { \n"
"	background: white; \n"
"	height: 8px; \n"
"	margin-left: 10px; \n"
"	border: 1px solid transparent;\n"
"	border-radius: 4px; \n"
"}\n"
"QScrollBar:handle:horizontal { \n"
"	background: qlineargradient(spread:pad, x1:1, y1:0.494, x2:0, y2:0.494, stop:0 rgba(103, 102, 103, 255), stop:1 rgba(0, 0, 0, 255));\n"
"	min-width: 0; \n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar:add-line:horizontal { border: none; background: none; "
                        "}\n"
"QScrollBar:sub-line:horizontal { border: none; background: none; }"));
        centralWidget = new QWidget(PhoneBook);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget {\n"
"	background: rgb(242, 242, 242); \n"
"	border-radius: 10px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameTop = new QFrame(centralWidget);
        frameTop->setObjectName(QStringLiteral("frameTop"));
        frameTop->setStyleSheet(QLatin1String("QFrame#frameTop {\n"
"	background: rgb(103, 102, 103);\n"
"	border-radius: 0;\n"
"}"));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameTop);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(frameTop);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setMinimumSize(QSize(35, 35));
        btnClose->setMaximumSize(QSize(35, 35));
        btnClose->setCursor(QCursor(Qt::PointingHandCursor));
        btnClose->setStyleSheet(QLatin1String("QPushButton#btnClose {\n"
"	background: transparent;\n"
"	image: url(:/img/close.png);\n"
"	padding: 5px;\n"
"}\n"
"QPushButton#btnClose:hover {\n"
"	image: url(:/img/closeHover.png);\n"
"	padding: 2px;\n"
"}"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);

        lblTitle = new QLabel(frameTop);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setStyleSheet(QLatin1String("QLabel#lblTitle {\n"
"	font: 40pt \"AR DESTINE\";\n"
"	background: transparent;\n"
"}"));
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitle);


        verticalLayout_2->addWidget(frameTop);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 802, 791));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 30, 20, 20);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lblFullName = new QLabel(scrollAreaWidgetContents);
        lblFullName->setObjectName(QStringLiteral("lblFullName"));
        lblFullName->setStyleSheet(QLatin1String("QLabel#lblFullName {\n"
"	font: 10pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"}"));

        horizontalLayout_5->addWidget(lblFullName);

        lEditFullname = new QLineEdit(scrollAreaWidgetContents);
        lEditFullname->setObjectName(QStringLiteral("lEditFullname"));
        lEditFullname->setMinimumSize(QSize(301, 0));
        lEditFullname->setMaximumSize(QSize(301, 31));
        lEditFullname->setStyleSheet(QLatin1String("QLineEdit#lEditFullname {\n"
"	font: 75 italic 15pt \"Garamond\";\n"
"	background: transparent;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 10px;\n"
"	color: rgb(103, 102, 103);\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	selection-background-color: rgb(103, 102, 103);\n"
"}\n"
"\n"
"QLineEdit#lEditFullname:focus {\n"
"	border: 1px solid rgb(92, 192, 254);\n"
"}"));

        horizontalLayout_5->addWidget(lEditFullname);

        lEditPhoneNumber = new QLineEdit(scrollAreaWidgetContents);
        lEditPhoneNumber->setObjectName(QStringLiteral("lEditPhoneNumber"));
        lEditPhoneNumber->setMinimumSize(QSize(201, 0));
        lEditPhoneNumber->setMaximumSize(QSize(201, 31));
        lEditPhoneNumber->setStyleSheet(QLatin1String("QLineEdit#lEditPhoneNumber {\n"
"	font: 75 italic 15pt \"Garamond\";\n"
"	background: transparent;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-top-right-radius: 10px;\n"
"	border-bottom-right-radius: 20px;\n"
"	color: rgb(103, 102, 103);\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	selection-background-color: rgb(103, 102, 103);\n"
"}\n"
"\n"
"QLineEdit#lEditPhoneNumber:focus {\n"
"	border: 1px solid rgb(92, 192, 254);\n"
"}"));

        horizontalLayout_5->addWidget(lEditPhoneNumber);

        lblPhoneNumber = new QLabel(scrollAreaWidgetContents);
        lblPhoneNumber->setObjectName(QStringLiteral("lblPhoneNumber"));
        lblPhoneNumber->setStyleSheet(QLatin1String("QLabel#lblPhoneNumber {\n"
"	font: 10pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"}"));

        horizontalLayout_5->addWidget(lblPhoneNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(20, -1, -1, -1);
        btnAdd = new QPushButton(scrollAreaWidgetContents);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMinimumSize(QSize(70, 0));
        btnAdd->setCursor(QCursor(Qt::PointingHandCursor));
        btnAdd->setStyleSheet(QLatin1String("QPushButton#btnAdd {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 10px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 10px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnAdd:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_6->addWidget(btnAdd);

        btnFind = new QPushButton(scrollAreaWidgetContents);
        btnFind->setObjectName(QStringLiteral("btnFind"));
        btnFind->setMinimumSize(QSize(70, 0));
        btnFind->setCursor(QCursor(Qt::PointingHandCursor));
        btnFind->setStyleSheet(QLatin1String("QPushButton#btnFind {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-top-right-radius: 10px;\n"
"	border-bottom-right-radius: 20px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnFind:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_6->addWidget(btnFind);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_6);

        lblTitleLab1 = new QLabel(scrollAreaWidgetContents);
        lblTitleLab1->setObjectName(QStringLiteral("lblTitleLab1"));
        lblTitleLab1->setStyleSheet(QLatin1String("QLabel#lblTitleLab1 {\n"
"	font: 20pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	text-decoration: underline;\n"
"}"));

        verticalLayout_3->addWidget(lblTitleLab1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lblHeader = new QLabel(scrollAreaWidgetContents);
        lblHeader->setObjectName(QStringLiteral("lblHeader"));
        lblHeader->setStyleSheet(QLatin1String("QLabel#lblHeader {\n"
"		border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 0px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 0px;\n"
"	background-color: rgb(103, 102, 103);\n"
"	font: 12pt \"AR DESTINE\";\n"
"	color: white;\n"
"	padding: 10px;\n"
"}"));

        verticalLayout_4->addWidget(lblHeader);

        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(760, 400));
        listWidget->setMaximumSize(QSize(760, 400));
        listWidget->setStyleSheet(QLatin1String("font: 75 italic 15pt \"Garamond\";\n"
"color: rgb(123, 122, 123);"));

        verticalLayout_4->addWidget(listWidget);


        verticalLayout_3->addLayout(verticalLayout_4);

        lblError = new QLabel(scrollAreaWidgetContents);
        lblError->setObjectName(QStringLiteral("lblError"));
        lblError->setMinimumSize(QSize(0, 30));
        lblError->setMaximumSize(QSize(16777215, 30));
        lblError->setStyleSheet(QLatin1String("QLabel#lblError {\n"
"	font: 75 italic 15pt \"Garamond\";\n"
"	color: red;\n"
"	background: transparent;\n"
"}"));

        verticalLayout_3->addWidget(lblError);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnOpen = new QPushButton(scrollAreaWidgetContents);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setMinimumSize(QSize(70, 0));
        btnOpen->setCursor(QCursor(Qt::PointingHandCursor));
        btnOpen->setStyleSheet(QLatin1String("QPushButton#btnOpen {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-top-right-radius: 10px;\n"
"	border-bottom-right-radius: 20px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnOpen:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnOpen);

        btnSave = new QPushButton(scrollAreaWidgetContents);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setMinimumSize(QSize(70, 0));
        btnSave->setCursor(QCursor(Qt::PointingHandCursor));
        btnSave->setStyleSheet(QLatin1String("QPushButton#btnSave {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 10px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 10px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnSave:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnSave);

        horizontalSpacer_5 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btnClear = new QPushButton(scrollAreaWidgetContents);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMinimumSize(QSize(70, 0));
        btnClear->setCursor(QCursor(Qt::PointingHandCursor));
        btnClear->setStyleSheet(QLatin1String("QPushButton#btnClear {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-top-right-radius: 10px;\n"
"	border-bottom-right-radius: 20px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnClear:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnClear);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnDelete = new QPushButton(scrollAreaWidgetContents);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setMinimumSize(QSize(70, 0));
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));
        btnDelete->setStyleSheet(QLatin1String("QPushButton#btnDelete {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 10px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 10px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnDelete:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnDelete);

        btnEdit = new QPushButton(scrollAreaWidgetContents);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setMinimumSize(QSize(70, 0));
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));
        btnEdit->setStyleSheet(QLatin1String("QPushButton#btnEdit {\n"
"	font: 15pt \"AR DESTINE\";\n"
"	color: rgb(103, 102, 103);\n"
"	background: transparent;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 10px;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 10px;\n"
"	border: 1px solid rgb(103, 102, 103);\n"
"}\n"
"\n"
"QPushButton#btnEdit:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        PhoneBook->setCentralWidget(centralWidget);

        retranslateUi(PhoneBook);
        QObject::connect(btnClose, SIGNAL(clicked()), PhoneBook, SLOT(close()));

        QMetaObject::connectSlotsByName(PhoneBook);
    } // setupUi

    void retranslateUi(QMainWindow *PhoneBook)
    {
        PhoneBook->setWindowTitle(QApplication::translate("PhoneBook", "PhoneBook", 0));
        btnClose->setText(QString());
        lblTitle->setText(QApplication::translate("PhoneBook", "PHONEBOOK", 0));
        lblFullName->setText(QApplication::translate("PhoneBook", "fullname:", 0));
        lEditFullname->setPlaceholderText(QApplication::translate("PhoneBook", "Ivanov Ivan Ivanovich", 0));
        lEditPhoneNumber->setPlaceholderText(QApplication::translate("PhoneBook", "+7123456789", 0));
        lblPhoneNumber->setText(QApplication::translate("PhoneBook", ":phone", 0));
        btnAdd->setText(QApplication::translate("PhoneBook", "add", 0));
        btnFind->setText(QApplication::translate("PhoneBook", "find", 0));
        lblTitleLab1->setText(QApplication::translate("PhoneBook", " DATA:                                  ", 0));
        lblHeader->setText(QApplication::translate("PhoneBook", "fullname                           phone", 0));
        lblError->setText(QString());
        btnOpen->setText(QApplication::translate("PhoneBook", "open", 0));
        btnSave->setText(QApplication::translate("PhoneBook", "save", 0));
        btnClear->setText(QApplication::translate("PhoneBook", "clear", 0));
        btnDelete->setText(QApplication::translate("PhoneBook", "delete", 0));
        btnEdit->setText(QApplication::translate("PhoneBook", "edit", 0));
    } // retranslateUi

};

namespace Ui {
    class PhoneBook: public Ui_PhoneBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
