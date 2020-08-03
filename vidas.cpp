#include "vidas.h"

#include <QFont>

vidas::vidas(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar las vidas en 3
    life = 3;

    //ESCRIBIR EL TEXTO
    setPlainText(QString("Vidas: ")+QString::number(life));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void vidas::decrease()
{
    life--;
    setPlainText(QString("Vidas: ")+QString::number(life));
}

int vidas::getlife()
{
    return life;
}

void vidas::setLife(int value)
{
    life = value;
    setPlainText(QString("Vidas: ")+QString::number(life));
}
