#include "particula.h"

void Particula::setVel(double value)
{
    vel = value;
}

Particula::Particula()
{
    
}

Particula::Particula(double posxx, double posyy, double velocidad, int r, QString path)
{
    posx=posxx;
    posy=posyy;
    vel=velocidad;
    ruta=path;
    radio=r;
    setPos(posx, posy);

}


