#include "pared.h"

Pared::Pared()
{

}

Pared::Pared(int x, int y,int w_, int h_,  QString r)
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;
    ruta=r;
}


int Pared::getW()
{
    return w;
}

int Pared::getH()
{
    return h;
}

void Pared::setW(int ancho)
{
    w = ancho;
}

void Pared::setH(int altura)
{
    h = altura;
}

int Pared::getPosx()
{
    return posx;
}

void Pared::setPosx(int px)
{
    posx=px;
}

int Pared::getPosy()
{
    return posy;
}

void Pared::setPosy(int py)
{
    posy = py;
}

QRectF Pared::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());*/
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
