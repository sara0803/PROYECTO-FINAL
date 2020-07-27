#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QDialog>
#include <QGraphicsScene>
#include <mainwindow.h>
#include <QMessageBox>
namespace Ui {
class Registrarse;
}

class Registrarse : public QDialog
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = nullptr);
    ~Registrarse();

private:
    Ui::Registrarse *ui;
   QGraphicsScene *scene;
   // QMainWindow *juego;
    int ban=1;
    QString ArchivoUsuario;
};

#endif // REGISTRARSE_H
