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
    std::string name;
    std::string categ;
    DialogAjout *dialog = new DialogAjout(this);
    dialog->exec();

    if (categ == "Manga")
    {
        _listMangas.push_back(name);
    }
    else if (categ == "Comic")
    {
        _listComics.push_back(name);
    }
    else if (categ == "Roman")
    {
        _listRomans.push_back(name);
    }
    else if (categ == "Article")
    {
        _listArticles.push_back(name);
    }
}

void Gestionnaire::on_actionAjouter_triggered()
{
    std::string name;
    std::string categ;
    DialogAjout *dialog = new DialogAjout(this);
    dialog->exec();
    name = dialog->getTitle();
    categ = dialog->getCat();

    if (categ == "Manga")
    {
        _listMangas.push_back(name);
    }
    else if (categ == "Comic")
    {
        _listComics.push_back(name);
    }
    else if (categ == "Roman")
    {
        _listRomans.push_back(name);
    }
    else if (categ == "Article")
    {
        _listArticles.push_back(name);
    }
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

void Gestionnaire::_initialisation()
{
    std::string ligne;
    std::ifstream manga("../Sources/listMangas.txt");
    if (manga)
    {
        while(getline(manga, ligne))
        {
            _listMangas.push_back(ligne);
        }
    }
    else
    {
        std::cerr<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    manga.close();

    std::ifstream comic("../Sources/listComics.txt");
    if (comic)
    {
        while(getline(comic, ligne))
        {
            _listComics.push_back(ligne);
        }
    }
    else
    {
        std::cerr<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    comic.close();

    std::ifstream roman("../Sources/listRomans.txt");
    if (roman)
    {
        while(getline(roman, ligne))
        {
            _listRomans.push_back(ligne);
        }
    }
    else
    {
        std::cerr<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    roman.close();

    std::ifstream article("../Sources/listArticles.txt");
    if (article)
    {
        while(getline(article, ligne))
        {
            _listArticles.push_back(ligne);
        }
    }
    else
    {
        std::cerr<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    article.close();
}

///function _sauvegarde() (whitch is private) for saving the lists of documents
void Gestionnaire::_sauvegarde()
{
    unsigned int i;
    std::string ligne;
    std::ofstream fichier("../Sources/listArticles.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listArticles.size(); i++)
        {
            ligne = _listArticles.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listRomans.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listRomans.size(); i++)
        {
            ligne = _listRomans.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listComics.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listComics.size(); i++)
        {
            ligne = _listComics.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listMangas.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listMangas.size(); i++)
        {
            ligne = _listMangas.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }
}
