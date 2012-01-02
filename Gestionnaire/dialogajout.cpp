#include "dialogajout.h"
#include "ui_dialogajout.h"
#include <fstream>
#include <iostream>

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

///function getTitle whoe return the title of the new Document.
std::string DialogAjout::getTitle()
{
    return _title;
}

///function getCat who return the categorie of the new Document.
std::string DialogAjout::getCat()
{
    return _categorie;
}

///function sauvegarde in DialogAjout
void DialogAjout::sauvegarde()
{
    std::ofstream fichier;
    std::string name = "../Elements/";
    if (ui->comboBox->currentText() == "Manga")
    {
        name += _myManga.getTitle();
        name += ".txt";
        ///open a file in writing
        fichier.open(name.c_str(), std::ios::trunc);
        if (fichier)
        {
            ///insert lines in the file opened
            fichier << "Titre: " << _myManga.getTitle() << std::endl;
            fichier << "Auteur: " << _myManga.getAuthor() << std::endl;
            fichier << "Editeur: " << _myManga.getEditor() << std::endl;
            fichier << "Type: " << _myManga.getType() << std::endl;
            ///close the file
            fichier.close();
        }
        else
        {
            std::cerr << "Fichier introuvable!!!" << std::endl;
        }
        _title = _myManga.getTitle();
        _categorie = "Manga";
    }
    else if (ui->comboBox->currentText() == "Comic")
    {
        name += _myComic.getTitle();
        name += ".txt";
        ///open a file in writing
        fichier.open(name.c_str(), std::ios::trunc);
        if (fichier)
        {
            ///insert lines in the file opened
            fichier << "Titre: " << _myComic.getTitle() << std::endl;
            fichier << "Auteur: " << _myComic.getAuthor() << std::endl;
            fichier << "Editeur: " << _myComic.getEditor() << std::endl;
            ///close the file
            fichier.close();
        }
        else
        {
            std::cerr << "Fichier introuvable!!!" << std::endl;
        }
        _title = _myComic.getTitle();
        _categorie = "Comic";
    }
    else if (ui->comboBox->currentText() == "Roman")
    {
        name += _myRoman.getTitle();
        name += ".txt";
        ///open a file in writing
        fichier.open(name.c_str(), std::ios::trunc);
        if (fichier)
        {
            ///insert lines in the file opened
            fichier << "Titre: " << _myRoman.getTitle() << std::endl;
            fichier << "Auteur: " << _myRoman.getAuthor() << std::endl;
            fichier << "Editeur: " << _myRoman.getEditor() << std::endl;
            ///close the file
            fichier.close();
        }
        else
        {
            std::cerr << "Fichier introuvable!!!" << std::endl;
        }
        _title = _myRoman.getTitle();
        _categorie = "Roman";
    }
    else if (ui->comboBox->currentText() == "Article")
    {
        name += _myArticle.getTitle();
        name += ".txt";
        ///open a file in writing
        fichier.open(name.c_str(), std::ios::trunc);
        if (fichier)
        {
            ///insert lines in the file opened
            fichier << "Titre: " << _myArticle.getTitle() << std::endl;
            fichier << "Auteur: " << _myArticle.getAuthor() << std::endl;
            fichier << "Thème: " << _myArticle.getTheme() << std::endl;
            fichier << "Date de parution: "<< _myArticle.getDateParution() <<std::endl;
            ///close the file
            fichier.close();
        }
        else
        {
            std::cerr << "Fichier introuvable!!!" << std::endl;
        }
        _title = _myArticle.getTitle();
        _categorie = "Article";
    }
}

///function activated by the UI
void DialogAjout::on_pbCancel_clicked()
{
    this->close();
}

///function activated by the UI
void DialogAjout::on_pbOk_clicked()
{
    sauvegarde();
    this->close();
}

/**function activated by the UI
  this function select the lines to enter when the good document-type is selected**/
void DialogAjout::on_comboBox_activated(QString name)
{
    if (name == "Choisir le type de document")
    {
        ///hide all the areas
        ui->leTitle->hide();
        ui->leAuthor->hide();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->hide();
        ui->leType->hide();
    }
    else if (name == "Manga")
    {
        ///show the manga's areas
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->show();
    }
    else if (name == "Comic")
    {
        ///show the comic's areas
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->hide();
    }
    else if (name == "Roman")
    {
        ///show the rmoan's areas
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->hide();
        ui->leDateParution->hide();
        ui->leEditor->show();
        ui->leType->hide();
    }
    else if (name == "Article")
    {
        ///show the article's areas
        ui->leTitle->show();
        ui->leAuthor->show();
        ui->leTheme->show();
        ui->leDateParution->show();
        ui->leEditor->hide();
        ui->leType->hide();
    }
}

///function who register the title
void DialogAjout::on_leTitle_editingFinished()
{
    if (ui->comboBox->currentText() == "Manga")
    {
        _myManga.setTitle(ui->leTitle->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Comic")
    {
        _myComic.setTitle(ui->leTitle->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Roman")
    {
        _myRoman.setTitle(ui->leTitle->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Article")
    {
        _myArticle.setTitle(ui->leTitle->text().toStdString());
    }
}

///function who register the author
void DialogAjout::on_leAuthor_editingFinished()
{
    if (ui->comboBox->currentText() == "Manga")
    {
        _myManga.setAuthor(ui->leAuthor->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Comic")
    {
        _myComic.setAuthor(ui->leAuthor->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Roman")
    {
        _myRoman.setAuthor(ui->leAuthor->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Article")
    {
        _myArticle.setAuthor(ui->leAuthor->text().toStdString());
    }
}

///function who register the theme
void DialogAjout::on_leTheme_editingFinished()
{
    _myArticle.setTheme(ui->leTheme->text().toStdString());
}

///function who register the date of parution
void DialogAjout::on_leDateParution_editingFinished()
{
    _myArticle.setDateParution(ui->leDateParution->text().toStdString());
}

///function who register the editor
void DialogAjout::on_leEditor_editingFinished()
{
    if (ui->comboBox->currentText() == "Manga")
    {
        _myManga.setEditor(ui->leEditor->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Comic")
    {
        _myComic.setEditor(ui->leEditor->text().toStdString());
    }
    else if (ui->comboBox->currentText() == "Roman")
    {
        _myRoman.setEditor(ui->leEditor->text().toStdString());
    }
}

///function who register the type
void DialogAjout::on_leType_editingFinished()
{
    _myManga.setType(ui->leType->text().toStdString());
}
