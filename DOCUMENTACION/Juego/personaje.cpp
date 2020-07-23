#include "personaje.h"

Personaje::Personaje()
{

}

Personaje::Personaje(int x, int y, int r, float f, float a, QString path)
{
    radio=r;
    posx = x;
    posy = y;
    ruta=path;
    friccion=f;
    aceleracion=a;
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
     setPos(x(),y()-5*friccion);
}

void Personaje::bajar()
{
    setPos(x(),y()+5*friccion);
}

void Personaje::derecha()
{
    setPos(x()+5*friccion,y());
}

void Personaje::izquierda()
{

    setPos(x()-5*friccion,y());

}

/*void Personaje::setFriccion( int f )
{
    friccion=f;
}

int  Personaje::getFriccion()
{
    return friccion;
}*/

QRectF Personaje::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*QPixmap personaje;

    personaje.load(ruta);


    painter->drawPixmap(boundingRect(),personaje,personaje.rect());*/


    QPixmap *personaje=new QPixmap(ruta);
    *personaje=personaje->transformed(QTransform().scale(-1,1));
    painter->drawPixmap(boundingRect(),*personaje,personaje->rect());

}
