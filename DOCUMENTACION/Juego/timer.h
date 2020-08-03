#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>


class Timer: public QGraphicsTextItem
{

public:

    Timer(QGraphicsItem * parent=0);

    void decrease();
    int gettime();
    void settime(int value);

private:

    int time;
};

#endif // TIMER_H
