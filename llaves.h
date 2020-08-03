#ifndef LLAVES_H
#define LLAVES_H

#include <QGraphicsTextItem>


class llaves: public QGraphicsTextItem
{

public:

    llaves(QGraphicsItem * parent=0);

    void increase();
    int getkey();
    void setKey(int value);

private:

    int key;
};

#endif // LLAVES_H
