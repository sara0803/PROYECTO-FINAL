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

void Personaje::perseguir(int px , int py)
{

    //en esta funcion el emenigo calcula a el como moverse para seguir el enemigo,
    //esto usando las formulas de gravedad de la practica 6
    double r,ax,ay,x,y;
    r=sqrt(pow(px-this->x(),2)+pow(py-this->y(),2));
    ax=(100/pow(abs(r),3))*(px-this->x());
    ay=(100/pow(abs(r),3))*(py-this->y());
    if(ax>=0) x=ax+vel;
    else x=ax-vel;
    if(ay>=0) y=ay+vel;
    else y=ay-vel;
    if((ax+vel)>0.5) ax=0.5;
    if((ax+vel)<-0.5) ax=-0.5;
    if((ay+vel)>0.5) ay=1;
    if((ay+vel)<-0.5) ay=-0.5;
    if(r<23)
    {
        setPos(this->x(),this->y());
    }
    //r<23 (this->x(),this->y())
    else
    {
        setPos(this->x()+x,this->y()+y);
    }
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
