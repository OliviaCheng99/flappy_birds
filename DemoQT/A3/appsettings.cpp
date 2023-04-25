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

// Read user data from the users.json file located in the 'database' folder
QList<User> AppSettings::readUsersFromFile()
{
    // Navigate to the 'database' folder that is located at the same level as the A3 folder
    QDir dir(dirPath);
    dir.cdUp(); // Move up one level to the parent directory of the A3 folder
    dir.cd("database"); // Go into the "database" directory
    QString databasePath = dir.absolutePath(); // Get the absolute path of the database directory

    // Open the users.json file for reading
    QFile file(databasePath + QDir::separator() + "users.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Couldn't open user data file.");
        return QList<User>();
    }

    // Read all data from the users.json file into a QByteArray
    QByteArray jsonData = file.readAll();
    file.close();

    // Parse the JSON data into a QJsonDocument
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    // Convert the QJsonDocument to a QJsonArray
    QJsonArray jsonArray = doc.array();
    // Create a QList to store the User objects
    QList<User> users;

    // Iterate through the QJsonArray and create User objects from the JSON data
    for (const QJsonValue &value : jsonArray)
    {
        QJsonObject obj = value.toObject();
        User user = User::fromJsonObject(obj);
        users.append(user);
    }

    // Return the list of User objects
    return users;
}



// Rank users based on their bestScore
QString AppSettings::rankUsersByBestScore()
{
    QList<User> users = readUsersFromFile();
    // Sort the users based on their bestScore in descending order
    std::sort(users.begin(), users.end(), [](const User &a, const User &b) {
        return a.getBestScore() > b.getBestScore();
    });

    // Assign rankings to the users based on their sorted position
    for (int i = 0; i < users.size(); ++i)
    {
        users[i].setRanking(i + 1);

    }

    // return a top ten list
    QJsonArray topTenUsersArray;
    int end = users.size() < 10 ? users.size() : 10;
    for (int i = 0; i< end; i++){
        topTenUsersArray.append(users[i].toJsonObject());
    }
    QJsonDocument jsonDoc(topTenUsersArray);
    QString jsonString = QString::fromUtf8(jsonDoc.toJson());
}
