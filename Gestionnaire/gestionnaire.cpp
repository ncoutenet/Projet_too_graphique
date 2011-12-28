#include "gestionnaire.h"
#include "ui_gestionnaire.h"
#include "dialogajout.h"
#include "dialogsuppr.hh"

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

void Gestionnaire::on_pbSuppr_clicked()
{
    DialogSuppr *dialog = new DialogSuppr(this);
    dialog->exec();
}

void Gestionnaire::on_actionSupprimer_triggered()
{
    DialogSuppr *dialog = new DialogSuppr(this);
    dialog->exec();
}

void Gestionnaire::_export()
{
    std::string ligne;

    std::ofstream Ajout("../Pages/Liste_des_documents.html");
    if (Ajout)
    {
        Ajout << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" <<std::endl;
        Ajout << "    \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" <<std::endl;
        Ajout << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\">" <<std::endl;
        Ajout << "<head>" <<std::endl;
        Ajout << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" <<std::endl;
        Ajout << "<meta name=\"description\" content=\"Objet\" />" <<std::endl;
        Ajout << "<meta name=\"keywords\" content=\"xhtml,internet,too\" />" <<std::endl;
        Ajout << "<meta name=\"author\" content=\"none\" />" <<std::endl;
        Ajout << "<title>Liste des éléments:</title>" <<std::endl;
        Ajout << "</head>" <<std::endl;
        Ajout << "<body>" <<std::endl;
        Ajout << "<h1> Articles: </h1><br/>" <<std::endl;
        std::ifstream article("../Sources/listArticles.txt");
        while(getline(article, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Comics: </h1><br/>" <<std::endl;
        std::ifstream comic("../Sources/listComics.txt");
        while(getline(comic, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Mangas: </h1><br/>" <<std::endl;
        std::ifstream manga("../Sources/listMangas.txt");
        while(getline(manga, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Romans: </h1><br/>" <<std::endl;
        std::ifstream roman("../Sources/listRomans.txt");
        while(getline(roman, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "</body>" <<std::endl;
        Ajout << "</html>" <<std::endl;
    }
}

void Gestionnaire::on_pbExpor_clicked()
{
    _export();
}

void Gestionnaire::on_actionExporter_triggered()
{
    _export();
}
