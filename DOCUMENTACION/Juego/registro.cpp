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


void Registro::on_pushButton_2_clicked()
{
    QString usuario= ui->USUARIO->text();
     QString contrasena=ui->CONTRASENA->text();
     QString nivel="1";
        QString vidas="80";
        QString llaves="0";
        QString time="313";
        QString l1="1";
        QString l2="1";
        QString l3="1";
        QString l4="1";
        QString l5="1";
        QString l6="1";
     QList<QString>cont_nivel={contrasena,nivel};
      QList<QString>cont2_nivel={contrasena,nivel};

     QFile archivo ("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
     QFile archivo1("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
     QFile cambios("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/cambios.txt");
     archivo.open(QIODevice::ReadOnly | QIODevice::Text);
     archivo1.open(QIODevice::WriteOnly | QIODevice::Append);
     cambios.open(QIODevice::WriteOnly | QIODevice::Append);
     QTextStream datosArchivo (&archivo);
     QTextStream escribir (&archivo1);
     QTextStream write (&cambios);

     if ((modo!="1" and modo!="2") or (usuario=="") or (contrasena=="") )
          {
              QMessageBox::warning(this, tr("REGISTRO NO VÁLIDO"),

                                   tr("DEBE COMPLETAR TODOS LOS CAMPOS REQUERIDOS"),
                                            QMessageBox::Cancel);

          }

          else
          {
              ban=1;
          }

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
         write<<usuario<<" "<<contrasena<<" "<<nivel<<" "<<modo<<" "<<vidas<<" "<<llaves<<" "<<time<<" "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<endl;
         escribir<<usuario<<" "<<contrasena<<" "<<nivel<<" "<<modo<<" "<<vidas<<" "<<llaves<<" "<<time<<" "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<endl;
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

void Registro::on_pushButton_clicked()
{
     modo= "1";
     QMessageBox::information(this,"","SELECCIONASTE UN JUGADOR");
}

void Registro::on_pushButton_3_clicked()
{
     modo= "2";
     QMessageBox::information(this,"","SELECCIONASTE MODO MULTIJUGADOR");
}
