#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

class Usuario
{
    QString nombre;
    QString contrasena;
    QString nivel;
    QString modoDeJuego;

public:
    Usuario();
    Usuario(QString name, QString pass, QString level,QString modoDeJuego );


    QString getNombre() const;
    void setNombre(QString value);
    QString getContrasena() const;
    void setContrasena(QString value);
    QString getNivel() const;
    void setNivel(const QString &value);
    QString getModoDeJuego() const;
    void setModoDeJuego(const QString &value);
};

#endif // USUARIO_H
