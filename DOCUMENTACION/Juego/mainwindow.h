#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QPixmap>
#include <QList>
#include <personaje.h>
#include <sprite.h>
#include <objeto.h>
#include <particula.h>
#include <pared.h>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //QList<Objeto*> muros;
    QList<Pared*> muros;
    QList<Objeto*> piedras;

private slots:


    //SLOTS DE LA PARTÍCULA
    void mover();


    void lanzamiento (int xi, int xf, int yi, int yf);

    void lanzarfuego();

    void guardarPartida();

    void botonInicio();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //SONIDOS
    QMediaPlayer *key;
    QMediaPlayer *intro;


    //PARTÍCULA
    QTimer  *timer;
    Particula *cuerpo;
    QList<Particula*>cuerpos;

    //OBJETOS
    //Personaje *personaje1;
    Personaje *enemigo1;
    Personaje *totem;
    Personaje *personaje1;
    Personaje *lanzador;
    Sprite *dragon;
    Objeto *puerta;
    Objeto *bolaH;

    Objeto *bolaFuego;
    Objeto *llave;
    double x;
    double y;
    int opcion=0;
    int nivel=0;

   // Sprite *personaje1;

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int);

    void clean ();



QPushButton *start;
QPushButton *saveData;

};
#endif // MAINWINDOW_H
