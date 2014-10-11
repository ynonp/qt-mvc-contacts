#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "contactitem.h"
#include "addressbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void setInputFieldsData();
    void doFilter(QString term);


private:
    Ui::MainWindow *ui;
    QAbstractItemModel *_model;

    AddressBook _contacts;
};

#endif // MAINWINDOW_H
