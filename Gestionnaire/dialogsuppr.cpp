#include "dialogsuppr.hh"
#include "ui_dialogsuppr.h"

DialogSuppr::DialogSuppr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSuppr)
{
    ui->setupUi(this);
    ui->linstruction->hide();
    ui->leTitre->hide();
}

DialogSuppr::~DialogSuppr()
{
    delete ui;
}

void DialogSuppr::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

std::string DialogSuppr::getTitle()
{
    return _title;
}

std::string DialogSuppr::getCat()
{
    return _categorie;
}

void DialogSuppr::on_pbValider_clicked()
{
    std::string name, file;
    if (ui->leTitre->text() != NULL)
    {
        name = ui->leTitre->text().toStdString();
        _title = name;

        file = " rm ../Elements/";
        file += name;
        file += ".txt";

        system(file.c_str());
    }

    if (ui->comboBox->currentText() != "Choisir le type de document")
    {
        _categorie = ui->comboBox->currentText().toStdString();
    }

    this->close();
}

void DialogSuppr::on_pbAnnuler_clicked()
{
    this->close();
}

void DialogSuppr::on_comboBox_activated(QString )
{
    if (ui->comboBox->currentText() == "Choisir le type de document")
    {
        ui->linstruction->hide();
        ui->leTitre->hide();
    }
    else
    {
        ui->linstruction->show();
        ui->leTitre->show();
    }
}
