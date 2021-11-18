#include "master_password_creation.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/NotoSerif-Bold.ttf"); //Permet d'importer la police (à vérifier)

    Master_Password_Creation w;
    w.setFixedSize(452,278);
    return a.exec();
}
