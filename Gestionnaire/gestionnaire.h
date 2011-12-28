#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <fstream>

namespace Ui {
    class Gestionnaire;
}

class Gestionnaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionnaire(QWidget *parent = 0);
    ~Gestionnaire();
    void initGestionnaire();

private slots:
    void on_pbExpor_clicked();
    void on_actionExporter_triggered();
    void on_actionSupprimer_triggered();
    void on_pbSuppr_clicked();
    void on_actionQuitter_triggered();

    void on_pbAjout_clicked();

    void on_actionAjouter_triggered();

private:
    Ui::Gestionnaire *ui;
    std::vector<std::string> _listMangas;
    std::vector<std::string> _listComics;
    std::vector<std::string> _listRomans;
    std::vector<std::string> _listArticles;
    void _export();
};

#endif // GESTIONNAIRE_H
