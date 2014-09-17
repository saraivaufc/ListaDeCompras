<<<<<<< HEAD
#include "filemanager.h"

FileManager::FileManager() {
}

void FileManager::createDothDesktop() {
    QFile file(EXEC_NAME);

    file.open(QIODevice::WriteOnly);
    file.write(SHELL_COMAND);
}
=======
#include "filemanager.h"

FileManager::FileManager() {
}

void FileManager::createDothDesktop() {
    QFile file(EXEC_NAME);

    file.open(QIODevice::WriteOnly);
    file << QString(SHELL_COMAND);
}
>>>>>>> b678a198cae01f58662b82bb94045658b64fb426
