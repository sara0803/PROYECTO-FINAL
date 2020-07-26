#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>

#include <math.h>
#define M 5
#define G 1

class Personaje : public QGraphicsItem
{
public:
    int radio;
    int posx, posy;
    QString ruta;
    float friccion;

public:

    Personaje();
    Personaje (  int x, int y , int r, float friccion ,  QString path);
    int getR();
    void setR(int radio);
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    void subir();
    void bajar();
    void derecha();
    void izquierda();
    float getaceleracion();
    void setaceleracion(int radio);
    //void setFriccion(int f);
    //int  getFriccion( );
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // PERSONAJE_H
