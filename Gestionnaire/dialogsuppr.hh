#ifndef DIALOGSUPPR_HH
#define DIALOGSUPPR_HH

#include <QDialog>
#include <cstdio>
#include <iostream>

///class DialogAjout, inheriting of class QDialog
namespace Ui {
    class DialogSuppr;
}

class DialogSuppr : public QDialog {
    Q_OBJECT
public:
    DialogSuppr(QWidget *parent = 0);
    ~DialogSuppr();
    std::string getTitle();
    std::string getCat();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogSuppr *ui;
    std::string _title;
    std::string _categorie;

private slots:
    void on_pbAnnuler_clicked();
    void on_pbValider_clicked();
    void on_comboBox_activated(QString );
};

#endif // DIALOGSUPPR_HH
