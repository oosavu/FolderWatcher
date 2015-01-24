#ifndef FILELISTPROVIDER_H
#define FILELISTPROVIDER_H

#include <QList>
#include <QDir>
#include <QQmlListProperty>
#include "fileitem.h"

class FileListProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<FileItem> fileList READ getFileList NOTIFY fileListChanged)
    Q_PROPERTY(QString folderPath READ getFolderPath WRITE setFolderPath NOTIFY folderPathChanged)

    QString m_folderPath;
    QList<FileItem*> m_fileList;
    QDir dir;

    void refreshFileList(QString path);

public:
    explicit FileListProvider(QObject *parent = 0);
    ~FileListProvider();

    QQmlListProperty<FileItem> getFileList();
    QString getFolderPath() const;

signals:

    void folderPathChanged(QString arg);
    void fileListChanged();

public slots:
    void setFolderPath(QString arg);
private:

};

#endif // FILELISTPROVIDER_H
