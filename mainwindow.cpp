#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);

    foreach( int id, _contacts.getAllContactIds() )
    {
        ContactItem contact = _contacts.getContactItem(id);
        QString name = contact.name();
        QStandardItem *item = new QStandardItem(name);
        item->setEditable(false);
        item->setData(id, Qt::UserRole + 1);
        model->appendRow(item);
    }

    ui->listView->setModel(model);

    QObject::connect(ui->listView, &QListView::clicked, this, &MainWindow::setInputFieldsData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInputFieldsData()
{
    QModelIndex that = ui->listView->currentIndex();

    int id = that.data(Qt::UserRole + 1).toInt();
    ContactItem item = _contacts.getContactItem(id);

    ui->lineEdit->setText(item.name());
    ui->lineEdit_2->setText(item.email());

}
