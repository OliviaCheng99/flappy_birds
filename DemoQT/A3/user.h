#pragma once

#ifndef USER_H
#define USER_H


#include <QString>
#include <QDate>
#include <QJsonObject>

class User
{
public:
    explicit User();
    explicit User(const QString &username,const QString &password,const QString &firstName,const QString &lastName,const QDate &birthDate,const QString &profilePicturePath,qint32 lastScore = 0,
                  qint32 bestScore = 0, qint32 ranking = 0);

    QString getUsername() const;
    QString getPassword() const;
    QString getFirstName() const;
    QString getLastName() const;
    QDate getBirthDate() const;
    QString getProfilePicturePath() const;
    qint32 getLastScore() const;
    qint32 getBestScore() const;
    qint32 getRanking() const;
    void setRanking(qint32 ranking);


    QJsonObject toJsonObject() const;
    static User fromJsonObject(const QJsonObject &json);
    void updateScore(qint32 newScore);

private:
    QString my_username;
    QString my_password;
    QString my_firstName;
    QString my_lastName;
    QDate my_birthDate;
    QString my_profilePicturePath;
    qint32 my_lastScore;
    qint32 my_bestScore;
    qint32 my_ranking;
};

#endif // USER_H



