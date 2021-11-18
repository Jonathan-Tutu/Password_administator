#ifndef BDD_H
#define BDD_H

#include "qtbcrypt.h"

#include <QMessageBox>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>


class BDD
{
public:
    BDD();
    ~BDD();
    void password_gen(QString);
    QString password_verif(QString, QString);
    bool isvide();
    bool connexion_BDD();
    void deconnexion_BDD();
    void insertion_BDD_accountpassword(QString, QString, QString);
    void insertion_BDD_account(QString, QString);
    bool verificationExistant(QString);

private:
    QSqlDatabase dbase;
    QString QStrCnxDatabase;

    QString pepper;
    QString salt;
};

#endif // BDD_HZ
