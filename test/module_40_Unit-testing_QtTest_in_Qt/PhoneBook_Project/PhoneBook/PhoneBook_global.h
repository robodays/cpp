#ifndef PHONEBOOK_GLOBAL_H
#define PHONEBOOK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PHONEBOOK_LIBRARY)
#  define PHONEBOOK_EXPORT Q_DECL_EXPORT
#else
#  define PHONEBOOK_EXPORT Q_DECL_IMPORT
#endif

//#ifndef PHONEBOOK_EXPORT Q_DECL_EXPORT
//#define PHONEBOOK_EXPORT Q_DECL_EXPORT
//#endif

#endif // PHONEBOOK_GLOBAL_H
