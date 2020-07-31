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
#include <verificar.h>
#include <registro.h>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QEvent>
#include <QMovie>
#include <QString>
#include <usuario.h>
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

     void setnivel(int opcion_);

     void setUser(Usuario *value);

private slots:

     void per();
     //SLOTS DE LA PARTÍCULA


    /*double masa;
    double posx;
    double posy;
    double radio;
    double vx;
    double vy;*/
//--------INGRESO-------

    //void Personaje mover(int , int );


    void moverEnemigo();

    void actualizar();

    void lanzamiento ();

    void lanzarfuego();

    void Iniciar();

    void registro();

    void continuar();



   // void Persecucion(int, int);

    void CoeficienteRestitucion();

    void coaliciones (char , Personaje *personaje );

    void guardar();



private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //SONIDOS
    //QMediaPlayer *key;
    //QMediaPlayer *intro;


    //PARTÍCULA
     QTimer *timerperseguir;
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
    Objeto *puerta;
    Objeto *bolaH;
    Objeto *bolaFuego;
    Objeto *llave;
    QObject *personaje;
    Objeto *boton;
    Usuario *user;
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

    void teletransportacion();

    int path=0;

    bool ban=false;

    bool visible;

    bool arch;

    int cosa=1;

//-------BOTONES
QPushButton *start;
QPushButton *continuarPartida;
QPushButton *save;
QLineEdit *usuario;
//QLineEdit *echoLineEdit;
//QGroupBox *echoGroup;
QFile archivo;
QString ArchivoUsuario;
QString passArchivo;
QString nivelUsuario;
QString mode;
QString ArchivoUsuario1;
QString passArchivo1;
QString nivelUsuario1;
QString mode1;
QPushButton *registrar;

Registro *regis;


};
#endif // MAINWINDOW_H
