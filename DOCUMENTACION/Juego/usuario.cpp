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

Usuario::Usuario()
{

}

Usuario::Usuario(QString name, QString pass, QString level, QString mode)
{
    nombre=name;
    contrasena=pass;
    nivel=level;
    modoDeJuego=mode;
}
