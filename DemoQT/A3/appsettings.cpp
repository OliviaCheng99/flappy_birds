#include "appsettings.h"


QString AppSettings::dirPath;

AppSettings::AppSettings(QObject *parent)
    : QObject{parent}
{
}

void AppSettings::initializeDirPath()
{
    QDir dir(QCoreApplication::applicationDirPath());
    //dirPath = dir.relativeFilePath("../../"); // up two levels to get to the main folder
    dir.cdUp(); // Move up one level to the parent directory of the build folder
    dir.cdUp(); // Move up one level to the parent directory of the build folder
    dir.cdUp(); // Move up another level to the parent directory of the "Contents" folder
    dir.cdUp();
    dir.cd("DemoQT"); // Go into the "DemoQT" directory
    dirPath = dir.absolutePath(); // Get the absolute path of the parent directory
}

