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

//---------------------------------ABRE REGISTRO PARA VERIFICAR EN QUE NIVEL ESTÁ
     QFile archivo ("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
     //QFile cambios("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/cambios.txt");
     archivo.open(QIODevice::ReadOnly | QIODevice::Text);
     //cambios.open(QIODevice::ReadOnly | QIODevice::Text);

    // QTextStream escribir (&archivo);

     QTextStream datosArchivo (&archivo);

    // QTextStream escribir (&cambios);

     //QTextStream datosArchivo (&cambios);


     while (!datosArchivo.atEnd())
     {

           datosArchivo>>ArchivoUsuario>>passArchivo>>nivelUsuario>>modo>>Vidas>>Llaves>>Tiempoj>>l1>>l2>>l3>>l4>>l5>>l6>>endl;




         if (usuario==ArchivoUsuario)
         {


             if (contrasena==passArchivo)
             {



                 ban=0;
                 hide();
                 QMessageBox::warning(this, tr("USUARIO REGISTRADO"),
                                               tr("INGRESO EXITOSO"),


                                      QMessageBox::Cancel);
                 user=new Usuario(usuario, contrasena, nivelUsuario, modo, Vidas, Llaves,Tiempoj,l1,l2,l3,l4,l5,l6);

                 user->setNombre(usuario);
                 user->setContrasena(contrasena);
                 user->setNivel(nivelUsuario);
                 user->setModoDeJuego(modo);
                 user->setTIEMPO(Tiempoj);
                 user->setL1(l1);
                 user->setL2(l2);
                 user->setL3(l3);
                 user->setL4(l4);
                 user->setL5(l5);
                 user->setL6(l6);
                 MainWindow *EM= new MainWindow ();
                 EM->setUser(user);
                level=nivelUsuario.toInt();
                 LIFE=Vidas.toInt();
                 llavecita=Llaves.toInt();
                 jugadores=modo.toInt();
                 tiempoj=Tiempoj.toInt();
                 EM->llavesGuardadas(l1,l2,l3,l4,l5,l6);
                 EM->LLAVES(llavecita);
                 EM->setnivel(level);
                 EM->SETMODO(jugadores);
                 EM->VIDAS(LIFE);
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

