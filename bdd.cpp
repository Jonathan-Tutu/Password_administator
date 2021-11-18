#include "bdd.h"
#include "qtbcrypt.h"

BDD::BDD()
{
    // Création du pepper
    pepper = "Nqsiu9,ls$";
}

bool BDD::connexion_BDD()
{
    // Initialisation des paramètres de la connexion via ODBC sur la base de données sauvegarde_password
    dbase = QSqlDatabase::addDatabase("QODBC");
    QStrCnxDatabase = QString("DRIVER={MySQL ODBC 8.0 ANSI Driver};Server Name=")+QString("127.0.0.1")+QString(";Database=sauvegardepassword;UID=root;PWD="); //Il nous faut un connector ODBC
    dbase.setDatabaseName(QStrCnxDatabase);

    if (dbase.open()) {
        qDebug() << "Connecté à la base de donnée";
    }
    else {

        QMessageBox wrong_password(QMessageBox::Warning,"Warning", "La base de donnée n'est pas accessible \n" + dbase.lastError().text());
        wrong_password.exec();
    }

    return dbase.open();
}

void BDD::deconnexion_BDD()
{
    dbase.close();
}

void BDD::password_gen(QString password)
{
    salt = QtBCrypt::generateSalt();
    QString hashedPassword = QtBCrypt::hashPassword(password, salt);
    hashedPassword = QtBCrypt::addPepper(hashedPassword, pepper);
    insertion_BDD_account(hashedPassword, salt);
}


QString BDD::password_verif(QString password, QString salt)
{
    QString hashedPassword = QtBCrypt::hashPassword(password, salt);
    hashedPassword = QtBCrypt::addPepper(hashedPassword, pepper);

    return hashedPassword;
}

void BDD::insertion_BDD_accountpassword(QString, QString, QString) //Compte des sites
{

}

bool BDD::isvide()
{
    bool isempty = false;
    QSqlQuery emptyQuery("select count(*) from account");
    while(emptyQuery.next())
    {
        if(emptyQuery.value(0).toInt() != 0)
        {
            isempty = false;
        }
        else
        {
            isempty = true;
        }
    }

    return isempty;
}

void BDD::insertion_BDD_account(QString hashedpassword, QString salt) //Mot de passe maitre
{
    //Préparation de la requête SQL
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO account (Password, salt)"
                        "VALUES (:Password, :salt)");
    insertQuery.bindValue(":Password", hashedpassword);
    insertQuery.bindValue(":salt", salt);

    //Envoie
    if(insertQuery.exec())
    {
        qDebug() << "La requête à été éxecuté et la donnée à été insérée " ;
    }
    else
    {
        qDebug() << "Error : " + insertQuery.lastError().text();
    }
}

bool BDD::verificationExistant(QString hashedpassword)
{
    QString passwordFromDB;
    QString salt;

    QSqlQuery passRequest("SELECT password, salt FROM account");
    while (passRequest.next())
    {
        passwordFromDB = passRequest.value(0).toString();
        salt = passRequest.value(1).toString();
    }

   return (passwordFromDB == (password_verif(hashedpassword, salt))); //Temps moyen d'éxecution 0.73s (mesuré avec time.h - clock)
}

BDD::~BDD()
{

}




