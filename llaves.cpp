#include "llaves.h"

#include <QFont>

llaves::llaves(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar las llaves en 0
    key = 0;

    //ESCRIBIR EL TEXTO
    setPlainText(QString("Llaves: ")+QString::number(key));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));

}

void llaves::increase()
{
    key++;
    setPlainText(QString("Llaves: ")+QString::number(key));
}

int llaves::getkey()
{
    return key;
}