#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(this);

    foreach( int id, _contacts.getAllContactIds() )
    {
        ContactItem contact = _contacts.getContactItem(id);
        QString name = contact.name();
        QStandardItem *item = new QStandardItem(name);
        item->setEditable(false);
        item->setData(id, Qt::UserRole + 1);
        model->appendRow(item);
    }


    _model = new QSortFilterProxyModel(this);
    ((QSortFilterProxyModel *)_model)->setSourceModel(model);

    ui->listView->setModel(_model);

    QObject::connect(ui->listView, &QListView::clicked, this, &MainWindow::setInputFieldsData);
    QObject::connect(ui->searchEdit, &QLineEdit::textChanged, this, &MainWindow::doFilter);
}

void MainWindow::doFilter(QString term)
{
    QSortFilterProxyModel *filterProxy =
            qobject_cast<QSortFilterProxyModel *>(_model);

    filterProxy->setFilterFixedString(term);
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
