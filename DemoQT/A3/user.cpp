#include "user.h"

User::User(const QString &username,
           const QString &password,
           const QString &firstName,
           const QString &lastName,
           const QDate &birthDate,
           const QString &profilePicturePath,
           int lastScore,
           int bestScore,
           int ranking)
    : my_username(username),
    my_password(password),
    my_firstName(firstName),
    my_lastName(lastName),
    my_birthDate(birthDate),
    my_profilePicturePath(profilePicturePath),
    my_lastScore(lastScore),
    my_bestScore(bestScore),
    my_ranking(ranking)
{
}

QString User::getUsername() const { return my_username; }
QString User::getPassword() const { return my_password; }
QString User::getFirstName() const { return my_firstName; }
QString User::getLastName() const { return my_lastName; }
QDate User::getBirthDate() const { return my_birthDate; }
QString User::getProfilePicturePath() const { return my_profilePicturePath; }
int User::getLastScore() const { return my_lastScore; }
int User::getBestScore() const { return my_bestScore; }
int User::getRanking() const { return my_ranking; }

QJsonObject User::toJsonObject() const
{
    QJsonObject json;
    json["username"] = my_username;
    json["password"] = my_password;
    json["firstName"] = my_firstName;
    json["lastName"] = my_lastName;
    json["birthDate"] = my_birthDate.toString(Qt::ISODate);
    json["profilePicturePath"] = my_profilePicturePath;
    json["lastScore"] = my_lastScore;
    json["bestScore"] = my_bestScore;
    json["ranking"] = my_ranking;
    return json;
}


User User::fromJsonObject(const QJsonObject &json)
{
    QString username = json["username"].toString();
    QString password = json["password"].toString();
    QString firstName = json["firstName"].toString();
    QString lastName = json["lastName"].toString();
    QDate birthDate = QDate::fromString(json["birthDate"].toString(), Qt::ISODate);
    QString profilePicturePath = json["profilePicturePath"].toString();
    int lastScore = json["lastScore"].toInt();
    int bestScore = json["bestScore"].toInt();
    int ranking = json["ranking"].toInt();

    return User(username, password, firstName, lastName, birthDate, profilePicturePath, lastScore, bestScore,ranking);
}

void User::updateScore(int newScore)
{
    my_lastScore = newScore;

    if (newScore > my_bestScore)
    {
        my_bestScore = newScore;
    }
}




