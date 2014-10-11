#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <QtCore>
#include "contactitem.h"

class AddressBook
{
public:
    AddressBook();

    int addContact(QString name, QString email);
    void removeContact(int id);

    ContactItem getContactItem(int id);

    QList<int> getAllContactIds();

    void fillWithDummyData();

private:
    QMap<int, ContactItem> _data;
    int _nextId;
};

#endif // ADDRESSBOOK_H
