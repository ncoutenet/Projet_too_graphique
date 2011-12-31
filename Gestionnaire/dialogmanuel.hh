#ifndef DIALOGMANUEL_HH
#define DIALOGMANUEL_HH

#include <QDialog>

namespace Ui {
    class DialogManuel;
}

class DialogManuel : public QDialog {
    Q_OBJECT
public:
    DialogManuel(QWidget *parent = 0);
    ~DialogManuel();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogManuel *ui;
};

#endif // DIALOGMANUEL_HH
