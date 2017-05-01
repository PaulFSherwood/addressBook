#include <QtGlobal>
#include "addressbookcontroller.h"

AddressBookController::AddressBookController(
        AddressBook *addressBook, QObject *parent) :
        QObject(parent),
        m_addressBook(addressBook)
{
    Q_ASSERT(addressBook != nullptr);
}

AddressBookEntry *AddressBookController::createEntry()
{
    auto result = m_addressBook->createEntry();
    if(result != nullptr){
        int randomValue = qrand();
        QString aString = QString::number(randomValue);

        result->setName( QString(tr("New Entry...%1")).arg(aString) );
    }
    return result;
}

bool AddressBookController::deleteEntry(AddressBookEntry *entry)
{
    return m_addressBook->deleteEntry(entry);
}
