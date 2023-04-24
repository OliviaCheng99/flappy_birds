#include "appsettings.h"


QString AppSettings::dirPath;

AppSettings::AppSettings(QObject *parent)
    : QObject{parent}
{
}

void AppSettings::initializeDirPath()
{
    QDir dir(QCoreApplication::applicationDirPath());
    dirPath = dir.relativeFilePath("../../"); // up two levels to get to the main folder
}
