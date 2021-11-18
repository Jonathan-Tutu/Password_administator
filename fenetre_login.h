#ifndef FENETRE_LOGIN_H
#define FENETRE_LOGIN_H

#include <QMainWindow>

#include "bdd.h"
#include "gestionnaire_password.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Fenetre; }
QT_END_NAMESPACE

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = nullptr);
    ~Fenetre();
    void showhide_password();
    void Connexion();

private:

    Gestionnaire_Password *fen_log;
    BDD bdd;
    Ui::Fenetre *ui;
};
#endif // FENETRE_LOGIN_H
