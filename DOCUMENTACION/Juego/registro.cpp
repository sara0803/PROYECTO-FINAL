#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);


}

Registro::~Registro()
{
    delete ui;
}


void Registro::on_pushButton_clicked()
{
    QString usuario= ui->USUARIO->text();
     QString contrasena=ui->CONTRASENA->text();
     QString nivel="1";
     QList<QString>cont_nivel={contrasena,nivel};

     QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
     QFile archivo1("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
     archivo.open(QIODevice::ReadOnly | QIODevice::Text);
     archivo1.open(QIODevice::WriteOnly | QIODevice::Append);
     QTextStream datosArchivo (&archivo);
     QTextStream escribir (&archivo1);



     while (!datosArchivo.atEnd())
     {

         datosArchivo>>ArchivoUsuario;

         if (usuario==ArchivoUsuario)
         {
         ban=0;
          QMessageBox::warning(this, tr("REGISTRO NO VÁLIDO"),
                                        tr("EL USUARIO YA ESTÁ REGISTRADO"),

                                        QMessageBox::Cancel);
         }
     }
     if (ban==1)
     {
         hide();
         QMap<QString,QList<QString>> registro;
         registro[usuario]=cont_nivel;
        escribir<<usuario<<" "<<contrasena<<" "<<nivel<<endl;
        QMessageBox::warning(this, tr("REGISTRO VÁLIDO"),
                                      tr("REGISTRO EXITOSO"),

                                      QMessageBox::Cancel);

     }
}
