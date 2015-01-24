#ifndef FILELISTPROVIDER_H
#define FILELISTPROVIDER_H

#include <QObject>

class FileListProvider : public QObject
{
    Q_OBJECT
public:
    explicit FileListProvider(QObject *parent = 0);
    ~FileListProvider();

signals:

public slots:
};

#endif // FILELISTPROVIDER_H
