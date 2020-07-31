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
      QList<QString>cont2_nivel={contrasena,nivel};

     QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
     QFile archivo1("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
     QFile cambios("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/cambios.txt");
     archivo.open(QIODevice::ReadOnly | QIODevice::Text);
     archivo1.open(QIODevice::WriteOnly | QIODevice::Append);
     cambios.open(QIODevice::WriteOnly | QIODevice::Append);
     QTextStream datosArchivo (&archivo);
     QTextStream escribir (&archivo1);
     QTextStream write (&cambios);



     while (!datosArchivo.atEnd())
     {

         datosArchivo>>ArchivoUsuario; //lee el usuario del archivo, la primera línea

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
         //QMap<QString,QList<QString>> registro;
         //QMap<QString,QList<QString>> registro2;
         //registro[usuario]=cont_nivel;
         //registro2[usuario]=cont_nivel;
          //QList<QString>cont2_nivel={contrasena,nivel};
        write<<usuario<<" "<<contrasena<<" "<<nivel<<" "<<modo<<endl;
        escribir<<usuario<<" "<<contrasena<<" "<<nivel<<" "<<modo<<endl;
        QMessageBox::warning(this, tr("REGISTRO VÁLIDO"),
                                      tr("REGISTRO EXITOSO"),

                                      QMessageBox::Cancel);

     }
}

/*QString Registro::getNivel() const
{
    return nivel;
}

void Registro::setNivel(const QString &value)
{
    nivel = value;
}*/

void Registro::on_pushButton_2_clicked()
{
     modo= "1";
}

void Registro::on_pushButton_3_clicked()
{
     modo= "2";
}
