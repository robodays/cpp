#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "PhoneBook_global.h"
#include <QList>

struct Record
{
    QString firstName;
    QString lastName;
    QString phone;
};

class PHONEBOOK_EXPORT PhoneBook
{
public:
    PhoneBook();
    void add(Record toAdd);
    QList<Record> getAll();
    QList<Record> filter(QString pattern);
private:
    QList<Record> mData;
};

#endif // PHONEBOOK_H
