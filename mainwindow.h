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

    //OBJETOS
    Personaje *enemigo1;
    Personaje *personaje1;
    Personaje *personaje2;
    Particula *bolafuego;
    Objeto *bolaH;
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
    int rigidez=0;
    int friccion=0;
    int counter=0;
    int xmenor=0;
    int xmayor=0;
    int ymenor=0;
    int ymayor=0;
    int path=0;
    bool ban=false;
    bool ban2=false;
    bool visible;

    //____ prueba

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int);

    void guardarPartida();

    void clean ();

    void teletransportacion();

    void moverfuego();

    //void lanzarfuego();

    void moverEnemigo();

    void coaliciones (char , Personaje *personaje );

    void resorte(char letter,Personaje *personaje);

QPushButton *start;
QPushButton *continuarPartida;
QPushButton *guardar;
QFile archivo;
};
#endif // MAINWINDOW_H
