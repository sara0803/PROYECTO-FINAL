#include "usuario.h"





QString Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(QString value)
{
    nombre = value;
}


QString Usuario::getContrasena() const
{
    return contrasena;
}

void Usuario::setContrasena(QString value)
{
    contrasena = value;
}

QString Usuario::getNivel() const
{
    return nivel;
}

void Usuario::setNivel(const QString &value)
{
    nivel = value;
}

QString Usuario::getModoDeJuego() const
{
    return modoDeJuego;
}

void Usuario::setModoDeJuego(const QString &value)
{
    modoDeJuego = value;
}


QString Usuario::getVIDAS() const
{
    return VIDAS;
}

void Usuario::setVIDAS(const QString &value)
{
    VIDAS = value;
}

QString Usuario::getLLAVES() const
{
    return LLAVES;
}

void Usuario::setLLAVES(const QString &value)
{
    LLAVES = value;
}

QString Usuario::getTIEMPO() const
{
    return TIEMPO;
}

void Usuario::setTIEMPO(const QString &value)
{
    TIEMPO = value;
}

QString Usuario::getL1() const
{
    return L1;
}

void Usuario::setL1(const QString &value)
{
    L1 = value;
}

QString Usuario::getL2() const
{
    return L2;
}

void Usuario::setL2(const QString &value)
{
    L2 = value;
}

QString Usuario::getL3() const
{
    return L3;
}

void Usuario::setL3(const QString &value)
{
    L3 = value;
}

QString Usuario::getL4() const
{
    return L4;
}

void Usuario::setL4(const QString &value)
{
    L4 = value;
}

QString Usuario::getL5() const
{
    return L5;
}

void Usuario::setL5(const QString &value)
{
    L5 = value;
}

QString Usuario::getL6() const
{
    return L6;
}

void Usuario::setL6(const QString &value)
{
    L6 = value;
}

Usuario::Usuario()
{
    
}



Usuario::Usuario(QString name, QString pass, QString level, QString mode, QString vidas_, QString llaves_, QString tiempo_,QString l1_,QString l2_,QString l3_,QString l4_,QString l5_,QString l6_)
{
    nombre=name;
    contrasena=pass;
    nivel=level;
    modoDeJuego=mode;
    VIDAS=vidas_;
    LLAVES=llaves_;
    TIEMPO=tiempo_;
    L1=l1_;
    L2=l2_;
    L3=l3_;
    L4=l4_;
    L5=l5_;
    L6=l6_;
}
