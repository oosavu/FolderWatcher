#include <QApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>
#include "fileitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QList<QObject*> folderList;
    folderList.append(new FileItem("Item 1", false));
    folderList.append(new FileItem("Ite1sdfm 1", false));
    folderList.append(new FileItem("Item aaaaa1", false));

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("folderListModel", QVariant::fromValue(folderList));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
