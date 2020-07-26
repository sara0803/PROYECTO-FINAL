#ifndef VIDAS_H
#define VIDAS_H

#include <QGraphicsTextItem>


class vidas: public QGraphicsTextItem
{

public:

    vidas(QGraphicsItem * parent=0);

    void decrease();
    int getlife();

private:

    int life;

};

#endif // VIDAS_H
