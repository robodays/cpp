Добавьте путь MinGW в переменную системной среды, чтобы программа могла автоматически найти эти библиотеки
PATH C:\Qt6\6.2.0\mingw81_64\bin
https://russianblogs.com/article/8896872563/

QML2_IMPORT_PATH как C:\Qt6\6.2.0\mingw81_64\qml
https://question-it.com/questions/6741894/qt5-qml-v-clion-qqmlapplicationengine-ne-udalos-zagruzit-komponent

можно почитать  https://doc.qt.io/qt-5/qtqml-syntax-imports.html#qml-import-path


Обратите внимание, что CLion необходимо перезапустить после установки переменных системной среды. В CLion есть дефект, заключающийся в том, что переменные системной среды загружаются только при запуске и не обновляются автоматически при компиляции программы.