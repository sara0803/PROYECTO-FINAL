#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
//#include <QMediaPlayer>
class Sprite : public QObject, public QGraphicsItem
{
    QString ruta;
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;

    float ancho;
    float alto;


    void subir();
    void bajar();
    void derecha();
    void izquierda();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:

    void Actualizacion();

private:

};

#endif // SPRITE_H
