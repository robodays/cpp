#include <QtTest>

// add necessary includes here

class testPhoneBook : public QObject
{
    Q_OBJECT

public:
    testPhoneBook();
    ~testPhoneBook();

private slots:
    void test_case1();

};

testPhoneBook::testPhoneBook()
{

}

testPhoneBook::~testPhoneBook()
{

}

void testPhoneBook::test_case1()
{

}

QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_testphonebook.moc"
