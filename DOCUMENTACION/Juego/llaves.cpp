#include "llaves.h"

#include <QFont>

llaves::llaves(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar las llaves en 0
    key = 6;

    //ESCRIBIR EL TEXTO
    setPlainText(QString("Llaves: ")+QString::number(key));
    setDefaultTextColor(Qt::red);
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

void llaves::setKey(int value)
{
    key = value;
    setPlainText(QString("Llaves: ")+QString::number(key));
}

QString llaves::getLlave1() const
{
    return llave1;
}

void llaves::setLlave1(const QString &value)
{
    llave1 = value;
}

QString llaves::getLlave2() const
{
    return llave2;
}

void llaves::setLlave2(const QString &value)
{
    llave2 = value;
}

QString llaves::getLlave3() const
{
    return llave3;
}

void llaves::setLlave3(const QString &value)
{
    llave3 = value;
}

QString llaves::getLlave4() const
{
    return llave4;
}

void llaves::setLlave4(const QString &value)
{
    llave4 = value;
}

QString llaves::getLlave5() const
{
    return llave5;
}

void llaves::setLlave5(const QString &value)
{
    llave5 = value;
}

QString llaves::getLlave6() const
{
    return llave6;
}

void llaves::setLlave6(const QString &value)
{
    llave6 = value;
}
