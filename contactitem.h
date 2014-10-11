#ifndef CONTACTITEM_H
#define CONTACTITEM_H

#include <QtCore>
#include <QString>
#include <QMetaType>

class ContactItem
{
public:
    ContactItem();
    ContactItem(QString name, QString email);
    ContactItem(const ContactItem &other);

    bool operator==(const ContactItem &other) const;

    const ContactItem &operator=(const ContactItem &other);

public:
    QString name() const;
    QString email() const;

private:
    QString _name;
    QString _email;
};

// hash friendly
uint qHash( const ContactItem &key );

// debug friendly
QDebug operator<<(QDebug d, const ContactItem &contact);

Q_DECLARE_METATYPE(ContactItem);

#endif // CONTACTITEM_H
