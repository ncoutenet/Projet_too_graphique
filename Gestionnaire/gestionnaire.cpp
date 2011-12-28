#include "gestionnaire.h"
#include "ui_gestionnaire.h"
#include "dialogajout.h"

Gestionnaire::Gestionnaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestionnaire)
{
    ui->setupUi(this);
}

Gestionnaire::~Gestionnaire()
{
    delete ui;
}

void Gestionnaire::initGestionnaire()
{

}

void Gestionnaire::on_actionQuitter_triggered()
{
    QCoreApplication::quit();
}

void Gestionnaire::on_pbAjout_clicked()
{
    DialogAjout *dialog = new DialogAjout(this);
    dialog->exec();
}

void Gestionnaire::on_actionAjouter_triggered()
{
    DialogAjout *dialog = new DialogAjout(this);
    dialog->exec();
}
