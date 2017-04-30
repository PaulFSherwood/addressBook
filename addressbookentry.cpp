#include "addressbookentry.h"

AddressBookEntry::AddressBookEntry(QObject *parent) : QObject(parent)
{

}
AddressBookEntry::~AddressBookEntry()
{

}

QString AddressBookEntry::name() const
{
    return m_name;
}

void AddressBookEntry::setName(const QString &name)
{
    m_name = name;
}

QString AddressBookEntry::address() const
{
    return m_address;
}

void AddressBookEntry::setAddress(const QString &address)
{
    m_address = address;
}

QDate AddressBookEntry::birthday() const
{
    return m_birthday;
}

void AddressBookEntry::setBirthday(const QDate &birthday)
{
    m_birthday = birthday;
}

QStringList AddressBookEntry::phoneNumbers() const
{
    return m_phoneNumbers;
}

void AddressBookEntry::setPhoneNumbers(const QStringList &phoneNumbers)
{
    m_phoneNumbers = phoneNumbers;
}
