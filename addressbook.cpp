#include "addressbook.h"

AddressBook::AddressBook():
_nextId(0)
{
    fillWithDummyData();
}

int AddressBook::addContact(QString name, QString email)
{
    _data[_nextId] = ContactItem(name, email);
    return _nextId++;
}

void AddressBook::removeContact(int id)
{
    _data.remove(id);
}

ContactItem AddressBook::getContactItem(int id)
{
    return _data[id];
}

QList<int> AddressBook::getAllContactIds()
{
    return _data.keys();
}

void AddressBook::fillWithDummyData()
{
    addContact("joe", "joe@gmail.com");
    addContact("bob", "bob@yahoo.com");
    addContact("mike", "mike@walla.co.il");
    addContact("jane", "jane@gmail.com");
}
