#include <QtTest>

// add necessary includes here
#include "businesslogic.h"

class testFibonacci : public QObject
{
    Q_OBJECT

public:
    testFibonacci();
    ~testFibonacci();

private slots:
    void testcase_data();
    void testcase();

private:
    BusinessLogic* m_businessLogic;

};

testFibonacci::testFibonacci()
{
    m_businessLogic = new BusinessLogic(this);
}

testFibonacci::~testFibonacci()
{

}

void testFibonacci::testcase_data()
{
    QTest::addColumn<uint>("input");
    QTest::addColumn<uint>("expectedresult");

    QTest::newRow("Fib 0") << uint(0) << uint(0);
    QTest::newRow("Fib 1") << uint(1) << uint(1);
    QTest::newRow("Fib 2") << uint(2) << uint(1);
    QTest::newRow("Fib 5") << uint(5) << uint(5) ;
    QTest::newRow("Fib 23") << uint(23) << uint(28657);
    QTest::newRow("Fib 50") << uint(50) << uint(12586269025);

}

void testFibonacci::testcase()
{
    QFETCH(uint, input);
    QFETCH(uint , expectedresult);

    uint actualresult;
    QBENCHMARK {
        actualresult= m_businessLogic->fib(input);
    }

    QCOMPARE(actualresult, expectedresult);
}

QTEST_APPLESS_MAIN(testFibonacci)

#include "tst_testfibonacci.moc"
