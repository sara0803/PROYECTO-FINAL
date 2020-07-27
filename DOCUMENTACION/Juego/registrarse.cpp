#include "registrarse.h"
#include "ui_registrarse.h"

Registrarse::Registrarse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrarse)
{
    ui->setupUi(this);
   QString usuario= ui->Usuario->text();
    QString contrasena=ui->Contrasena->text();
    QString nivel="1";
    QList<QString>cont_nivel={contrasena,nivel};
    QFile archivo ("");
    QFile archivo1("");
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    archivo1.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream escribir (&archivo1);

    QTextStream datosArchivo(&archivo);

    while (!datosArchivo.atEnd())
    {

        datosArchivo>>ArchivoUsuario;

        if (usuario==ArchivoUsuario)
        {
        ban=0;
        //QMessageBox :: critical (this, "EL USUARIO NO EXISTE");
        }
    }
    if (ban==1)
    {
        hide();
        QMap<QString,QList<QString>> registro;
        registro[usuario]=cont_nivel;
        escribir<<usuario<<" "<<contrasena<<" "<<nivel<<endl;

    }

}

Registrarse::~Registrarse()
{
    delete ui;
}
