#include "sprite.h"

Sprite::Sprite(QObject *parent) : QObject(parent)
{

    timer = new QTimer();

    //PARA QUE SE MUESTRE EL SPRITE
    filas = 0;
    columnas = 0;

    pixmap = new QPixmap(":/IMAGENES/spritesheet_run_1x.png");
    pixmap->transformed(QTransform().scale(-1,1));

    //QPixmap *a= new QPixmap (":/IMAGENES/spritesheet_run_1x.png");
    //*a=a->transformed(QTransform().scale(-1,1));

    //DIMENSIONES DE LAS IMÁGENES (SPRITE)
    ancho = 96;
    alto  = 96;

    timer->start(200);// VELOCIDAD EN QUE ITERAN LAS IMÁGENES DEL SPRITE

    connect(timer,&QTimer::timeout,this,&Sprite::Actualizacion);

}

void Sprite::subir()
{
     setPos(x(),y()-5);
}

void Sprite::bajar()
{
    setPos(x(),y()+5);
}

void Sprite::derecha()
{
    setPos(x()+5,y());
}

void Sprite::izquierda()
{
    setPos(x()-5,y());
}
void Sprite::Actualizacion()
{
    //PARA QUE LAS IMAGENES DEL SPRITE CAMBIEN
    columnas +=96;
    if(columnas >=1088)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}
QRectF Sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}
