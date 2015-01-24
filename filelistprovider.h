#ifndef FILELISTPROVIDER_H
#define FILELISTPROVIDER_H

#include <QList>
#include <QDir>
#include <QQmlListProperty>
#include "fileitem.h"

/**
 * @brief Класс, обеспечивающий работу с файловой системой для QML.
 * Содержит два свойства: путь к папке folderPath и список элементов @FileItem fileList,
 * предоставляющий информацию о содержимом указанной папки.
 * При изменении folderPath значения fileList обновляются.
 * В случае, если folderPath содержит пустое значение, fileList сожержит список файлов и папок директории запуска приложения
 * В случае, если папки folderPath не существует, fileList является пустым списком.
 */
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
