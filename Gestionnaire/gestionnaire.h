#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <QtAlgorithms>

#include "dialogajout.h"
#include "dialogsuppr.hh"
#include "dialogmanuel.hh"

namespace Ui {
    class Gestionnaire;
}

///class Gestionnaire, inheriting of class QMainWindow, it is the main window of the programme
class Gestionnaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionnaire(QWidget *parent = 0);
    ~Gestionnaire();

private slots:
    void on_pbExpor_clicked();
    void on_actionExporter_triggered();
    void on_actionSupprimer_triggered();
    void on_pbSuppr_clicked();
    void on_actionQuitter_triggered();

    void on_pbAjout_clicked();

    void on_actionAjouter_triggered();

    void on_actionManuel_triggered();

    void on_actionPar_titre_triggered();

    void on_actionPar_auteur_triggered();

private:
    Ui::Gestionnaire *ui;
    std::vector<std::string> _listMangas;
    std::vector<std::string> _listComics;
    std::vector<std::string> _listRomans;
    std::vector<std::string> _listArticles;
    void _export();
    void _initialisation();
    void _sauvegarde();
    void _affmangas();
    void _affComics();
    void _affRomans();
    void _affArticles();
    void _initTab();
    void _suppression(std::string, std::string);
    void _razTable();
    void _triAuthors();
    void _tri(std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&);
};

#endif // GESTIONNAIRE_H
