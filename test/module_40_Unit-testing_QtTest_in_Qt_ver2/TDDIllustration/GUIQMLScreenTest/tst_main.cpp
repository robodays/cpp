#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickTest/quicktest.h>
#include <QtCore/qstring.h>
#include <QQmlEngine>
#include <QtQml>

#ifdef QT_OPENGL_LIB
#include <QtOpenGL/qgl.h>
#endif


int main(int argc, char **argv)
{
   return quick_test_main(argc, argv, "trainingCase", QUICK_TEST_SOURCE_DIR);
}

