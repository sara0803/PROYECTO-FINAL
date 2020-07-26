#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#define dt 10
#define G 1
class Particula: public QGraphicsItem
{
    double posx,posy;
    double velx,vely;
    double acelx,acely;
    double Masa;
    double radio;
    QString ruta;
    int r=10;

public:

    Particula();
    void Asignar(float pi, float pyi, float vxi, float vyi,float m, float rad, QString path);
    //~Particula();

    void Actualizar();
    void actualizar();
    void Acacelx(Particula N);
    void Acacely(Particula N);
    double getPosx() const;
    double getPosy() const;
    double getVelx() const;
    double getVely() const;
    double getAcelx() const;
    double getAcely() const;
    double getMasa() const;
    double getRadio() const;

    void setPosx(double value);
    void setPosy(double value);
    void setVelx(double value);
    void setVely(double value);
    void setAcelx(double value);
    void setAcely(double value);
    void setMasa(double value);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:

};

#endif // PARTICULA_H
