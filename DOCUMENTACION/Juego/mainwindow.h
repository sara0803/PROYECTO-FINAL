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
#include <QMovie>
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


    /*double masa;
    double posx;
    double posy;
    double radio;
    double vx;
    double vy;*/

    void mover();

    void actualizar();

    void lanzamiento ();

    void lanzarfuego();

    void continuar();

    void botonInicio();

    void moverEnemigo();

    void CoeficienteRestitucion();

    void coaliciones (char , Personaje *personaje );

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //SONIDOS
    QMediaPlayer *key;
    QMediaPlayer *intro;


    //PARTÍCULA
    QTimer *timerEnem;
    QTimer  *timer;
    QTimer  *Timer;
    QTimer  *disparo;
    QLabel *label;
    Particula *cuerpo;
    QList<Particula*>cuerpos;
    QList<Particula*>LISTA;

    //OBJETOS
    //Personaje *personaje1;
    Personaje *enemigo1;
    Personaje *totem;
    Personaje *personaje1;
    Personaje *personaje2;
    Personaje *lanzador;
    Sprite *dragon;
    Objeto *puerta;
    Objeto *bolaH;
    Objeto *bolaFuego;
    Objeto *llave;
    QObject *personaje;
    Objeto *boton;
    double x;
    double y;
    int opcion=0;
    int nivel=0;
    int i=0;

    //____ prueba
    Particula *particula1;
    Particula *particula2;
   // Sprite *personaje1;

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int);

    void aceleracion(int);

    void guardarPartida();

    void clean ();

    int path=0;

    bool ban=false;

QPushButton *start;
QPushButton *continuarPartida;
QPushButton *guardar;
QFile archivo;
};
#endif // MAINWINDOW_H
