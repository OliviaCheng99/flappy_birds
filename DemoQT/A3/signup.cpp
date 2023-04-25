#include "signup.h"
#include "ui_signup.h"
#include "appsettings.h"

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    connect(ui->picButton, &QPushButton::clicked, this, &SignUp::on_picButton_clicked);
}

SignUp::~SignUp()
{
    delete ui;
}


void SignUp::on_picButton_clicked()
{
    QString dir_Path = AppSettings::dirPath; // default user path
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "profile picture",
        dir_Path,
        tr("Images (*.png *.jpg)")
        );

    if (!imagePath.isEmpty())
    {
        // Store the image path
        // Extract file extension
        QFileInfo fileInfo(imagePath);
        QString fileExtension = fileInfo.suffix();

        // Get the username from the form
        QString username = ui->usernameLineEdit->text();

        // Check if the username is not empty
        if (username.isEmpty())
        {
            // Show a warning message to the user
            QMessageBox::warning(this, "Warning", "Please enter a username before selecting a profile picture.");
            return;
        }

        // Construct the new file name
        QString newFileName = username + "_profile_picture." + fileExtension;
        qDebug() << newFileName;

        // Construct the destination path
        QString destinationPath = AppSettings::dirPath + "/database/" + newFileName; // maybe here create an image cache dir

        qDebug() << imagePath;
        qDebug() << destinationPath;

        // Copy the file to the destination path
        if (QFile::copy(imagePath, destinationPath))
        {
            // Store the new file path
            this->profilePicturePath = destinationPath;
        }
        else
        {
            // Handle error if the file copy fails
            QMessageBox::warning(this, "Error", "Database crashes!");
            return;
        }

    }
}


void SignUp::on_buttonBox_accepted()
{
    //handle the sign form
    // check if user name(no repeated), passwprd valid, pic not bigger than 2m
    // if ok, store the data and go to the gameboard

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString profilePicturePath = this->profilePicturePath;
    QString firstname = ui->firstNameLineEdit->text();
    QString lastname = ui->lastNameLineEdit->text();
    QDate date = ui->dateOfBirthDateEdit->date();

    if (!isUsernameValid(username))
    {
        // Show an error message and return
        QMessageBox::warning(this, "Invalid Username", "The username is not unique.");
        return;

    }

    if (!isPwdValid(password))
    {
        // Show an error message and return
        QMessageBox::warning(this, "Invalid Password", "The password should consist of at least 8 characters "
                                                       "and contain at least one number, upper and lower case letters!");
        return;
    }

    if (!isImgSizeValid(profilePicturePath))
    {
        QMessageBox::warning(this, "Invalid Image Size", "The selected image is too large. Please choose an image smaller than 2MB.");
        return;
    }


    // all valid
    //store the user info to json file
    User new_user(username,password,firstname,lastname,date,profilePicturePath);
    this->saveUser(new_user);

    // then hide this sign window and swtich to the game board
    this->hide();
    emit setAccountInfo();
    emit showLoginWindow();

}


void SignUp::on_buttonBox_rejected()
{
    this->hide();
    emit showLoginWindow();

}


bool SignUp::isUsernameValid(const QString &username)
{
    // Load user data from JSON file
    QString userFilePath = AppSettings::dirPath +"/database/users.json";
    QFile userFile(userFilePath);
    if (!userFile.open(QIODevice::ReadOnly))
    {
        // Handle the error
        QMessageBox::critical(this, "Error", "An error occurred.");

    }

    QByteArray userFileData = userFile.readAll();
    userFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(userFileData);
    QJsonArray jsonArray = jsonDoc.array();

    // Iterate through users and check if the username already exists
    for (const QJsonValue &userValue : jsonArray)
    {
        QJsonObject userObject = userValue.toObject();
        if (userObject["username"].toString() == username)
        {
            return false;
        }
    }
    return true;
}


bool SignUp::isPwdValid(const QString &password)
{
    if (password.length() < 8)
    {
        return false;
    }

    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;

    for (const QChar &ch : password)
    {
        if (ch.isDigit())
        {
            hasDigit = true;
        }
        else if (ch.isUpper())
        {
            hasUpper = true;
        }
        else if (ch.isLower())
        {
            hasLower = true;
        }
    }

    return hasDigit && hasUpper && hasLower;
}


bool SignUp::isImgSizeValid(const QString &imagePath)
{
    QFile imageFile(imagePath);
    qint64 fileSize = imageFile.size();

    return fileSize <= 2 * 1024 * 1024;
}

void SignUp::saveUser(const User &user)
{
    // Read the existing JSON user file
    QString userFilePath = AppSettings::dirPath +"/database/users.json";
    QFile userFile(userFilePath);
    if (!userFile.open(QIODevice::ReadOnly))
    {
        // Handle the error
        QMessageBox::critical(this, "Error", "An error occurred.");

    }

    QByteArray userFileData = userFile.readAll();
    userFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(userFileData);
    QJsonArray jsonArray = jsonDoc.array();

    // Add the new user to the JSON array
    jsonArray.append(user.toJsonObject());

    // Save the updated JSON array to the file
    jsonDoc.setArray(jsonArray);
    userFileData = jsonDoc.toJson();

    if (!userFile.open(QIODevice::WriteOnly))
    {
        // Handle the error
        QMessageBox::critical(this, "Error", "An error occurred.");

    }

    userFile.write(userFileData);
    userFile.close();

}
