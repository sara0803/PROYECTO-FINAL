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

Usuario::Usuario()
{

}



Usuario::Usuario(QString name, QString pass, QString level, QString mode, QString vidas_, QString llaves_, QString tiempo_)
{
    nombre=name;
    contrasena=pass;
    nivel=level;
    modoDeJuego=mode;
    VIDAS=vidas_;
    LLAVES=llaves_;
    TIEMPO=tiempo_;
}
