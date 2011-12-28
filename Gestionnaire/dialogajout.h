#ifndef DIALOGAJOUT_H
#define DIALOGAJOUT_H

#include <QDialog>
#include "manga.hh"
#include "roman.hh"
#include "article.hh"
#include "comic.hh"

namespace Ui {
    class DialogAjout;
}

class DialogAjout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjout(QWidget *parent = 0);
    ~DialogAjout();
    Manga getManga();
    Comic getComic();
    Roman getRoman();
    Article getArticle();

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
};

#endif // DIALOGAJOUT_H
