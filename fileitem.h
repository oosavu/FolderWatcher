#ifndef FILEITEM_H
#define FILEITEM_H

#include <QObject>

class FileItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(bool isFolder READ getIsFolder NOTIFY isFolderChanged)

    QString m_name;
    bool m_isFolder;

public:
    explicit FileItem(QString name = "", bool isFolder = false, QObject *parent = 0);
    ~FileItem();

    QString getName() const;
    bool getIsFolder() const;

signals:

    void nameChanged(QString arg);

    void isFolderChanged(bool arg);

public slots:
    void setName(QString arg);
    void setIsFolder(bool arg);
};

#endif // FILEITEM_H
