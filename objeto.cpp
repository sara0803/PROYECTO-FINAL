#include "objeto.h"

Objeto::Objeto()
{

}

Objeto::Objeto(int x, int y, int r, QString rt)
{
    posx=x;
    posy=y;
    radio=r;
    ruta=rt;
    setPos(posx,posy);
}

int Objeto::getR()
{
    return radio;
}

void Objeto::setR(int r)
{
    radio=r;
}


int Objeto::getPosx()
{
    return posx;
}

void Objeto::setPosx(int  px)
{
    posx=px;
}

int Objeto::getPosy()
{
    return posy;
}

void Objeto::setPosy(int py)
{
    posy = py;
}
void Objeto::subir(int ECI, int ECF)
{
     setPos(x(),y()-5*ECI*ECF);
}

void Objeto::bajar(int ECI, int ECF)
{
    setPos(x(),y()+5*ECI*ECF);
}

void Objeto::derecha(int ECI,int ECF)
{
    setPos(x()+5*ECI*ECF,y());
}

void Objeto::izquierda(int ECI, int ECF)
{
    setPos(x()-5*ECI*ECF,y());
}

QRectF Objeto::boundingRect() const
{
     return QRectF(-radio,-radio,2*radio,2*radio);

}

void Objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
