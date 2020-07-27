#ifndef VERIFICAR_H
#define VERIFICAR_H

#include <QDialog>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <mainwindow.h>
namespace Ui {
class Verificar;
}

class Verificar : public QDialog
{
    Q_OBJECT

public:
    explicit Verificar(QWidget *parent = nullptr);
    ~Verificar();
    QString passArchivo;
    QString archivoUsuario;
    QString nivelUsuario;
        //int cargarText();
private slots:
    void on_pushButton_clicked();


private:
    Ui::Verificar *ui;
    QGraphicsScene *scene;
    // QMainWindow *juego;
     int ban=1;
     int level;
     QString *nivel;
     QString ArchivoUsuario;
     //MainWindow *EM;


};

#endif // VERIFICAR_H
