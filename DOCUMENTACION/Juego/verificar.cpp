#include "verificar.h"
#include "ui_verificar.h"

Verificar::Verificar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Verificar)
{
    ui->setupUi(this);
}

Verificar::~Verificar()
{
    delete ui;
}

void Verificar::on_pushButton_clicked()
{
    QString usuario= ui->USUARIO->text();
     QString contrasena=ui->CONTRASENA->text();
     QString nivel="1";
     QList<QString>cont_nivel={contrasena,nivel};

     QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");

     archivo.open(QIODevice::ReadOnly | QIODevice::Text);


     QTextStream escribir (&archivo);

     QTextStream datosArchivo (&archivo);



     while (!datosArchivo.atEnd())
     {

         datosArchivo>>ArchivoUsuario>>passArchivo>>nivelUsuario;




         if (usuario==ArchivoUsuario)
         {
             if (contrasena==passArchivo)
             {
                 ban=0;
                 hide();
                 /*QMessageBox::warning(this, tr("USUARIO REGISTRADO"),
                                               tr("INGRESO EXITOSO"),


                                      QMessageBox::Cancel);*/

                 MainWindow *EM= new MainWindow ();
                level=nivelUsuario.toInt();
                 EM->setnivel(level);
                 EM->show();


                 /*EM=new MainWindow( this);

                 EM->niveles(level);*/
                 //cargarText();
             }


         }
     }
     if (ban==1)
     {
         ban=0;
         hide();
         QMessageBox::warning(this, tr("NO SE PUEDE INGRESAR"),
                                       tr("USUARIO NO REGISTRADO"),

                                       QMessageBox::Cancel);

     }
}

/*int  Verificar::cargarText()
{
    return level;
}*/
