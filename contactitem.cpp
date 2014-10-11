#include "contactitem.h"

ContactItem::ContactItem()
{
}

ContactItem::ContactItem(QString name, QString email) :
    _name(name),
    _email(email)
{
}

ContactItem::ContactItem(const ContactItem &other):
    _name(other.name()),
    _email(other.email())
{
}

QString ContactItem::name() const
{
    return _name;
}

QString ContactItem::email() const
{
    return _email;
}

bool ContactItem::operator==(const ContactItem &other) const
{
    return ((name() == other.name()) && (email() == other.email()));
}

const ContactItem &ContactItem::operator=(const ContactItem &other)
{
    _name = other.name();
    _email = other.email();
    return *this;
}

// hash friendly
uint qHash( const ContactItem &key )
{
    uint result = 17;
    result = result * 23 + qHash(key.name());
    result = result * 23 + qHash(key.email());
    return result;
}

// debug friendly
QDebug operator<<(QDebug d, const ContactItem &contact)
{
    d << contact.name() << ':' << contact.email();
    return d;
}
