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
    QString L1;
    QString L2;
    QString L3;
    QString L4;
    QString L5;
    QString L6;

public:
    Usuario();
    Usuario(QString name, QString pass, QString level, QString modo, QString VIDAS, QString LLAVES, QString tiempo_,QString L1,QString L2,QString L3,QString L4,QString L5,QString L6);


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
    QString getL1() const;
    void setL1(const QString &value);
    QString getL2() const;
    void setL2(const QString &value);
    QString getL3() const;
    void setL3(const QString &value);
    QString getL4() const;
    void setL4(const QString &value);
    QString getL5() const;
    void setL5(const QString &value);
    QString getL6() const;
    void setL6(const QString &value);
};

#endif // USUARIO_H
