#pragma once

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include<QDir>
#include<QApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include "user.h"



class AppSettings : public QObject
{
    Q_OBJECT

public:
    explicit AppSettings(QObject *parent = nullptr);
    static void initializeDirPath();
    static QList<User> readUsersFromFile();
    static QString rankUsersByBestScore();

    static QString dirPath;
};



#endif // APPSETTINGS_H
