#ifndef MASTER_PASSWORD_CREATION_H
#define MASTER_PASSWORD_CREATION_H

#include <QDialog>
#include <QToolTip>

#include "bdd.h"
#include "fenetre_login.h"

namespace Ui {
class Master_Password_Creation;
}

class Master_Password_Creation : public QDialog
{
    Q_OBJECT

public:
    explicit Master_Password_Creation(QWidget *parent = nullptr);
    ~Master_Password_Creation();
    void showhide_password();
    void Valider();
    void password_score();

private:
    BDD bdd;
    Ui::Master_Password_Creation *ui;

    int score;
    Fenetre *login;

};

#endif // MASTER_PASSWORD_CREATION_H
