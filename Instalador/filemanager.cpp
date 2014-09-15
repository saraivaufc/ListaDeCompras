#include "filemanager.h"

FileManager::FileManager() {
}

void FileManager::createDothDesktop() {
    QFile file(EXEC_NAME);

    file.open(QIODevice::WriteOnly);
    file << QString(SHELL_COMAND);
}
