#pragma once

#ifndef USER_H
#define USER_H


#include <QString>
#include <QDate>
#include <QJsonObject>

class User
{
public:
    explicit User(const QString &username,const QString &password,const QString &firstName,const QString &lastName,const QDate &birthDate,const QString &profilePicturePath);
    explicit User();

    QString getUsername() const;
    QString getPassword() const;
    QString getFirstName() const;
    QString getLastName() const;
    QDate getBirthDate() const;
    QString getProfilePicturePath() const;

    QJsonObject toJsonObject() const;
    static User fromJsonObject(const QJsonObject &json);

private:
    QString my_username;
    QString my_password;
    QString my_firstName;
    QString my_lastName;
    QDate my_birthDate;
    QString my_profilePicturePath;
};

#endif // USER_H



