#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <QMainWindow>

namespace Ui {
    class Gestionnaire;
}

class Gestionnaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionnaire(QWidget *parent = 0);
    ~Gestionnaire();

private:
    Ui::Gestionnaire *ui;
};

#endif // GESTIONNAIRE_H
