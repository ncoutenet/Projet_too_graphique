#ifndef DIALOGAJOUT_H
#define DIALOGAJOUT_H

#include <QDialog>

namespace Ui {
    class DialogAjout;
}

class DialogAjout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjout(QWidget *parent = 0);
    ~DialogAjout();

private slots:
    void on_pbCancel_clicked();

    void on_pbOk_clicked();

    void on_comboBox_activated(QString );

private:
    Ui::DialogAjout *ui;
};

#endif // DIALOGAJOUT_H
