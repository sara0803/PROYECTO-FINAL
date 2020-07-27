#ifndef CONTINUARPARTIDA_H
#define CONTINUARPARTIDA_H

#include <QDialog>

namespace Ui {
class ContinuarPartida;
}

class ContinuarPartida : public QDialog
{
    Q_OBJECT

public:
    explicit ContinuarPartida(QWidget *parent = nullptr);
    ~ContinuarPartida();

private:
    Ui::ContinuarPartida *ui;
};

#endif // CONTINUARPARTIDA_H
