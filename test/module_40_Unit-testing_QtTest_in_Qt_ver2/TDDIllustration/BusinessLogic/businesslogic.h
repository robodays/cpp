#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include "BusinessLogic_global.h"
#include <QObject>
#include <QHash>

class BUSINESSLOGIC_EXPORT BusinessLogic: public QObject
{
    Q_OBJECT

public:
    BusinessLogic(QObject* parent=nullptr);

    Q_INVOKABLE uint fib(uint) noexcept;

private:
    QHash<uint,uint> m_fib;
};

#endif // BUSINESSLOGIC_H
