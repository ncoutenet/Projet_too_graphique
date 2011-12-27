#include "dialogajout.h"
#include "ui_dialogajout.h"

DialogAjout::DialogAjout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjout)
{
    ui->setupUi(this);
    ui->leTitle->hide();
    ui->leAuthor->hide();
    ui->leTheme->hide();
    ui->leDateParution->hide();
    ui->leEditor->hide();
    ui->leType->hide();
}

DialogAjout::~DialogAjout()
{
    delete ui;
}

void DialogAjout::on_pbCancel_clicked()
{
    this->close();
}

void DialogAjout::on_pbOk_clicked()
{
//sauvegarder ici le nouvel objet
    this->close();
}

void DialogAjout::on_comboBox_activated(QString name)
{
    if (name == "Choisir le type de document")
    {
        ui->leTitle->hide();
        ui->leAuthor->hide();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->hide();
        ui->leType->hide();
    }
    else if (name == "Manga")
    {
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->show();
    }
    else if (name == "Comic")
    {
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->hide();
    }
    else if (name == "Roman")
    {
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->hide();
    }
    else if (name == "Article")
    {
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->show();
        ui->leDateParution->show();
        ui->leEditor->hide();
        ui->leType->hide();
    }
}
