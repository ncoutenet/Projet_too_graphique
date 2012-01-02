#ifndef DIALOGAJOUT_H
#define DIALOGAJOUT_H

#include <QDialog>
#include "manga.hh"
#include "roman.hh"
#include "article.hh"
#include "comic.hh"

///namespace ui is generate by qt for make the code lighter
namespace Ui {
    class DialogAjout;
}

///class DialogAjout, inheriting of class QDialog
class DialogAjout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjout(QWidget *parent = 0);
    ~DialogAjout();
    void sauvegarde();
    std::string getTitle();
    std::string getCat();

private slots:
    void on_pbCancel_clicked();

    void on_pbOk_clicked();

    void on_comboBox_activated(QString );

    void on_leTitle_editingFinished();

    void on_leAuthor_editingFinished();

    void on_leTheme_editingFinished();

    void on_leDateParution_editingFinished();

    void on_leEditor_editingFinished();

    void on_leType_editingFinished();

private:
    Ui::DialogAjout *ui;
    Manga _myManga;
    Comic _myComic;
    Roman _myRoman;
    Article _myArticle;
    std::string _title;
    std::string _categorie;
};

#endif // DIALOGAJOUT_H
