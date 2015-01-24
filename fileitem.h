#ifndef FILEITEM_H
#define FILEITEM_H

#include <QObject>

class FileItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool isFolder READ getIsFolder WRITE setIsFolder NOTIFY isFolderChanged)

    QString m_name;
    bool m_isFolder;

public:
    explicit FileItem(QObject *parent = 0);
    explicit FileItem(QString name, bool isFolder, QObject *parent = 0);
    ~FileItem();

    QString getName() const
    {
        return m_name;
    }

    bool getIsFolder() const
    {
        return m_isFolder;
    }

signals:

    void nameChanged(QString arg);

    void isFolderChanged(bool arg);

public slots:
    void setName(QString arg);
    void setIsFolder(bool arg);
};

#endif // FILEITEM_H
