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
    QQmlContext *ctxt = engine.rootContext();

    qmlRegisterType<FileItem>("CppImport",1,0,"FileItem");

    FileListProvider *fileListProvider = new FileListProvider();
    ctxt->setContextProperty("fileListProvider", fileListProvider);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
