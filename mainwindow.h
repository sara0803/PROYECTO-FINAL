#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
//#include <QMediaPlayer>
#include <QPixmap>
#include <QList>
#include <personaje.h>
//#include <sprite.h>
#include <objeto.h>
#include <particula.h>
#include <pared.h>
#include <vidas.h>
#include <llaves.h>
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
    QList<Particula*> cuerpos;

private slots:

    void continuar();

    void botonInicio();

    void actualizar();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //SONIDOS
    //QMediaPlayer *key;
    //QMediaPlayer *intro;


    //PARTÍCULA
    QTimer  *timer;
    QLabel *label;
    Particula *cuerpo;

    //OBJETOS
    Personaje *enemigo1;
    Personaje *totem;
    Personaje *personaje1;
    Personaje *personaje2;
    Personaje *lanzador;
    Objeto *puerta;
    Objeto *bolaH;
    Objeto *bolaFuego;
    Objeto *llave;
    QObject *personaje;
    Objeto *boton;
    Objeto *dragon;
    vidas *vida;
    llaves *keys;
    double x;
    double y;
    int opcion=0;
    int nivel=0;
    int i=0;
    int rigidez=0;
    int friccion=0;
    int counter=0;

    //____ prueba
    Particula *particula1;
    Particula *particula2;

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int);

    void guardarPartida();

    void clean ();

    void teletransportacion();

    int path=0;

    bool ban=false;

    bool visible;

    void mover();

    void lanzarfuego();

    void moverEnemigo();

    void coaliciones (char , Personaje *personaje );

    void resorte(char letter,Personaje *personaje);

QPushButton *start;
QPushButton *continuarPartida;
QPushButton *guardar;
QFile archivo;
};
#endif // MAINWINDOW_H
