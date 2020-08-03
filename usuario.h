#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

class Usuario
{
    QString nombre;
    QString contrasena;
    QString nivel;
    QString modoDeJuego;
    QString VIDAS;
    QString LLAVES;
    QString TIEMPO;

public:
    Usuario();
    Usuario(QString name, QString pass, QString level, QString modo, QString VIDAS, QString LLAVES, QString tiempo_);


    QString getNombre() const;
    void setNombre(QString value);
    QString getContrasena() const;
    void setContrasena(QString value);
    QString getNivel() const;
    void setNivel(const QString &value);
    QString getModoDeJuego() const;
    void setModoDeJuego(const QString &value);
    QString getVidas() const;
    void setVidas(const QString &value);
    QString getLlaves() const;
    void setLlaves(const QString &value);
    QString getVIDAS() const;
    void setVIDAS(const QString &value);
    QString getLLAVES() const;
    void setLLAVES(const QString &value);
    QString getTIEMPO() const;
    void setTIEMPO(const QString &value);
};

#endif // USUARIO_H
