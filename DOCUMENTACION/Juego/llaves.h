#ifndef LLAVES_H
#define LLAVES_H

#include <QGraphicsTextItem>

#include <QString>

class llaves: public QGraphicsTextItem
{

public:

    llaves(QGraphicsItem * parent=0);

    void increase();
    int getkey();
    void setKey(int value);



    QString getLlave1() const;
    void setLlave1(const QString &value);

    QString getLlave2() const;
    void setLlave2(const QString &value);

    QString getLlave3() const;
    void setLlave3(const QString &value);

    QString getLlave4() const;
    void setLlave4(const QString &value);

    QString getLlave5() const;
    void setLlave5(const QString &value);

    QString getLlave6() const;
    void setLlave6(const QString &value);

private:

    int key;
    QString llave1;
    QString llave2;
    QString llave3;
    QString llave4;
    QString llave5;
    QString llave6;



};

#endif // LLAVES_H
