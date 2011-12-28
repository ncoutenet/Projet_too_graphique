#ifndef DIALOGSUPPR_HH
#define DIALOGSUPPR_HH

#include <QDialog>

namespace Ui {
    class DialogSuppr;
}

class DialogSuppr : public QDialog {
    Q_OBJECT
public:
    DialogSuppr(QWidget *parent = 0);
    ~DialogSuppr();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogSuppr *ui;

private slots:
    void on_pbAnnuler_clicked();
    void on_pbValider_clicked();
};

#endif // DIALOGSUPPR_HH
