#ifndef BUSINESSLOGIC_GLOBAL_H
#define BUSINESSLOGIC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BUSINESSLOGIC_LIBRARY)
#  define BUSINESSLOGIC_EXPORT Q_DECL_EXPORT
#else
#  define BUSINESSLOGIC_EXPORT Q_DECL_IMPORT
#endif

#endif // BUSINESSLOGIC_GLOBAL_H
