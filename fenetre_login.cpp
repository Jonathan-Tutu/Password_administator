#include "fenetre_login.h"
#include "ui_fenetre_login.h"

Fenetre::Fenetre(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::Fenetre)
{
    ui->setupUi(this);
    Fenetre::setWindowTitle("Login");
    ui->statusbar->showMessage("Ce gestionnaire est développé à but non lucratif par Jonathan");

    connect(ui->btn_show, &QPushButton::clicked, this, &Fenetre::showhide_password);
    connect(ui->btn_connexion, &QPushButton::clicked, this, &Fenetre::Connexion);

    //Si on appuie sur entrer sur les QLineEdit, ça appel la fonction connexion
    connect(ui->edit_pswd, &QLineEdit::returnPressed, this, &Fenetre::Connexion);
    connect(ui->edit_pswd_verif, &QLineEdit::returnPressed, this, &Fenetre::Connexion);
}

void Fenetre::showhide_password()
{
    if(ui->edit_pswd->echoMode() == QLineEdit::Password)
    {
        ui->edit_pswd->setEchoMode(QLineEdit::Normal);
        ui->edit_pswd_verif->setEchoMode(QLineEdit::Normal);
        ui->btn_show->setStyleSheet(" QPushButton {background-image: url('C:/Users/Jonathan/Desktop/Gestionnaire_MotDePasse - Copie/Images/Logo_Show_password.png');background-color: none; border: none;} \
                                      QPushButton:hover { background-image: url('C:/Users/Jonathan/Desktop/Gestionnaire_MotDePasse - Copie/Images/Logo_Show_password_b_w.png');}");
    }
    else
    {
        ui->edit_pswd->setEchoMode(QLineEdit::Password);
        ui->edit_pswd_verif->setEchoMode(QLineEdit::Password);
        ui->btn_show->setStyleSheet("QPushButton {background-image: url('C:/Users/Jonathan/Desktop/Gestionnaire_MotDePasse - Copie/Images/Logo_Show_password-inv.png');background-color: none; border: none;} \
                                     QPushButton:hover { background-image: url('C:/Users/Jonathan/Desktop/Gestionnaire_MotDePasse - Copie/Images/Logo_Show_password-inv_b_w.png');}");
        //ui->btn_show->setStyleSheet("QPushButton:hover { background-image: url('C:/Users/Jonathan/Desktop/Gestionnaire_MotDePasse - Copie/Images/Logo_Show_password_b_w.png';}");
    }
}

void Fenetre::Connexion()
{
    if(!ui->edit_pswd->text().compare(ui->edit_pswd_verif->text()))
    {
        if(bdd.verificationExistant(ui->edit_pswd->text()))
        {
            qDebug() << "Mot de passe valide";
            Fenetre::hide();
            fen_log = new Gestionnaire_Password();
            fen_log->show();
        }
        else
        {
            QMessageBox wrong_password(QMessageBox::Warning,"Warning", "Le mot de passe saisis est invalide");
            wrong_password.exec();
        }
    }
    else
    {
        QMessageBox wrong_password(QMessageBox::Warning,"Warning", "Les deux mots de passes ne correspondent pas");
        wrong_password.exec();
    }
}

Fenetre::~Fenetre()
{
    delete ui;
}

