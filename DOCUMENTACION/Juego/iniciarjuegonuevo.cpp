#include "iniciarjuegonuevo.h"
#include "ui_iniciarjuegonuevo.h"

IniciarJuegoNuevo::IniciarJuegoNuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarJuegoNuevo)
{
    ui->setupUi(this);
}

IniciarJuegoNuevo::~IniciarJuegoNuevo()
{
    delete ui;
}

void IniciarJuegoNuevo::on_pushButton_clicked()
{

}
