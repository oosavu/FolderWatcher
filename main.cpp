#include <QApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "filelistprovider.h"
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    //Получаем ссылку на контекст QML.
    QQmlContext *ctxt = engine.rootContext();
    //Регистрируем необходимый нам тип, используемый в ListView
    qmlRegisterType<FileItem>("CppImport",1,0,"FileItem");

    //Обеспечиваем доступ к файловой системе из QML
    FileListProvider *fileListProvider = new FileListProvider();
    ctxt->setContextProperty("fileListProvider", fileListProvider);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
