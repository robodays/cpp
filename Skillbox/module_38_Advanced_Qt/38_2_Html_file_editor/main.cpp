#include <QApplication>

#include <QWebEngineView>
#include <QHBoxLayout>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto *htmlEditor = new QWidget(nullptr);
    auto *editor = new QTextEdit;
    auto *webView = new QWebEngineView;

    auto *vbox = new QHBoxLayout(htmlEditor);
    vbox->addWidget(editor,1);
    vbox->addWidget(webView,1);

    editor->setPlainText("<HTML>"
                         "<BODY BGPROPERTIES=FIXED BACKGROUND=Backg8.gif TEXT= blue"
                         "<FONT SIZE=12 FACE=""Times New Roman"">"
                           "<P ALIGN=JUSTIFY>"
                           "&nbsp;&nbsp;&nbsp;"
                           "Класс <b>QTextEdit</b> содержит следующие методы:"
                           "<ul>"
                           "<li><b>setReadOnly()</b> устанавливает или снимает режим блокировки изменения текста;"
                           "<li><b>text()</b> возвращает текущий текст."
                           "</ul></p>"
                           "<P ALIGN=JUSTIFY>"
                           "&nbsp;&nbsp;&nbsp;"
                           "Слоты класса <b>QTextEdit</b>:   "
                           "<ul>"
                           "<li><b>setPlainText()</b> — установка обычного текста;"
                           "<li><b>setHtml()</b> — установка текста в формате HTML;"
                           "<li><b>copy()</b>, <b>cut()</b> и <b>paste()</b> — работа с буфером обмена (копировать, вырезать и вставить соответственно);"
                           "<li><b>selectAll()</b> или <b>deselect()</b> — выделение или снятие выделения всего текста;"
                           "<li><b>clear()</b> — очистка поля ввода."
                           "</ul></p>"
                           "</FONT>"
                           "</BODY>"
                           "</HTML>");

    webView->setHtml(editor->toPlainText());

    QObject::connect(editor, &QTextEdit::textChanged, [&webView, &editor](){
        webView->setHtml(editor->toPlainText());
    });

    webView->show();

    htmlEditor->show();
    return a.exec();
}
