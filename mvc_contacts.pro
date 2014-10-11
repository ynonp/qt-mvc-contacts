#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T10:27:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvc_contacts
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contactitem.cpp \
    addressbook.cpp

HEADERS  += mainwindow.h \
    contactitem.h \
    addressbook.h

FORMS    += mainwindow.ui
