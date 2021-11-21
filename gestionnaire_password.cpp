#include "gestionnaire_password.h"
#include "ui_gestionnaire_password.h"

#include <QStandardItemModel>
#include <QPushButton>
#include <QDebug>

Gestionnaire_Password::Gestionnaire_Password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestionnaire_Password)
{
    ui->setupUi(this);

    ui->table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->table->verticalHeader()->hide();
    ui->table->horizontalHeader()->hide();
    ui->table->setShowGrid(false);


    //On récupère les accounts depuis la base sql et on les ajoutes à la liste
    QLabel *MonLabel = new QLabel();
    QPixmap pix("C:\\Users\\Jonathan\\Desktop\\battle_netx56.png");
    MonLabel->setPixmap(pix);

    qDebug() << ui->table->rowCount();
    for(int i = 0; i < ui->table->rowCount(); i++)
    {
        QPushButton *delButton = new QPushButton("glaciusV2@gmail.com");
        ui->table->setCellWidget(i,1,delButton); //need pour les boutons

        ui->table->setColumnWidth(i,56);
        ui->table->setRowHeight(i,56); //0 = indice
        ui->table->setCellWidget(i,0,MonLabel); //need pour les boutons
    }



    ui->label->setPixmap(pix);

}

void Gestionnaire_Password::InsertIntoTableWidgetRow(QString path, QString mail_adress)
{

}

Gestionnaire_Password::~Gestionnaire_Password()
{
    delete ui;
}
