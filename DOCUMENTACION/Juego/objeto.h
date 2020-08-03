#ifndef OBJETO_H
    #define OBJETO_H
    #include <math.h>
    #define M 5
    #define G 1
    #include <QGraphicsItem>
    #include <QPainter>
    class Objeto  : public QGraphicsItem
    {public:

        int radio;
        int posx, posy;
        QString ruta;
        int ECI;
        int ECF;

    public:
        Objeto();
        Objeto(int x, int y, int r, QString ruta);
        int getR();
        void setR(int r);
        int getPosx();
        void setPosx(int px);
        int getPosy();
        void setPosy(int py);
        void subir(int ECI,int ECF);
        void bajar(int ECI,int ECF);
        void derecha(int ECI,int ECF);
        void izquierda(int ECI,int ECF);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    };

    #endif // OBJETO_H
