#include "dialogmanuel.hh"
#include "ui_dialogmanuel.h"

DialogManuel::DialogManuel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManuel)
{
    ui->setupUi(this);
}

DialogManuel::~DialogManuel()
{
    delete ui;
}

void DialogManuel::changeEvent(QEvent *e)
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
