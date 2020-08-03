#ifndef PARTICULA_H
#define PARTICULA_H
#include <objeto.h>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h> //seno coseno raiz

class Particula: public Objeto
{
    //se le dan las conidiones iniciales (atributos)
    double vel;
    // se van a recalculas con base en las ecuaciones
    double g= 9.8; //tiempo

public:
    Particula();
    Particula( double posxx, double  posyy , double velocidad, int r, QString path);

    void setVel(double value);
};

#endif // PARTICULA_H
