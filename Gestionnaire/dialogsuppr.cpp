#include "dialogsuppr.hh"
#include "ui_dialogsuppr.h"

DialogSuppr::DialogSuppr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSuppr)
{
    ui->setupUi(this);
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

void DialogSuppr::on_pbValider_clicked()
{
    std::string name, file;

    name = ui->leTitre->text().toStdString();

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    system(file.c_str());

    this->close();
}

void DialogSuppr::on_pbAnnuler_clicked()
{
    this->close();
}
