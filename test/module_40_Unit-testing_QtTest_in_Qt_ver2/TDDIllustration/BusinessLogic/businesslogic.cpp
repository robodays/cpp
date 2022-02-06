#include "businesslogic.h"

BusinessLogic::BusinessLogic(QObject* parent):QObject(parent)
{
}

uint BusinessLogic::fib(uint n) noexcept
{
    if(n== 0)
        return 0;
    if(n == 1)
         return 1;
    else if(m_fib.contains(n))
         return m_fib.value(n);
     else{
          m_fib.insert(n, fib(n-1)+fib(n-2) );
          return m_fib[n];
     }
}
