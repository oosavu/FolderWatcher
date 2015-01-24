#include "fileitem.h"

FileItem::FileItem(QString name, bool isFolder, QObject *parent) : QObject(parent)
{
    m_name = name;
    m_isFolder = isFolder;
}

FileItem::~FileItem()
{
    m_name = "";
    m_isFolder = false;
}

QString FileItem::getName() const
{
    return m_name;
}

bool FileItem::getIsFolder() const
{
    return m_isFolder;
}

void FileItem::setName(QString arg)
{
    if (m_name == arg)
        return;

    m_name = arg;
    emit nameChanged(arg);
}
void FileItem::setIsFolder(bool arg)
{
    if (m_isFolder == arg)
        return;

    m_isFolder = arg;
    emit isFolderChanged(arg);
}
