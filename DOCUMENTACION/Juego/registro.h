#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include <QMessageBox>
namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registro *ui;
    QGraphicsScene *scene;
    // QMainWindow *juego;
     int ban=1;
     QString ArchivoUsuario;
};

#endif // REGISTRO_H
