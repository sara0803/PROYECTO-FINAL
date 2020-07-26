#include "particula.h"


Particula::Particula()
{

}

void Particula::Asignar(float pxi, float pyi, float vxi, float vyi, float m, float rad, QString path)
{
    posx=pxi;
    posy=pyi;
    velx=vxi;
    vely=vyi;
    acelx=0;
    acely=0;
    Masa=m;
    radio=rad;
    ruta=path;
}

/*void Particula::Actualizar()
{
    P->actualizar();
    setPos(P->getPosx()*escala,(-P->getPosy())*escala);
}*/
void Particula::actualizar() //se actualizan todos los datos//
{
    posx=posx+velx*dt+(acelx*dt*dt)/2;
    posy=posy+vely*dt+(acely*dt*dt)/2;

    velx=velx+acelx*dt;
    vely=vely+acely*dt;

    acelx=0;
    acely=0;
}


void Particula::Acacelx(Particula N)
{
    float r, teta, dx, dy;
    dx= N.posx-posx;
    dy= N.posy-posy;
    teta=atan2(dy,dx);
    r=pow(dx,2)+pow(dy,2);
    acelx=acelx+G*N.Masa*cos(teta)/r;
}

void Particula::Acacely(Particula N)
{
    float r, teta, dx, dy;
    dx= N.posx-posx;
    dy= N.posy-posy;
    teta=atan2(dy,dx);
    r=pow(dx,2)+pow(dy,2);
    acely=acely+G*N.Masa*sin(teta)/r;
}

double Particula::getPosx() const
{
    return posx;
}
void Particula::setPosx(double value)
{
    posx = value;
}
double Particula::getPosy() const
{
    return posy;
}

void Particula::setPosy(double value)
{
    posy = value;
}

double Particula::getVelx() const
{
    return velx;
}

void Particula::setVelx(double value)
{
    velx = value;
}

double Particula::getVely() const
{
    return vely;
}

void Particula::setVely(double value)
{
    vely = value;
}

double Particula::getAcelx() const
{
    return acelx;
}

void Particula::setAcelx(double value)
{
    acelx = value;
}

double Particula::getAcely() const
{
    return acely;
}

void Particula::setAcely(double value)
{
    acely = value;
}

double Particula::getMasa() const
{
    return Masa;
}

void Particula::setMasa(double value)
{
    Masa = value;
}



double Particula::getRadio() const
{
    return radio;
}


QRectF Particula::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}


