#include "loginwindow.h"
#include "appsettings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppSettings::initializeDirPath();


    LoginWindow w;




    w.show();
    return a.exec();
}
