#pragma once

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include<QDir>
#include<QApplication>




class AppSettings : public QObject
{
    Q_OBJECT

public:
    explicit AppSettings(QObject *parent = nullptr);
    static void initializeDirPath();
    static QString dirPath;

};



#endif // APPSETTINGS_H
