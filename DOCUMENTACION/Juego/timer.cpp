#include "timer.h"

#include <QFont>

Timer::Timer(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar las vidas en 3
    time = 313;

    //ESCRIBIR EL TEXTO
    setPlainText(QString("Tiempo: ")+QString::number(time));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Timer::decrease()
{
    time--;
    setPlainText(QString("Tiempo: ")+QString::number(time));
}

int Timer::gettime()
{
    return time;
}

void Timer::settime(int value)
{
    time = value;
    setPlainText(QString("Tiempo: ")+QString::number(time));
}
