#ifndef GESTIONNAIRE_PASSWORD_H
#define GESTIONNAIRE_PASSWORD_H

#include <QMainWindow>

namespace Ui {
class Gestionnaire_Password;
}

class Gestionnaire_Password : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionnaire_Password(QWidget *parent = nullptr);
    ~Gestionnaire_Password();
    void InsertIntoTableWidgetRow(QString, QString);

private:
    Ui::Gestionnaire_Password *ui;
};

#endif // GESTIONNAIRE_PASSWORD_H
