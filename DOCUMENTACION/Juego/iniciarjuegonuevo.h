#ifndef INICIARJUEGONUEVO_H
#define INICIARJUEGONUEVO_H

#include <QDialog>
#include <verificar.h>
namespace Ui {
class IniciarJuegoNuevo;
}

class IniciarJuegoNuevo : public QDialog
{
    Q_OBJECT

public:
    explicit IniciarJuegoNuevo(QWidget *parent = nullptr);
    ~IniciarJuegoNuevo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IniciarJuegoNuevo *ui;

    Verificar *ver;
};

#endif // INICIARJUEGONUEVO_H
