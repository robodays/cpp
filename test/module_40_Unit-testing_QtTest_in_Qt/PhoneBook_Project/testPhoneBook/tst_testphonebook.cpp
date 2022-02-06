#include <QtTest>

// add necessary includes here
#include "phonebook.h"

//#include "../PhoneBook/PhoneBook_global.h"
//#include "../PhoneBook/phonebook.h"

class testPhoneBook : public QObject
{
    Q_OBJECT

public:
    testPhoneBook();
    ~testPhoneBook();


private slots:
    void addRecordTest();
    void filterRecords();

};

testPhoneBook::testPhoneBook()
{
}

testPhoneBook::~testPhoneBook()
{
}

void testPhoneBook::addRecordTest()
{
    PhoneBook pBook;
    pBook.add({"John", "Smith", "+79091234567"});
    pBook.add({"Martin", "Chase", "+79261234567"});
    pBook.add({"Luke", "Bradly", "+79857654321"});

    QVERIFY2(pBook.getAll().size() == 3, "add 3 records");
}

void testPhoneBook::filterRecords()
{
    PhoneBook pBook;
    pBook.add({"John", "Smith", "+79091234567"});
    pBook.add({"Martin", "Chase", "+79261234567"});
    pBook.add({"Luke", "Bradly", "+79857654321"});

    QVERIFY2(pBook.filter("Jo").size() == 1, "only one Jo");
    QVERIFY2(pBook.filter("123").size() == 2, "to num contains 452");
    QVERIFY2(pBook.filter("ssffergsf").size() == 0, "non existing pattern");
}


QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_testphonebook.moc"
