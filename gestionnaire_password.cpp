#include "gestionnaire_password.h"
#include "ui_gestionnaire_password.h"

Gestionnaire_Password::Gestionnaire_Password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestionnaire_Password)
{
    ui->setupUi(this);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->horizontalHeader()->setVisible(false);
}

Gestionnaire_Password::~Gestionnaire_Password()
{
    delete ui;
}
