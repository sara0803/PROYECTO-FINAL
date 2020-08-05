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
#include <QLineEdit>
#include <verificar.h>
#include <registro.h>
#include <usuario.h>
#include <win.h>
#include <lose.h>
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
    QList<Objeto*> llavesL;

    void setnivel(int opcion_);

    void VIDAS(int opcion_);

    void LLAVES(int opcion_);

    void TIEMPO(int opcion_);

    void L1(int NIVEL1);

    void L2(int NIVEL2);

    void L3(int  NIVEL3);

    void L4(int  NIVEL4);

    void L5(int  NIVEL5);

    void L6(int  NIVEL6);

    void SETMODO(int modoo);

    void setUser(Usuario *value);

        void llavesGuardadas(QString,QString,QString,QString,QString,QString);

private slots:

    void continuar();

    //void botonInicio();

    void actualizar();

    void Iniciar();

    void registro();

    void guardar();

    void ganar();

    void instrucciones();

    void ReinicioDEnivel();

    void perder();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //TIPO VENTANAS
    Usuario *user;
    Registro *regis;

    //SONIDOS
    //QMediaPlayer *key;
    //QMediaPlayer *intro;


    //PARTÍCULA
    QTimer  *timer;
    QLabel *label;

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
    QString Tiempo;
    QString LEVEL1;
    QString LEVEL2;
    QString LEVEL3;
    QString LEVEL4;
    QString LEVEL5;
    QString LEVEL6;
    QString vidas1;
    QString llaves1;
    QString tiempo1;
    QString NIV1;
    QString NIV2;
    QString NIV3;
    QString NIV4;
    QString NIV5;
    QString NIV6;
    QString L11;
    QString L22;
    QString L33;
    QString L44;
    QString L55;
    QString L66;
    QPushButton *registrar;

    //OBJETOS
    Objeto *enemigo1;
    Objeto *personaje1;
    Objeto *personaje2;
    Particula *bolafuego;
    Objeto *bolaH;
    QObject *personaje;
    Objeto *boton;
    Objeto *dragon;
    vidas *vida;
    llaves *keys;
    Timer *tiempo;
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
    int jugadores=0;
    int nivel1=1;
    int nivel2=1;
    int nivel3=1;
    int nivel4=1;
    int nivel5=1;
    int nivel6=1;
    bool ban=false;
    bool ban2=false;
    bool ban3;
    bool visible;
    bool arch;
    int opcionArchivo=1;

    //__ prueba

    void keyPressEvent(QKeyEvent * evento);

    void items();

    void niveles(int,int,int,int,int,int,int,int);

    void guardarPartida();

    void clean ();

    void teletransportacion();

    void moverfuego();

    //void lanzarfuego();



    void moverEnemigo();

    void coaliciones (char , Objeto *personaje);

    void resorte(char letter,Objeto *personaje);

};
#endif // MAINWINDOW_H
