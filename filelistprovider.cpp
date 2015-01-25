#include "filelistprovider.h"


FileListProvider::FileListProvider(QObject *parent) : QObject(parent)
{
    dir.setFilter(QDir::NoDotAndDotDot|QDir::AllEntries);
    setFolderPath(QDir::currentPath());
}

FileListProvider::~FileListProvider()
{

}

QQmlListProperty<FileItem> FileListProvider::getFileList()
{
    return QQmlListProperty<FileItem>(this,m_fileList);
}

QString FileListProvider::getFolderPath() const
{
    return m_folderPath;
}

void FileListProvider::setFolderPath(QString arg)
{
    if (m_folderPath == arg)
        return;

    m_folderPath = arg;    
    m_fileList.clear();
    if(dir.cd(m_folderPath))
    {
        QFileInfoList list = dir.entryInfoList();
        foreach(QFileInfo fInfo, list)
        {
            m_fileList.append(new FileItem(fInfo.fileName(),fInfo.isDir()));
        }
        m_folderPathExists = true;
    }
    else
    {
        m_folderPathExists = false;
    }
    emit fileListChanged();
    emit folderPathExistsChanged();
    emit folderPathChanged();
}

