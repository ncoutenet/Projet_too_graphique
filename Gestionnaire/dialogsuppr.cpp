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

///function getTitle who return the title of the file to delete
std::string DialogSuppr::getTitle()
{
    return _title;
}

///function getCat who return the type of the file to delete
std::string DialogSuppr::getCat()
{
    return _categorie;
}

/**function activated by UI
  this function select the file and remove it from the HDD**/
void DialogSuppr::on_pbValider_clicked()
{
    std::string name, file;
    int i;
    if (ui->leTitre->text() != NULL)
    {
        name = ui->leTitre->text().toStdString();
        _title = name;

        file = "../Elements/";
        file += name.c_str();
        file += ".txt";

        ///remove the file
        i = remove(file.c_str());

        if(i != 0)
        {
            std::cerr<<"Fichier '"<<name<<"' introuvable!!!"<<std::endl;
        }
    }
    if (ui->comboBox->currentText() != "Choisir le type de document")
    {
        _categorie = ui->comboBox->currentText().toStdString();
    }
    this->close();
}

///function activated by UI
void DialogSuppr::on_pbAnnuler_clicked()
{
    this->close();
}

/**function activated by the UI
  this function select the lines to enter when the good document-type is selected**/
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
