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

QList<User> AppSettings::readUsersFromFile()
{
    QDir dir(dirPath);
    dir.cdUp(); // Move up one level to the parent directory of the A3 folder
    dir.cd("database"); // Go into the "database" directory
    QString databasePath = dir.absolutePath(); // Get the absolute path of the database directory

    QFile file(databasePath + QDir::separator() + "users.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Couldn't open user data file.");
        return QList<User>();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = doc.array();
    QList<User> users;

    for (const QJsonValue &value : jsonArray)
    {
        QJsonObject obj = value.toObject();
        User user = User::fromJsonObject(obj);
        users.append(user);
    }

    return users;
}


// Rank users based on their bestScore
void AppSettings::rankUsersByBestScore(QList<User> &users)
{
    // Sort the users based on their bestScore in descending order
    std::sort(users.begin(), users.end(), [](const User &a, const User &b) {
        return a.getBestScore() > b.getBestScore();
    });

    // Assign rankings to the users based on their sorted position
    for (int i = 0; i < users.size(); ++i)
    {
        users[i].setRanking(i + 1);
    }
}
