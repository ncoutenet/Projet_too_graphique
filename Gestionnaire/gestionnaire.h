#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <QMainWindow>
#include <vector>
#include <string>

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
    void on_actionQuitter_triggered();

    void on_pbAjout_clicked();

private:
    Ui::Gestionnaire *ui;
    std::vector<std::string> _listMangas;
    std::vector<std::string> _listComics;
    std::vector<std::string> _listRomans;
    std::vector<std::string> _listArticles;
};

#endif // GESTIONNAIRE_H
