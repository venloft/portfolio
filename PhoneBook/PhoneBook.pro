#-------------------------------------------------
#
# Project created by QtCreator 2019-10-17T22:49:46
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qtestlib
TARGET = PhoneBook
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        phonebook.cpp \
    phoneb.cpp \
    test.cpp

HEADERS  += phonebook.h \
    phoneb.h \
    test.h

FORMS    += phonebook.ui

RESOURCES += \
    resource.qrc
