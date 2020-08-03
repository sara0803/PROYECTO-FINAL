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

   // QString getNivel() const;
    //void setNivel(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Registro *ui;
    QGraphicsScene *scene;
    // QMainWindow *juego;
     int ban=1;
     QString ArchivoUsuario;
     QString modo;
    // QString nivel;

};

#endif // REGISTRO_H
