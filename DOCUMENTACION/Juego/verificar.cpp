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
     QString vidas="6";
     QString llaves="0";
     QString tiempo="313";
     QList<QString>cont_nivel={contrasena,nivel};
//---------------------------------ABRE REGISTRO PARA VERIFICAR EN QUE NIVEL ESTÁ
     QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
     //QFile cambios("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/cambios.txt");
     archivo.open(QIODevice::ReadOnly | QIODevice::Text);
     //cambios.open(QIODevice::ReadOnly | QIODevice::Text);

    // QTextStream escribir (&archivo);

     QTextStream datosArchivo (&archivo);

    // QTextStream escribir (&cambios);

     //QTextStream datosArchivo (&cambios);


     while (!datosArchivo.atEnd())
     {

         datosArchivo>>ArchivoUsuario>>passArchivo>>nivelUsuario>>modo>>Vidas>>Llaves>>Tiempoj>>endl;




         if (usuario==ArchivoUsuario)
         {


             if (contrasena==passArchivo)
             {
                 //qDebug()<<"NIVEL USUARIO"<<ArchivoUsuario<<" = "<<nivelUsuario;


                 ban=0;
                 hide();
                 QMessageBox::warning(this, tr("USUARIO REGISTRADO"),
                                               tr("INGRESO EXITOSO"),


                                      QMessageBox::Cancel);
                 user=new Usuario(usuario, contrasena, nivel, modo, Vidas, Llaves,Tiempoj);
                 user->setNombre(usuario);
                 user->setContrasena(contrasena);
                 user->setNivel(nivel);
                 user->setModoDeJuego(modo);
                 user->setTIEMPO(Tiempoj);
                 MainWindow *EM= new MainWindow ();
                 EM->setUser(user);
                level=nivelUsuario.toInt();
                 LIFE=Vidas.toInt();
                 llavecita=Llaves.toInt();
                 jugadores=modo.toInt();
                 tiempoj=Tiempoj.toInt();
                 EM->setnivel(level);
                 EM->SETMODO(jugadores);
                 EM->VIDAS(LIFE);
                 EM->LLAVES(llavecita);
                 EM->TIEMPO(tiempoj);
                 EM->show();



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
