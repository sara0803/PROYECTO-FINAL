#include "personaje.h"

Personaje::Personaje()
{

}

Personaje::Personaje(int x, int y, int r, float f, QString path)
{
    radio=r;
    posx = x;
    posy = y;
    ruta=path;
    friccion=f;
    setPos(posx,posy);
}

int Personaje::getR()
{
    return radio;
}

void Personaje::setR(int r)
{
     radio = r;
}

int Personaje::getPosx()
{
     return posx;
}

void Personaje::setPosx(int px)
{
     posx=px;
}

int Personaje::getPosy()
{
     return posy;
}

void Personaje::setPosy(int py)
{
    posy = py;
}

void Personaje::subir()
{
     setPos(x(),y()-(5*friccion));
}

void Personaje::bajar()
{
    setPos(x(),y()+(5*friccion));
}

void Personaje::derecha()
{
    setPos(x()+(5*friccion),y());
}

void Personaje::izquierda()
{
    setPos(x()-(5*friccion),y());
}

QRectF Personaje::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
