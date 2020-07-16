#ifndef PARED_H
#define PARED_H
#include <QGraphicsItem>
#include <QPainter>


class Pared: public QGraphicsItem
{
    int w,h,posx, posy;
    QString ruta;
public:
    Pared();
    Pared(int x, int y, int h_, int w_, QString r);
    int getW();
    void setW(int ancho);
    int getH();
    void setH(int altura);
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // PARED_H
