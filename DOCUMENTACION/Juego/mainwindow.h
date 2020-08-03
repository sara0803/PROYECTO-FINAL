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
#include <QMessageBox>
#include <QLabel>
#include <QEvent>
#include <QMovie>
#include <QString>
#include <usuario.h>
#include <vidas.h>
#include <llaves.h>
#include <win.h>
#include <timer.h>
#include <instrucciones.h>
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

    void VIDAS(int opcion_);

     void LLAVES(int opcion_);

     void setUser(Usuario *value);

     void SETMODO(int modoo);


           void TIEMPO(int opcion_);

private slots:

     //SLOTS PRIVADOS

    void per();

    void perder();

    void moverEnemigo();

    void actualizar();

    void lanzamiento ();

    void lanzarfuego();

    void Iniciar();

    void registro();

    void continuar();

    void guardar();

    void instrucciones();

    void ganar();

    void ReinicioDEnivel();

    void CoeficienteRestitucion();

    void coaliciones (char , Objeto *personaje);

    void resorte(char letter,Objeto *personaje);





private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //SONIDOS
    //QMediaPlayer *key;
    //QMediaPlayer *intro;


    //TIPO PARTÍCULA

    QTimer  *timer;
    QLabel *label;

    Particula *particula1;
    Particula *particula2;
    Particula *cuerpo;
    Particula *bolafuego;
    QList<Particula*>cuerpos;
    QList<Particula*>LISTA;

    //TIPO PERSONAJE
    QObject *personaje;



    //TIPO OBJETO
    Objeto *puerta;
    Objeto *bolaH;
    Objeto *bolaFuego;
    Objeto *llave;
    Objeto *dragon;
    Objeto *boton;
    Objeto *enemigo1;
    Objeto *personaje1;
    Objeto *personaje2;

    //TIPO VENTANAS
    Usuario *user;
    Registro *regis;


    //OTROS
    vidas *vida;
    llaves *keys;

    //TIPO NÚMEROS
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
    int i=0;
    int jugadores;

    //TIPO BOOLEANO
    bool ban=false;
    bool ban2=false;
    bool visible;
    bool arch;
    int opcionArchivo=1;
    bool in=false;




   //MÉTODOS

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int, int);

    void aceleracion(int);

    void guardarPartida();

    void clean ();

    void teletransportacion();

    void moverfuego();


    void resorte(char letter,Personaje *personaje);


    //-------BOTONES
    QPushButton *start;
    QPushButton *instruccion;
    QPushButton *save;
    QLineEdit *usuario;


    //--------ARCHIVOS--------
    QFile archivo;
    QString ArchivoUsuario;
    QString passArchivo;
    QString nivelUsuario;
    QString mode;
    QString ArchivoUsuario1;
    QString passArchivo1;
    QString nivelUsuario1;
    QString mode1;
    QString Vidas;
    QString Llaves;
    QString vidas1;
    QString llaves1;
    QPushButton *registrar;
    QString Tiempo;

        QString tiempo1;
Timer *tiempo;


};
#endif // MAINWINDOW_H
