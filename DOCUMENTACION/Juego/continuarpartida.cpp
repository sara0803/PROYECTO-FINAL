#include "continuarpartida.h"
#include "ui_continuarpartida.h"

ContinuarPartida::ContinuarPartida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinuarPartida)
{
    ui->setupUi(this);
}

ContinuarPartida::~ContinuarPartida()
{
    delete ui;
}
