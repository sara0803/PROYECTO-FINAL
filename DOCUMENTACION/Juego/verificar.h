#ifndef VERIFICAR_H
#define VERIFICAR_H

#include <QDialog>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <mainwindow.h>
#include <usuario.h>
namespace Ui {
class Verificar;
}

class Verificar : public QDialog
{
    Q_OBJECT

public:
    explicit Verificar(QWidget *parent = nullptr);
    ~Verificar();
    QString passArchivo;
    QString archivoUsuario;
    QString nivelUsuario;
    QString modo;
    QString Vidas;
    QString Llaves;
    QString Tiempoj;
    QString l1;
    QString l2;
    QString l3;
    QString l4;
    QString l5;
    QString l6;
    int level1;
    int level2;
    int level3;
    int level4;
    int level5;
    int level6;
    //int cargarText();
private slots:
    void on_pushButton_clicked();


private:
    Ui::Verificar *ui;
    QGraphicsScene *scene;
    // QMainWindow *juego;
     int ban=1;
     int level;
     int LIFE;
     int llavecita;
     int tiempoj;
     int jugadores;

     //QString *nivel;
     QString ArchivoUsuario;
     //MainWindow *EM;
    Usuario *user;

};

#endif // VERIFICAR_H
