#include "master_password_creation.h"
#include "ui_master_password_creation.h"

Master_Password_Creation::Master_Password_Creation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Master_Password_Creation)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar->setTextVisible(false);

    connect(ui->edit_pswd, &QLineEdit::textChanged, this, &Master_Password_Creation::password_score);
    connect(ui->btn_show, &QPushButton::pressed, this, &Master_Password_Creation::showhide_password);
    connect(ui->btn_valid, &QPushButton::clicked,this, &Master_Password_Creation::Valider);

    okRegMaj = true;
    okRegMin = true;
    okRegNum = true;
    okRegMaj = true;

    score = 0;
    if(bdd.connexion_BDD())
    {
        if(!bdd.isvide())
        {
            login = new Fenetre();
            login->show();
        }
        else
        {
            Master_Password_Creation::show();
        }
    }
}

void Master_Password_Creation::showhide_password()
{
    if(ui->edit_pswd->echoMode() == QLineEdit::Password)
    {
        ui->edit_pswd->setEchoMode(QLineEdit::Normal);
        ui->edit_pswd_verif->setEchoMode(QLineEdit::Normal);
        ui->btn_show->setStyleSheet(" QPushButton {background-image: url('../Images/Logo_Show_password.png'); background-color: none; border: none;} \
                                      QPushButton:hover { background-image: url('../Images/Logo_Show_password_b_w.png');}");
    }
    else
    {
        ui->edit_pswd->setEchoMode(QLineEdit::Password);
        ui->edit_pswd_verif->setEchoMode(QLineEdit::Password);
        ui->btn_show->setStyleSheet("QPushButton {background-image: url('../Images/Logo_Show_password-inv.png');background-color: none; border: none;} \
                                     QPushButton:hover { background-image: url('../Images/Logo_Show_password-inv_b_w.png');}");
    }
}

void Master_Password_Creation::Valider()
{
    QRegExp regmdp("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");

    if(ui->edit_pswd->text().contains(regmdp))
    {
        bdd.password_gen(ui->edit_pswd->text());
        Master_Password_Creation::hide();
        login = new Fenetre();
        login->show();
    }
    else
    {
        ui->progressBar->setValue(50);
        QMessageBox wrong_password(QMessageBox::Warning,"Warning", "Le mot de passe saisi ne correspond pas aux stantards indiqués");
        wrong_password.exec();
    }
}

void Master_Password_Creation::password_score()
{


    //Méthode à modifié dans le futur



    QString password = ui->edit_pswd->text();
 /* A faire fonctionner */
    QRegExp reg_maj("[A-Z]");
    QRegExp reg_min("[a-z]");
    QRegExp reg_chiffre("[0-9]");
    QRegExp reg_spe("[#?!@$%^&*-]");



    if(password.size() == 8)
        score += 1;
    if(password.size() == 11)
        score +=1;
    if(password.contains(reg_maj) && okRegMaj != false)
    {
        score +=1;
        okRegMaj = false;
    }
    if(password.contains(reg_min) && okRegMin != false)
    {
        score +=1;
        okRegMin = false;
    }
    if(password.contains(reg_chiffre) && okRegNum != false)
    {
        score +=1;
        okRegNum = false;
    }
    if(password.contains(reg_spe) && okRegSym != false)
    {
        score +=1;
        okRegSym = false;
    }

    switch(score)
    {
        case 1:
        {
            ui->progressBar->setValue(16);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:red; border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white;}");
            break;
        }
        case 2:
        {
            ui->progressBar->setValue(33);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:orange; border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white;}");
            break;
        }
        case 3:
        {
            ui->progressBar->setValue(49);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:yellow;border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white;}");
            break;
        }
        case 4:
        {
            ui->progressBar->setValue(65);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:green; border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white;}");
            break;
        }
        case 5:
        {
            ui->progressBar->setValue(81);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:blue;border: 1px solid gray; border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white;}");
            break;
        }
        case 6:
        {
            ui->progressBar->setValue(100);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color:purple;border: 1px solid gray; border-radius: 7px;} QProgressBar:horizontal { border: 1px solid gray; border-radius: 7px; background: white; padding: 1px;}");
            break;
        }
    }
    }

Master_Password_Creation::~Master_Password_Creation()
{
    delete ui;
}
