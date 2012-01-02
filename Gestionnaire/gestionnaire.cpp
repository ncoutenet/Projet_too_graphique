#include "gestionnaire.h"
#include "ui_gestionnaire.h"

Gestionnaire::Gestionnaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestionnaire)
{
    ui->setupUi(this);
    _initialisation();
    for(int i = 0; i < 7; i++)
        ui->tableWidget->setColumnWidth(i, 141);
}

Gestionnaire::~Gestionnaire()
{
    delete ui;
}

///function _suppression(std::string title, std::string categ) (whitch is private) for deleting a document
void Gestionnaire::_suppression(std::string title, std::string categ)
{
    unsigned int i;
    bool trouve = false;

    if (categ == "Manga")
    {
        i = 0;

        while ((!trouve) && (i < _listMangas.size()))
        {
            if (title == _listMangas.at(i))
            {
                trouve = true;
                _listMangas.erase(_listMangas.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }
    else if (categ == "Comic")
    {
        i = 0;

        while ((!trouve) && (i < _listComics.size()))
        {
            if (title == _listComics.at(i))
            {
                trouve = true;
                _listComics.erase(_listComics.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }
    else if (categ == "Roman")
    {
        i = 0;

        while ((!trouve) && (i < _listRomans.size()))
        {
            if (title == _listRomans.at(i))
            {
                trouve = true;
                _listRomans.erase(_listRomans.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }
    else if (categ == "Article")
    {
        i = 0;

        while ((!trouve) && (i < _listArticles.size()))
        {
            if (title == _listArticles.at(i))
            {
                trouve = true;
                _listArticles.erase(_listArticles.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }
    _sauvegarde();
}

///function on_actionQuitter_triggered() for waiting a clic on the menu 'Quitter'
void Gestionnaire::on_actionQuitter_triggered()
{
    QCoreApplication::quit();
}

///function on_pbAjout_clicked() for waiting a clic on the button 'Ajouter...'
void Gestionnaire::on_pbAjout_clicked()
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
    _sauvegarde();
    _initTab();
}

///function on_actionAjouter_triggered() for waiting a clic on the menu 'Ajouter...'
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
    _sauvegarde();
    _initTab();
}

///function on_pbSuppr_clicked() for waiting a clic on the button 'Supprimer...'
void Gestionnaire::on_pbSuppr_clicked()
{
    std::string name, categ;
    DialogSuppr *dialog = new DialogSuppr(this);

    dialog->exec();
    name = dialog->getTitle();
    categ = dialog->getCat();
    _suppression(name, categ);
    _initTab();
}

///function on_actionSupprimer_triggered() for waiting a clic on the menu 'Supprimer...'
void Gestionnaire::on_actionSupprimer_triggered()
{
    std::string name, categ;
    DialogSuppr *dialog = new DialogSuppr(this);

    dialog->exec();
    name = dialog->getTitle();
    categ = dialog->getCat();
    _suppression(name, categ);
    _initTab();
}

///function _export() (whitch is private) for converting the list of documents to html format
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

///function on_pbExpor_clicked() for waiting a clic on the button 'Exporter'
void Gestionnaire::on_pbExpor_clicked()
{
    _export();
}

///function on_actionExporter_triggered() for waiting a clic on the menu 'Exporter'
void Gestionnaire::on_actionExporter_triggered()
{
    _export();
}

///function _initialisation() (whitch is private) for initialising the vectors whitch are used for making lists of documents
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

    _initTab();
}

///function _razTable() (whitch is private) for deleting list of documents
void Gestionnaire::_razTable()
{
    if (ui->tableWidget->rowCount() > 0)
    {
        while (ui->tableWidget->rowCount() > 0)
        {
            ui->tableWidget->removeRow(0);
        }
    }
}

///function _razTable() (whitch is private) for initialising list of documents
void Gestionnaire::_initTab()
{
    _razTable();
    _affmangas();
    _affComics();
    _affRomans();
    _affArticles();
}

///function _affmangas() (whitch is private) for creating the list of mangas item by item
void Gestionnaire::_affmangas()
{
    QTableWidgetItem *titre;
    QTableWidgetItem *auteur;
    QTableWidgetItem *categorie;
    QTableWidgetItem *editeur;
    QTableWidgetItem *type;
    unsigned int i;
    std::string chemin;
    QString nom;
    std::ifstream manga;
    std::string ligne;

    for (i = 0; i < _listMangas.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listMangas[i];
        chemin += ".txt";
        ui->tableWidget->insertRow(0);
        manga.open(chemin.c_str());

        titre = new QTableWidgetItem();
        manga >> ligne;
        std::getline(manga, ligne);
        nom = nom.fromStdString(ligne);
        titre->setText(nom);
        auteur = new QTableWidgetItem();
        manga >> ligne;
        std::getline(manga, ligne);
        nom = nom.fromStdString(ligne);
        auteur->setText(nom);
        editeur = new QTableWidgetItem();
        manga >> ligne;
        std::getline(manga, ligne);
        nom = nom.fromStdString(ligne);
        editeur->setText(nom);
        type = new QTableWidgetItem();
        manga >> ligne;
        std::getline(manga, ligne);
        nom = nom.fromStdString(ligne);
        type->setText(nom);
        categorie = new QTableWidgetItem();
        nom = "Manga";
        categorie->setText(nom);

        manga.close();
        ui->tableWidget->setItem(0,0,titre);
        ui->tableWidget->setItem(0,1,auteur);
        ui->tableWidget->setItem(0,2,categorie);
        ui->tableWidget->setItem(0,5,editeur);
        ui->tableWidget->setItem(0,6,type);
    }
}

///function _affComics() (whitch is private) for creating the list of comics item by item
void Gestionnaire::_affComics()
{
    QTableWidgetItem *titre;
    QTableWidgetItem *auteur;
    QTableWidgetItem *categorie;
    QTableWidgetItem *editeur;
    unsigned int i;
    std::string chemin;
    QString nom;
    std::ifstream comic;
    std::string ligne;

    for (i = 0; i < _listComics.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listComics[i];
        chemin += ".txt";
        ui->tableWidget->insertRow(0);
        comic.open(chemin.c_str());

        titre = new QTableWidgetItem();
        comic >> ligne;
        std::getline(comic, ligne);
        nom = nom.fromStdString(ligne);
        titre->setText(nom);
        auteur = new QTableWidgetItem();
        comic >> ligne;
        std::getline(comic, ligne);
        nom = nom.fromStdString(ligne);
        auteur->setText(nom);
        editeur = new QTableWidgetItem();
        comic >> ligne;
        std::getline(comic, ligne);
        nom = nom.fromStdString(ligne);
        editeur->setText(nom);
        categorie = new QTableWidgetItem();
        nom = "Comic";
        categorie->setText(nom);

        comic.close();
        ui->tableWidget->setItem(0,0,titre);
        ui->tableWidget->setItem(0,1,auteur);
        ui->tableWidget->setItem(0,2,categorie);
        ui->tableWidget->setItem(0,5,editeur);
    }
}

///function _affRomans() (whitch is private) for creating the list of novels item by item
void Gestionnaire::_affRomans()
{
    QTableWidgetItem *titre;
    QTableWidgetItem *auteur;
    QTableWidgetItem *categorie;
    QTableWidgetItem *editeur;
    unsigned int i;
    std::string chemin;
    QString nom;
    std::ifstream roman;
    std::string ligne;

    for (i = 0; i < _listRomans.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listRomans[i];
        chemin += ".txt";
        ui->tableWidget->insertRow(0);
        roman.open(chemin.c_str());

        titre = new QTableWidgetItem();
        roman >> ligne;
        std::getline(roman, ligne);
        nom = nom.fromStdString(ligne);
        titre->setText(nom);
        auteur = new QTableWidgetItem();
        roman >> ligne;
        std::getline(roman, ligne);
        nom = nom.fromStdString(ligne);
        auteur->setText(nom);
        editeur = new QTableWidgetItem();
        roman >> ligne;
        std::getline(roman, ligne);
        nom = nom.fromStdString(ligne);
        editeur->setText(nom);
        categorie = new QTableWidgetItem();
        nom = "Roman";
        categorie->setText(nom);

        roman.close();
        ui->tableWidget->setItem(0,0,titre);
        ui->tableWidget->setItem(0,1,auteur);
        ui->tableWidget->setItem(0,2,categorie);
        ui->tableWidget->setItem(0,5,editeur);
    }

}

///function _affArticles() (whitch is private) for creating the list of articles item by item
void Gestionnaire::_affArticles()
{
    QTableWidgetItem *theme;
    QTableWidgetItem *date;
    QTableWidgetItem *titre;
    QTableWidgetItem *auteur;
    QTableWidgetItem *categorie;
    unsigned int i;
    std::string chemin;
    QString nom;
    std::ifstream article;
    std::string ligne;

    for (i = 0; i < _listArticles.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listArticles[i];
        chemin += ".txt";
        ui->tableWidget->insertRow(0);
        article.open(chemin.c_str());

        titre = new QTableWidgetItem();
        article >> ligne;
        std::getline(article, ligne);
        nom = nom.fromStdString(ligne);
        titre->setText(nom);
        auteur = new QTableWidgetItem();
        article >> ligne;
        std::getline(article, ligne);
        nom = nom.fromStdString(ligne);
        auteur->setText(nom);
        theme = new QTableWidgetItem();
        article >> ligne;
        std::getline(article, ligne);
        nom = nom.fromStdString(ligne);
        theme->setText(nom);
        date = new QTableWidgetItem();
        article >> ligne;
        article >> ligne;
        article >> ligne;
        std::getline(article, ligne);
        nom = nom.fromStdString(ligne);
        date->setText(nom);
        categorie = new QTableWidgetItem();
        nom = "Article";
        categorie->setText(nom);

        article.close();
        ui->tableWidget->setItem(0,0,titre);
        ui->tableWidget->setItem(0,1,auteur);
        ui->tableWidget->setItem(0,2,categorie);
        ui->tableWidget->setItem(0,3,theme);
        ui->tableWidget->setItem(0,4,date);
    }
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

void Gestionnaire::on_actionManuel_triggered()
{
    DialogManuel *dialog = new DialogManuel(this);
    dialog->exec();
}

///function on_actionPar_titre_triggered() for waiting a clic on the menu 'Par titre' for doing a sort by title
void Gestionnaire::on_actionPar_titre_triggered()
{
    qSort(_listMangas.begin(), _listMangas.end(), qGreater<std::string>());
    qSort(_listComics.begin(), _listComics.end(), qGreater<std::string>());
    qSort(_listRomans.begin(), _listRomans.end(), qGreater<std::string>());
    qSort(_listArticles.begin(), _listArticles.end(), qGreater<std::string>());
    _sauvegarde();
    _initTab();
}

///function _tri() (whitch is private) for make a sort of 4 vectors of authors and sorting too the vectors used for the list in the same order
void Gestionnaire::_tri(std::vector<std::string> &vect1, std::vector<std::string> &vect2, std::vector<std::string> &vect3, std::vector<std::string> &vect4)
{
    int i, j;
    int nbTri, nbMax, pMin;

    nbTri = vect1.size();
    nbMax = nbTri;


    for(i = 0; i < nbTri; i++)
    {
        pMin = 0;
        for(j = 1; j < nbMax; j++)
        {
            if(vect1[j] > vect1[pMin])
            {
                pMin = j;
            }
        }
        vect1.push_back(vect1[pMin]);
        vect1.erase(vect1.begin()+pMin);
        _listMangas.push_back(_listMangas[pMin]);
        _listMangas.erase(_listMangas.begin()+pMin);
        nbMax--;
    }

    nbTri = vect2.size();
    nbMax = nbTri;


    for(i = 0; i < nbTri; i++)
    {
        pMin = 0;
        for(j = 1; j < nbMax; j++)
        {
            if(vect2[j] > vect2[pMin])
            {
                pMin = j;
            }
        }
        vect2.push_back(vect2[pMin]);
        vect2.erase(vect2.begin()+pMin);
        _listComics.push_back(_listComics[pMin]);
        _listComics.erase(_listComics.begin()+pMin);
        nbMax--;
    }

    nbTri = vect2.size();
    nbMax = nbTri;

    for(i = 0; i < nbTri; i++)
    {
        pMin = 0;
        for(j = 1; j > nbMax; j++)
        {
            if(vect3[j] > vect3[pMin])
            {
                pMin = j;
            }
        }
        vect3.push_back(vect3[pMin]);
        vect3.erase(vect3.begin()+pMin);
        _listArticles.push_back(_listArticles[pMin]);
        _listArticles.erase(_listArticles.begin()+pMin);
        nbMax--;
    }

    nbTri = vect2.size();
    nbMax = nbTri;

    for(i = 0; i < nbTri; i++)
    {
        pMin = 0;
        for(j = 1; j < nbMax; j++)
        {
            if(vect4[j] > vect4[pMin])
            {
                pMin = j;
            }
        }
        vect4.push_back(vect4[pMin]);
        vect4.erase(vect4.begin()+pMin);
        _listRomans.push_back(_listRomans[pMin]);
        _listRomans.erase(_listRomans.begin()+pMin);
        nbMax--;
    }
}

///function _triAuthors initialising the 4 vectors necessaries for the function _tri
void Gestionnaire::_triAuthors()
{
    std::vector<std::string> vAutMang;
    std::vector<std::string> vAutCom;
    std::vector<std::string> vAutRom;
    std::vector<std::string> vAutArt;
    std::ifstream lecture;
    std::string chemin;
    std::string auteur;
    unsigned int i;

    for(i = 0; i < _listMangas.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listMangas[i];
        chemin += ".txt";
        lecture.open(chemin.c_str());
        if (lecture)
        {
            std::getline(lecture, auteur);
            lecture >> auteur;
            std::getline(lecture, auteur);
            vAutMang.push_back(auteur);
            lecture.close();
        }
        else
        {
            std::cerr<<"Fichier '../Elements/"<<_listMangas[i]<<".txt' introuvable!!!"<<std::endl;
        }
    }

    for(i = 0; i < _listComics.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listComics[i];
        chemin += ".txt";
        lecture.open(chemin.c_str());
        if (lecture)
        {
            std::getline(lecture, auteur);
            lecture >> auteur;
            std::getline(lecture, auteur);
            vAutCom.push_back(auteur);
            lecture.close();
        }
        else
        {
            std::cerr<<"Fichier '../Elements/"<<_listMangas[i]<<".txt' introuvable!!!"<<std::endl;
        }
    }

    for(i = 0; i < _listRomans.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listRomans[i];
        chemin += ".txt";
        lecture.open(chemin.c_str());
        if (lecture)
        {
            std::getline(lecture, auteur);
            lecture >> auteur;
            std::getline(lecture, auteur);
            vAutRom.push_back(auteur);
            lecture.close();
        }
        else
        {
            std::cerr<<"Fichier '../Elements/"<<_listMangas[i]<<".txt' introuvable!!!"<<std::endl;
        }
    }

    for(i = 0; i < _listArticles.size(); i++)
    {
        chemin = "../Elements/";
        chemin += _listArticles[i];
        chemin += ".txt";
        lecture.open(chemin.c_str());
        if (lecture)
        {
            std::getline(lecture, auteur);
            lecture >> auteur;
            std::getline(lecture, auteur);
            vAutArt.push_back(auteur);
            lecture.close();
        }
        else
        {
            std::cerr<<"Fichier '../Elements/"<<_listMangas[i]<<".txt' introuvable!!!"<<std::endl;
        }
    }

    _tri(vAutMang, vAutCom, vAutRom, vAutArt);
}

///function on_actionPar_auteur_triggered() for waiting a clic on the menu 'Par auteur' for doing a sort by author
void Gestionnaire::on_actionPar_auteur_triggered()
{
    _triAuthors();
    _sauvegarde();
    _initTab();
}
