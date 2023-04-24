#pragma once

#ifndef USER_H
#define USER_H


#include <QString>
#include <QDate>
#include <QJsonObject>

class User
{
public:
    explicit User(const QString &username,const QString &password,const QString &firstName,const QString &lastName,const QDate &birthDate,const QString &profilePicturePath,int lastScore = 0,
                  int bestScore = 0,int ranking = 0);

    QString getUsername() const;
    QString getPassword() const;
    QString getFirstName() const;
    QString getLastName() const;
    QDate getBirthDate() const;
    QString getProfilePicturePath() const;
    int getLastScore() const;
    int getBestScore() const;
    int getRanking() const;
    void setRanking(int ranking);


    QJsonObject toJsonObject() const;
    static User fromJsonObject(const QJsonObject &json);
    void updateScore(int newScore);

private:
    QString my_username;
    QString my_password;
    QString my_firstName;
    QString my_lastName;
    QDate my_birthDate;
    QString my_profilePicturePath;
    int my_lastScore;
    int my_bestScore;
    int my_ranking;
};

#endif // USER_H



