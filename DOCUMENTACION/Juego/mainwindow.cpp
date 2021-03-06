#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));

ui->setupUi(this);
scene = new QGraphicsScene;
ui->graphicsView->setScene(scene);
llavesL.push_back(new Objeto (-65,220,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());
llavesL.push_back(new Objeto (470,35,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());
llavesL.push_back(new Objeto (480,45,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());
llavesL.push_back(new Objeto (490,55,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());
llavesL.push_back(new Objeto (10,100,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());
llavesL.push_back(new Objeto (460,25,30,":/I/I/llave1.png"));
    scene->addItem(llavesL.back());

for (int i=0;i<llavesL.size();i++)
    {
    llavesL.at(i)->hide();

    }
niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);

//--------------------BOTÓN INICIAR JUEGO NUEVO----------------------

start=new QPushButton("INICIAR JUEGO NUEVO", this);

start->setGeometry(QRect( QPoint(310,160), // Valores por defecto 250x160
QSize(200, 50) ));
//Valores por defecto : 200x 50

connect(start, SIGNAL (clicked()),this, SLOT (Iniciar()));
start->setStyleSheet("background-color: gray");

//-----------------------BOTÓN INSTRUCCIONES------------------

instruccion=new QPushButton ("      INSTRUCCIONES ",this);

instruccion->setGeometry(QRect( QPoint(310,300),
QSize(200, 50) ));

connect(instruccion, SIGNAL (clicked()),this, SLOT (instrucciones()));
instruccion->setStyleSheet("background-color: gray");


//-----------------------------BOTÓN REGISTRO ------------------

registrar=new QPushButton ("REGISTRARSE",this);

registrar->setGeometry(QRect( QPoint(310,450),
QSize(200, 50) ));

connect(registrar, SIGNAL (clicked()),this, SLOT (registro()));
registrar ->setStyleSheet("background-color: gray");

//-----------------------------BOTÓN GUARDADO ------------------

save=new QPushButton ("GUARDAR PARTIDA",this);

save->setGeometry(QRect( QPoint(0,0),
QSize(200, 50) ));

connect(save, SIGNAL (clicked()),this, SLOT (guardar()));
save ->setStyleSheet("background-color: gray");



/*LISTA.append(new Particula(0,0,0,0,50000,200));
LISTA.append(new Particula(-5000,0,0,0,70,70));
LISTA.append(new Particula(5000,0,0,0,70,70)); */   //Planetas agregados directamente
// LISTA.append(new Graficar(0,-5000,2,0,70,70));
//LISTA.append(new Graficar(0,5000,-2,0,70,70));



}


//-------------------------------------------------KEYPRESSEVENT--------------------------------------------------

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

 //qDebug()<<personaje1->pos()<<personaje1->x();

//-----------------------------------------EVENTO PERSONAJE 1 NIVEL 1-------------------------------------------------

if (opcion==1)
{
    if(evento->key()==Qt::Key_A)
    {
        coaliciones('A', personaje1);
    }

    else if(evento->key()==Qt::Key_D)
    {

        coaliciones('D', personaje1);

    }
    else if(evento->key()==Qt::Key_W)
    {

        coaliciones('W', personaje1);

    }

    else if(evento->key()==Qt::Key_S)
    {

        coaliciones('S', personaje1);
    }


// qDebug()<<personaje1->pos()<<personaje1->x();

//-------------------------------------------------EVENTO PERSONAJE 2 NIVEL 1------------------------------------------------------------
if(evento->key()==Qt::Key_I)
{

    coaliciones('I', personaje2);

}
if(evento->key()==Qt::Key_J)
{
    coaliciones('J', personaje2);


}
if(evento->key()==Qt::Key_L)
{

    coaliciones('L', personaje2);

}
if(evento->key()==Qt::Key_K)
{

    coaliciones('K', personaje2);

}
teletransportacion();
//------------------------------------------------CAMBIO DE NIVEL 1 A 2-------------------------------------------------

/*if (evento->key()==Qt::Key_2)
 //if (((personaje1->x()==200 )and (personaje1->y()==60  )) )
 {
 }*/

}

//-----------------------------------------------EVENTO PERSONAJE 1 NIVEL 2-------------------------------------------------

if (opcion==2)
{
    if(evento->key()==Qt::Key_A)
    {
        coaliciones('A', personaje1);
    }

    else if(evento->key()==Qt::Key_D)
    {

        coaliciones('D', personaje1);

    }
    else if(evento->key()==Qt::Key_W)
    {

        coaliciones('W', personaje1);

    }

    else if(evento->key()==Qt::Key_S)
    {

        coaliciones('S', personaje1);
    }


// qDebug()<<personaje1->pos()<<personaje1->x();

//-------------------------------------------EVENTO PERSONAJE 2 NIVEL 2------------------------------------------------------------
if(evento->key()==Qt::Key_I)
{

    coaliciones('I', personaje2);

}
if(evento->key()==Qt::Key_J)
{
    coaliciones('J', personaje2);


}
if(evento->key()==Qt::Key_L)
{

    coaliciones('L', personaje2);

}
if(evento->key()==Qt::Key_K)
{
    coaliciones('K', personaje2);
}
teletransportacion();
//------------------------------------------------CAMBIO DE NIVEL 2 A 3-------------------------------------------------

/*if (evento->key()==Qt::Key_3)
 {
    clean();
    opcion=3;
    niveles(opcion);
 }*/


}

//-----------------------------------------------EVENTO PERSONAJE 1 NIVEL 3-------------------------------------------------

if (opcion==3)
{
    if(evento->key()==Qt::Key_A)
    {
        coaliciones('A', personaje1);
    }

    else if(evento->key()==Qt::Key_D)
    {

        coaliciones('D', personaje1);

    }
    else if(evento->key()==Qt::Key_W)
    {

        coaliciones('W', personaje1);

    }

    else if(evento->key()==Qt::Key_S)
    {

        coaliciones('S', personaje1);
    }


//---------------------------------------------EVENTO PERSONAJE 2 NIVEL 3------------------------------------------------------------

if(evento->key()==Qt::Key_I)
{

    coaliciones('I', personaje2);

}
if(evento->key()==Qt::Key_J)
{
    coaliciones('J', personaje2);


}
if(evento->key()==Qt::Key_L)
{

    coaliciones('L', personaje2);

}
if(evento->key()==Qt::Key_K)
{

    coaliciones('K', personaje2);

}

teletransportacion();


}
//-----------------------------------------------EVENTO PERSONAJE 1 NIVEL 4-------------------------------------------------

if (opcion==4)
{
        if(evento->key()==Qt::Key_A)
        {
            coaliciones('A', personaje1);
        }

        else if(evento->key()==Qt::Key_D)
        {

            coaliciones('D', personaje1);

        }
        else if(evento->key()==Qt::Key_W)
        {

            coaliciones('W', personaje1);

        }

        else if(evento->key()==Qt::Key_S)
        {

            coaliciones('S', personaje1);
        }

    //---------------------------------------------EVENTO PERSONAJE 2 NIVEL 4------------------------------------------------------------

    if(evento->key()==Qt::Key_I)
    {

        coaliciones('I', personaje2);

    }
    if(evento->key()==Qt::Key_J)
    {
        coaliciones('J', personaje2);


    }
    if(evento->key()==Qt::Key_L)
    {

        coaliciones('L', personaje2);

    }
    if(evento->key()==Qt::Key_K)
    {

        coaliciones('K', personaje2);

    }
   teletransportacion();
    /*if (evento->key()==Qt::Key_5)
     {
        clean();
        opcion=5;
        niveles(5);
     }*/
}
//-----------------------------------------------EVENTO PERSONAJE 1 NIVEL 5-------------------------------------------------

if (opcion==5)
{

          if(evento->key()==Qt::Key_A)
            {
                coaliciones('A', personaje1);
            }

            else if(evento->key()==Qt::Key_D)
            {

                coaliciones('D', personaje1);

            }
            else if(evento->key()==Qt::Key_W)
            {

                coaliciones('W', personaje1);

            }

            else if(evento->key()==Qt::Key_S)
            {

                coaliciones('S', personaje1);
            }


        //---------------------------------------------EVENTO PERSONAJE 2 NIVEL 5------------------------------------------------------------

        if(evento->key()==Qt::Key_I)
        {

            coaliciones('I', personaje2);

        }
        if(evento->key()==Qt::Key_J)
        {
            coaliciones('J', personaje2);


        }
        if(evento->key()==Qt::Key_L)
        {

            coaliciones('L', personaje2);

        }
        if(evento->key()==Qt::Key_K)
        {

            coaliciones('K', personaje2);

        }

teletransportacion();
        /*if (evento->key()==Qt::Key_6)
         {
            clean();
            opcion=6;
            niveles(6);
         }*/

}
//-----------------------------------------------EVENTO PERSONAJE 1 NIVEL 6-------------------------------------------------

if (opcion==6)
{


  if(evento->key()==Qt::Key_A)
    {
        coaliciones('A', personaje1);
    }

    else if(evento->key()==Qt::Key_D)
    {

        coaliciones('D', personaje1);

    }
    else if(evento->key()==Qt::Key_W)
    {

        coaliciones('W', personaje1);

    }

    else if(evento->key()==Qt::Key_S)
    {

        coaliciones('S', personaje1);
    }


//---------------------------------------------EVENTO PERSONAJE 2 NIVEL 6------------------------------------------------------------

if(evento->key()==Qt::Key_I)
{

    coaliciones('I', personaje2);

}
if(evento->key()==Qt::Key_J)
{
    coaliciones('J', personaje2);


}
if(evento->key()==Qt::Key_L)
{

    coaliciones('L', personaje2);

}
if(evento->key()==Qt::Key_K)
{

    coaliciones('K', personaje2);

}
teletransportacion();
/*if (evento->key()==Qt::Key_7)
 {
    clean();
    opcion=7;
    niveles(opcion);
 }*/
    }

if (opcion==7)
{



      if(evento->key()==Qt::Key_A)
        {
            coaliciones('A', personaje1);
        }

        else if(evento->key()==Qt::Key_D)
        {

            coaliciones('D', personaje1);

        }
        else if(evento->key()==Qt::Key_W)
        {

            coaliciones('W', personaje1);

        }

        else if(evento->key()==Qt::Key_S)
        {

            coaliciones('S', personaje1);
        }


    //---------------------------------------------EVENTO PERSONAJE 2 NIVEL 6------------------------------------------------------------

    if(evento->key()==Qt::Key_I)
    {

        coaliciones('I', personaje2);

    }
    if(evento->key()==Qt::Key_J)
    {
        coaliciones('J', personaje2);


    }
    if(evento->key()==Qt::Key_L)
    {

        coaliciones('L', personaje2);

    }
    if(evento->key()==Qt::Key_K)
    {

        coaliciones('K', personaje2);

    }

teletransportacion();

}

if(evento->key()==Qt::Key_0)
{
    guardarPartida();
}

/*if(evento->key()==Qt::Key_1)
{
    clean();
    opcion=1;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_2)
{
    clean();
    opcion=2;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_3)
{
    clean();
    opcion=3;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_4)
{
    clean();
    opcion=4;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_5)
{
    clean();
    opcion=5;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_6)
{
    clean();
    opcion=6;
    niveles (opcion,jugadores);
}
if(evento->key()==Qt::Key_7)
{
    clean();
    opcion=7;
    niveles (opcion,jugadores);
}*/
}

void MainWindow::coaliciones(char letra , Objeto *personaje)
{

    /*if(vida->getlife()==0)
    {
    }*/

    /*if(keys->getkey()==6)
        {
         piedra->hide();
        }*/

   if (personaje==personaje1)
    {

    if (letra=='A')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());

    //---------------------------GIRO DEL PERSONAJE1 (A)------------------------------

    personaje1->setTransformOriginPoint(0,0);
    personaje1->izquierda(1,1);


    //------------------------------COALISIONES1 (A) ----------------------------
    if (bolaH->isVisible())
    {
    if(personaje1->collidesWithItem(bolaH))
    {
    bolaH->izquierda(3,1);
    }
    }

    if (bolafuego->isVisible())
    {
    if(personaje1->collidesWithItem(bolafuego))
    {
    personaje1->derecha(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if (dragon->isVisible())
    {
    if(personaje1->collidesWithItem(dragon))
    {
    personaje1->derecha(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if(enemigo1->isVisible())
    {if(personaje1->collidesWithItem(enemigo1))

        {
        resorte('A', personaje1);
        vida->decrease();
        if (vida->getlife()==0)
        {
            perder();
           ReinicioDEnivel();
        }
        }
     }

    //------------------------EVALUAR COALISIONES CON MUROS 1(A)------------------

    for (int i=0;i<muros.size();i++)
    {
    if (muros.at(i)->isVisible())
    {
    if (personaje1->collidesWithItem(muros.at(i)))
    {

    personaje1->derecha(1,1);
    }
    }
    }


    //--------------------EVALUAR COALISIONES CON PIEDRAS 1(A)--------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (piedras.at(i)->isVisible())
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->derecha(1,1);
    }
    }
    }

    //--------------------------CAPTURAR LLAVES 1(A)-------------------------------
    for (int i=0; i<llavesL.size();i++)
            {if(llavesL.at(i)->isVisible())
                {if (personaje1->collidesWithItem(llavesL.at(i)))
                        {scene->removeItem(llavesL.at(i));
                         llavesL.removeOne(llavesL.at(i));
                         keys->increase();
                         if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                            {keys->setLlave1("0");}
                         if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                            {keys->setLlave2("0");}
                         if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                            {keys->setLlave3("0");}
                         if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                            {keys->setLlave4("0");}
                         if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                            {keys->setLlave5("0");}
                         if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                            {keys->setLlave6("0");}
                        }
                    }
                }

        }
    if (letra=='D')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());

    //--------------------------GIRO DEL PERSONAJE 1(D)---------------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->derecha(1,1);

    //---------------------------COALISIONES 1(D)----------------------------
    if (bolaH->isVisible())
    {
    if(personaje1->collidesWithItem(bolaH))

    {
    bolaH->derecha(3,1);
    }
    }

    if (bolafuego->isVisible())
    {
    if(personaje1->collidesWithItem(bolafuego))
    {
    personaje1->izquierda(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if (dragon->isVisible())
    {
    if(personaje1->collidesWithItem(dragon))
    {
    personaje1->izquierda(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if(enemigo1->isVisible())
    {if(personaje1->collidesWithItem(enemigo1))

        {
        resorte('D', personaje1);
        x = enemigo1->x();
        y = enemigo1->y();
        vida->decrease();
        if (vida->getlife()==0)
        {
           perder();
            ReinicioDEnivel();
        }
        }
      }
    //----------------------EVALUAR COALISIONES CON MUROS 1(D)------------------
    for (int i=0;i<muros.size();i++)
    {
       if (muros.at(i)->isVisible())
        {
    if (personaje1->collidesWithItem(muros.at(i)))
    {



    personaje1->izquierda(1,1);
    }
        }
    }
    //----------------------EVALUAR COALISIONES CON PIEDRAS 1(D)----------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (piedras.at(i)->isVisible())
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->izquierda(1,1);
    }
    }
    }


    //----------------------------CAPTURAR LLAVES 1(D)----------------------------------
    for (int i=0; i<llavesL.size();i++)
            {if(llavesL.at(i)->isVisible())
                {if (personaje1->collidesWithItem(llavesL.at(i)))
                        {scene->removeItem(llavesL.at(i));
                         llavesL.removeOne(llavesL.at(i));
                         keys->increase();
                         if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                            {keys->setLlave1("0");}
                         if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                             {keys->setLlave2("0");}
                          if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                             {keys->setLlave3("0");}
                          if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                             {keys->setLlave4("0");}
                          if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                             {keys->setLlave5("0");}
                          if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                             {keys->setLlave6("0");}
                        }
                    }
                }

        }
    if (letra=='W')
    {
    //-------------------------GIRO DE PERSONAJE 1(W)-----------------------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->subir(1,1);


    //----------------------------COALISIONES 1(W)--------------------------------

    if (bolaH->isVisible())
    {
    if(personaje1->collidesWithItem(bolaH))
    {
    bolaH->subir(3,1);
    }
    }

    if (bolafuego->isVisible())
    {
    if(personaje1->collidesWithItem(bolafuego))
    {
    personaje1->bajar(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }


    if (dragon->isVisible())
    {
    if(personaje1->collidesWithItem(dragon))
    {
    personaje1->bajar(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }


    if(enemigo1->isVisible())
    {if(personaje1->collidesWithItem(enemigo1))
    {
        resorte('W', personaje1);
        vida->decrease();
     }
    }
    //----------------EVALUAR COALISIONES CON MUROS 1(W))-----------------------
    for (int i=0;i<muros.size();i++)
    {
    if (muros.at(i)->isVisible())
    {
    if (personaje1->collidesWithItem(muros.at(i)))
    {
    personaje1->bajar(1,1);
    }
    }
    }
    //-------------------EVALUAR COALISIONES CON PIEDRAS 1(W)---------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (piedras.at(i)->isVisible())
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->bajar(1,1);
    }
    }
    }

    //-----------------------------CAPTURAR LLAVES 1(W)----------------------------
    for (int i=0; i<llavesL.size();i++)

         {
            //qDebug()<<"entra a la lista"<<endl;
            if(llavesL.at(i)->isVisible())

                {
                    //qDebug()<<"es visible"<<endl;
                    if (personaje1->collidesWithItem(llavesL.at(i)))

                        {

                         scene->removeItem(llavesL.at(i));
                         llavesL.removeOne(llavesL.at(i));
                         //qDebug()<<"removido"<<endl;
                         keys->increase();
                         if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                            {
                             //qDebug()<<"get llave 1"<<endl;
                             keys->setLlave1("0");
                            }
                         if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                             {
                             //qDebug()<<"get llave 2"<<endl;
                              keys->setLlave2("0");
                             }
                          if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                             {
                              //qDebug()<<"get llave 3"<<endl;
                              keys->setLlave3("0");
                             }
                          if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                             {
                              //qDebug()<<"get llave 4"<<endl;
                              keys->setLlave4("0");
                             }
                          if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                             {
                              //qDebug()<<"get llave 5"<<endl;
                              keys->setLlave5("0");
                              }
                          if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                             {
                              //qDebug()<<"get llave 6"<<endl;
                              keys->setLlave6("0");
                              }
                        }
                    }
                }

        }
    if (letra=='S')
    {
      //---------------------------GIRO DE PERSONAJE 1(S)---------------------------
      personaje1->setTransformOriginPoint(0,0);
      personaje1->bajar(1,1);


      //------------------------------COALISIONES 1(S)-----------------------------
      if (bolaH->isVisible())
      {
      if(personaje1->collidesWithItem(bolaH))
      {
              bolaH->bajar(3,1);
      }
        }
      if (bolafuego->isVisible())
      {
      if(personaje1->collidesWithItem(bolafuego))
      {
      personaje1->subir(1,1);
      vida->decrease();
      if (vida->getlife()==0)
      {
         perder();
          ReinicioDEnivel();
      }
      }
      }

      if (dragon->isVisible())
      {
      if(personaje1->collidesWithItem(dragon))
      {
      personaje1->subir(1,1);
      vida->decrease();
      if (vida->getlife()==0)
      {
          perder();
          ReinicioDEnivel();
      }
      }
      }

      if(enemigo1->isVisible())
      {
          if(personaje1->collidesWithItem(enemigo1))
         {
              vida->decrease();
              if (vida->getlife()==0)
              {
                  perder();
                  ReinicioDEnivel();
              }
          resorte('S', personaje1);
            }
      }
        //-----------------------EVALUAR COALISIONES CON MUROS 1(S)----------------

      for (int i=0;i<muros.size();i++)
      {
          if (muros.at(i)->isVisible())
          {
          if (personaje1->collidesWithItem(muros.at(i)))
          {

              personaje1->subir(1,1);
          }
          }
      }
      //----------------------EVALUAR COALISIONES CON PIEDRAS 1(S)---------------

      for (int i=0;i<piedras.size();i++)
          {
          if (piedras.at(i)->isVisible())
          {
              if (personaje1->collidesWithItem(piedras.at(i)))
              {

                  personaje1->subir(1,1);
              }
          }
          }

      //--------------------------CAPTURAR LLAVES 1(S)-------------------------
      for (int i=0; i<llavesL.size();i++)
              {if(llavesL.at(i)->isVisible())
                  {if (personaje1->collidesWithItem(llavesL.at(i)))
                        {scene->removeItem(llavesL.at(i));
                           llavesL.removeOne(llavesL.at(i));
                           keys->increase();
                           if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                              {keys->setLlave1("0");}
                           if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                               {keys->setLlave2("0");}
                            if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                               {keys->setLlave3("0");}
                            if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                               {keys->setLlave4("0");}
                            if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                               {keys->setLlave5("0");}
                            if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                               {keys->setLlave6("0");}
                          }
                      }
                  }

          }


    }



   if (personaje==personaje2)
   {

    if (letra=='I')
    {
    //-------------------GIRO DE PERSONAJE 2(I)-------------------
    personaje2->setTransformOriginPoint(0,0);
    personaje2->subir(1,1);


    //--------------------------COALISIONES 2(I)------------------------
    if (bolaH->isVisible())
    {
    if(personaje2->collidesWithItem(bolaH))
    {
    bolaH->subir(3,1);
    }
    }

    if (bolafuego->isVisible())
    {
    if(personaje2->collidesWithItem(bolafuego))
    {
    personaje2->bajar(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if (dragon->isVisible())
    {
    if(personaje2->collidesWithItem(dragon))
    {
    personaje2->bajar(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if(enemigo1->isVisible())
    {if(personaje2->collidesWithItem(enemigo1))

        {
        resorte('I', personaje2);
        vida->decrease();
        if (vida->getlife()==0)
        {
           perder();
            ReinicioDEnivel();
        }
        }
    }
    //-----------------------------EVALUAR COALISIONES CON MUROS 2(I)------------------

    for (int i=0;i<muros.size();i++)
    {
        if (muros.at(i)->isVisible())
        {
        if (personaje2->collidesWithItem(muros.at(i)))
        {
        personaje2->bajar(1,1);
        }
        }
    }

    //-------------------------------EVALUAR COALISIONES CON PIEDRAS 2(I)--------------
    //qDebug() <<"Personaje 2 visible"<<endl;
    for (int i=0;i<piedras.size();i++)
    {
    if (piedras.at(i)->isVisible())
    {
    if (personaje2->collidesWithItem(piedras.at(i)))
    {

    personaje2->bajar(1,1);
    }
    }
    }

    //------------------------------------CAPTURAR LLAVES 2(I)--------------------

    for (int i=0; i<llavesL.size();i++)
            {if(llavesL.at(i)->isVisible())
                {if (personaje2->collidesWithItem(llavesL.at(i)))
                        {scene->removeItem(llavesL.at(i));
                         llavesL.removeOne(llavesL.at(i));
                         keys->increase();
                         if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                            {keys->setLlave1("0");}
                         if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                             {keys->setLlave2("0");}
                          if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                             {keys->setLlave3("0");}
                          if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                             {keys->setLlave4("0");}
                          if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                             {keys->setLlave5("0");}
                          if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                             {keys->setLlave6("0");}
                        }
                    }
                }

        }

    if (letra=='J')
    {
        //---------GIRO DEL PERSONAJE-------
        personaje2->setTransformOriginPoint(0,0);
        personaje2->izquierda(1,1);


        //------------------------COALISIONES 2(J)----------------------------------
        if (bolaH->isVisible())
        {
        if(personaje2->collidesWithItem(bolaH))
        {
        bolaH->izquierda(3,1);
        }
        }

        if (bolafuego->isVisible())
        {
        if(personaje2->collidesWithItem(bolafuego))
        {
        personaje2->derecha(1,1);
        vida->decrease();
        if (vida->getlife()==0)
        {
            perder();
            ReinicioDEnivel();
        }
        }
        }

        if (dragon->isVisible())
        {
        if(personaje2->collidesWithItem(dragon))
        {
        personaje2->derecha(1,1);
        vida->decrease();
        if (vida->getlife()==0)
        {
            perder();
            ReinicioDEnivel();
        }
        }
        }

        if(enemigo1->isVisible())
        {if(personaje2->collidesWithItem(enemigo1))

                {
                resorte('J', personaje2);
                vida->decrease();
                if (vida->getlife()==0)
                {
                    perder();
                    ReinicioDEnivel();
                }
                }
        }
        //-----------------------EVALUAR COALISIONES CON MUROS 2(J)---------------------

        for (int i=0;i<muros.size();i++)
        {
            if (muros.at(i)->isVisible())
            {
            if (personaje2->collidesWithItem(muros.at(i)))
            {
            personaje2->derecha(1,1);
            }
            }
        }
        //-------------------------EVALUAR COALISIONES CON PIEDRAS 2(J)--------------

        for (int i=0;i<piedras.size();i++)
        {
        if (piedras.at(i)->isVisible())
        {
        if (personaje2->collidesWithItem(piedras.at(i)))
        {
        personaje2->derecha(1,1);
        }
       }
        }

        //----------------------------CAPTURAR LLAVES 2(J)-----------------------

        for (int i=0; i<llavesL.size();i++)
                {if(llavesL.at(i)->isVisible())
                    {if (personaje2->collidesWithItem(llavesL.at(i)))
                            {scene->removeItem(llavesL.at(i));
                             llavesL.removeOne(llavesL.at(i));
                             keys->increase();
                             if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                                {keys->setLlave1("0");}
                             if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                                 {keys->setLlave2("0");}
                              if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                                 {keys->setLlave3("0");}
                              if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                                 {keys->setLlave4("0");}
                              if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                                 {keys->setLlave5("0");}
                              if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                                 {keys->setLlave6("0");}
                            }
                        }
                    }

            }


    if (letra=='L')
    {
    //---------GIRO DEL PERSONAJE-------
    personaje2->setTransformOriginPoint(0,0);
    personaje2->derecha(1,1);

    //-------------------------------COALISIONES 2(L) --------------------------------
    if (bolaH->isVisible())
    {
    if(personaje2->collidesWithItem(bolaH))

    {
    bolaH->derecha(3,1);
    }
    }

    if (bolafuego->isVisible())
    {
    if(personaje2->collidesWithItem(bolafuego))
    {
    personaje2->izquierda(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
       perder();
        ReinicioDEnivel();
    }
    }
    }

    if (dragon->isVisible())
    {
    if(personaje2->collidesWithItem(dragon))
    {
    personaje2->izquierda(1,1);
    vida->decrease();
    if (vida->getlife()==0)
    {
        perder();
        ReinicioDEnivel();
    }
    }
    }

    if(enemigo1->isVisible())
    {if(personaje2->collidesWithItem(enemigo1))
        {
        resorte('L', personaje2);
        vida->decrease();
        if (vida->getlife()==0)
        {
           perder();
            ReinicioDEnivel();
        }
        }
    }
    //------------------------EVALUAR COALISIONES CON MUROS 2(L)--------------------------

    for (int i=0;i<muros.size();i++)
    {
        if (muros.at(i)->isVisible())
        {
        if (personaje2->collidesWithItem(muros.at(i)))
        {
        personaje2->izquierda(1,1);
        }
        }
    }
    //---------------------EVALUAR COALISIONES CON PIEDRAS 2(L)----------------------------

    for (int i=0;i<piedras.size();i++)
    {
        if (piedras.at(i)->isVisible())
        {
    if (personaje2->collidesWithItem(piedras.at(i)))
    {
    personaje2->izquierda(1,1);
    }
    }
    }
    //------------------------------CAPTURAR LLAVES 2(L)--------------------------------

    for (int i=0; i<llavesL.size();i++)
            {if(llavesL.at(i)->isVisible())
                {if (personaje2->collidesWithItem(llavesL.at(i)))
                        {scene->removeItem(llavesL.at(i));
                         llavesL.removeOne(llavesL.at(i));
                         keys->increase();
                         if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                            {keys->setLlave1("0");}
                         if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                             {keys->setLlave2("0");}
                          if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                             {keys->setLlave3("0");}
                          if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                             {keys->setLlave4("0");}
                          if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                             {keys->setLlave5("0");}
                          if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                             {keys->setLlave6("0");}
                        }
                    }
                }

        }
    if (letra=='K')
    {
      //---------------------------------GIRO DE PERSONAJE 2(K)----------------------
      personaje2->setTransformOriginPoint(0,0);
      personaje2->bajar(1,1);


      //----------------------------------COALISIONES 2(K)--------------------------------

      if (bolaH->isVisible())
      {
      if(personaje2->collidesWithItem(bolaH))
      {
              bolaH->bajar(3,1);
      }
      }

      if (bolafuego->isVisible())
      {
      if(personaje2->collidesWithItem(bolafuego))
      {
      personaje2->subir(1,1);
      vida->decrease();
      if (vida->getlife()==0)
      {
          perder();
          ReinicioDEnivel();
      }
      }
      }

      if (dragon->isVisible())
      {
      if(personaje2->collidesWithItem(dragon))
      {
      personaje2->subir(1,1);
      vida->decrease();
      if (vida->getlife()==0)
      {
          perder();
          ReinicioDEnivel();
      }
      }
      }

      if(enemigo1->isVisible())
      {if(personaje2->collidesWithItem(enemigo1))
        {vida->decrease();
              if (vida->getlife()==0)
              {
                  perder();
                  ReinicioDEnivel();
              }
         resorte('K', personaje2);
        }
      }
        //--------------------------EVALUAR COALISIONES CON MUROS 2(K)--------------------------


      for (int i=0;i<muros.size();i++)
      {
          if (muros.at(i)->isVisible())
          {
          if (personaje2->collidesWithItem(muros.at(i)))
          {personaje2->subir(1,1);
          }
      }
      }
      //-----------------------------EVALUAR COALISIONES CON PIEDRAS 2(K)----------------------
      for (int i=0;i<piedras.size();i++)
          {
            if (piedras.at(i)->isVisible())
            {
              if (personaje2->collidesWithItem(piedras.at(i)))
              {
                  personaje2->subir(1,1);
              }
            }
          }

      //-----------------------------CAPTURAR LLAVES 2(K)------------------------------------
      for (int i=0; i<llavesL.size();i++)
              {if(llavesL.at(i)->isVisible())
                  {if (personaje2->collidesWithItem(llavesL.at(i)))
                          {scene->removeItem(llavesL.at(i));
                           llavesL.removeOne(llavesL.at(i));
                           keys->increase();
                           if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                              {keys->setLlave1("0");}
                           if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                               {keys->setLlave2("0");}
                            if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                               {keys->setLlave3("0");}
                            if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                               {keys->setLlave4("0");}
                            if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                               {keys->setLlave5("0");}
                            if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                               {keys->setLlave6("0");}
                          }
                      }
                  }

          }
   }

}

//------------------------------------------------------NIVELES--------------------------------------------------

void MainWindow::registro()
{
    regis=new Registro(this);
    regis->show();
}

void MainWindow::continuar()
{
    Verificar *verificar=new Verificar;
    verificar=new Verificar (this);


    verificar->show();

}

void MainWindow::setnivel(int opcion_)
{
    opcion=opcion_;
    niveles (opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::SETMODO(int modoo)
{
    jugadores=modoo;
    //qDebug()<<"cantidad de jugadores CUANDO INICIO "<<jugadores;
    niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::VIDAS(int opcion_)
{
    //qDebug()<<"vidas despues de guardar"<<opcion_;

    vida->setLife(opcion_);
}

void MainWindow::LLAVES(int opcion_)
{
    //qDebug()<<"llaves despues de guardar"<<opcion_;
  keys->setKey(opcion_);
  if (keys->getkey()==5)
  {
  for (int i=0; i<piedras.size();i++)
  {
  if (piedras.at(i)->posx==175 and piedras.at(i)->posy==30)
  {

      piedras.at(i)->hide();


  }
  }
  }
}

void MainWindow::TIEMPO(int opcion_)
{
    //qDebug()<<"Tiempo después de guardar"<<opcion_;

    tiempo->settime(opcion_);
}

void MainWindow::L1(int nive1)
{    nivel1=nive1;
     //qDebug()<<"Nivel1 después de guardar"<<nivel1;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::L2(int nive2)
{    nivel2=nive2;
     //qDebug()<<"Nivel2 después de guardar"<<nivel2;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::L3(int nive3)
{    nivel3=nive3;
     //qDebug()<<"Nivel3 después de guardar"<<nivel3;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::L4(int nive4)
{    nivel4=nive4;
     //qDebug()<<"Nivel4 después de guardar"<<nivel4;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::L5(int nive5)
{    nivel5=nive5;
     //qDebug()<<"Nivel5 después de guardar"<<nivel5;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::L6(int nive6)
{    nivel6=nive6;
     //qDebug()<<"Nivel6 después de guardar"<<nivel6;
     niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
}

void MainWindow::llavesGuardadas(QString l1, QString l2, QString l3, QString l4, QString l5, QString l6)
{
    keys->setLlave1(l1);
    keys->setLlave2(l2);
    keys->setLlave3(l3);
    keys->setLlave4(l4);
    keys->setLlave5(l5);
    keys->setLlave6(l6);

}

void MainWindow::Iniciar()
{
    Verificar *verificar;
    verificar=new Verificar (this);
    verificar->show();
}

void MainWindow::guardar()
    {

        arch =false;

            QString  nivel= QString::number(opcion);
            //QString nivel="7";

            QString contrasena=user->getContrasena();

            QString modo=user->getModoDeJuego();

            QString usu=user->getNombre();

            QString niv1=keys->getLlave1();

            QString niv2=keys->getLlave2();

            QString niv3=keys->getLlave3();

            QString niv4=keys->getLlave4();

            QString niv5=keys->getLlave5();

            QString niv6=keys->getLlave6();

            QString VIDAS=QString::number(vida->getlife()); //LLAVES,VIDAS Y TIEMPO QUE DEBE RECIBIR EL ARCHIVO

            QString LLAVES=QString::number(keys->getkey());

            QString TIEMPO=QString::number(tiempo->gettime());

            //user=new Usuario;
            user->setNivel(nivel);

            QList<QString>cont_nivel={contrasena,nivel};

        //qDebug()<<"name "<< usu<<" pass "<<contrasena<<" level"<<nivel<<"vidas"<<VIDAS <<"LLAVES"<<LLAVES<<"TIEMPO"<<TIEMPO<<"NIVEL1"<<niv1<<"NIVEL2"<<niv2<<"NIVEL3"<<niv3<<"NIVEL4"<<niv4<<"NIVEL5"<<niv5<<"NIVEL6"<<niv6;



       // QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
        QFile writearchivo("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
        QFile readarchivo("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
        QFile readcambios("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/cambios.txt");
        QFile writecambios("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/cambios.txt");
       // QFile cambios1("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/cambios.txt");
       // archivo.open(QIODevice::ReadOnly | QIODevice::Text);

        writearchivo.open(QIODevice::WriteOnly | QIODevice::WriteOnly);
        readarchivo.open(QIODevice::WriteOnly | QIODevice::ReadOnly);

        readcambios.open(QIODevice::ReadOnly | QIODevice::ReadOnly);
        writecambios.open(QIODevice::ReadOnly | QIODevice::WriteOnly);

      //  cambios1.open(QIODevice::ReadOnly | QIODevice::WriteOnly);
       // QTextStream datosArchivo (&archivo);
        QTextStream WRITEARCHIVO (&writearchivo);
        QTextStream READARCHIVO (&readarchivo);

        QTextStream READCAMBIOS (&readcambios);
         QTextStream WRITECAMBIOS (&writecambios);


        //QString linea= CAMBIOS.readLine();
        while (!READCAMBIOS.atEnd())
        {

                READCAMBIOS>>ArchivoUsuario>>passArchivo>>nivelUsuario>>mode>>Vidas>>Llaves>>Tiempo>>LEVEL1>>LEVEL2>>LEVEL3>>LEVEL4>>LEVEL5>>LEVEL6;

             //qDebug()<<"name "<< ArchivoUsuario<<" pass "<<passArchivo<<" level "<<nivelUsuario;
            if (usu==ArchivoUsuario)
            {

            WRITEARCHIVO<<usu<<" "<<contrasena<<" "<<nivel<<" "<<modo<<" "<<VIDAS<<" "<<LLAVES<<" "<<TIEMPO<<" "<<niv1<<" "<<niv2<<" "<<niv3<<" "<<niv4<<" "<<niv5<<" "<<niv6<<" "<<endl;
            //write2<<usu<<" "<<contrasena<<" "<<nivel<<" "<<modo<<endl;
            opcionArchivo=0;
             /*QMessageBox::warning(this, tr(""),
                                           tr("CAMBIO REALIZADO EN REGISTRO"),

                                           QMessageBox::Cancel);*/

            }
            else
            {
                //DEJO EL REGISTRO IGUAL SI ESE USUARIO NO SE LE MODIFICÓ EL NIVEL
                          WRITEARCHIVO<< ArchivoUsuario<<" "<<passArchivo<<" "<<nivelUsuario<<" "<<mode<<" "<<Vidas<<" "<<Llaves<<" "<<Tiempo<<" "<<LEVEL1<<" "<<LEVEL2<<" "<<LEVEL3<<" "<<LEVEL4<<" "<<LEVEL5<<" "<<LEVEL6<<" "<<endl;
            }

        }
        while (!READARCHIVO.atEnd())
        {
             READARCHIVO>>ArchivoUsuario1>>passArchivo1>>nivelUsuario1>>mode1>>vidas1>>llaves1>>tiempo1>>NIV1>>NIV2>>NIV3>>NIV4>>NIV5>>NIV6>>endl;
            if (usu==ArchivoUsuario1)
            {
                 WRITECAMBIOS<<usu<<" "<<contrasena<<" "<<nivel<<" "<<modo<<" "<<VIDAS<<" "<<LLAVES<<" "<<TIEMPO<<" "<<niv1<<" "<<niv2<<" "<<niv3<<" "<<niv4<<" "<<niv5<<" "<<niv6<<" "<<endl;
                opcionArchivo=0;
               /* QMessageBox::warning(this, tr(""),
                                              tr("CAMBIO REALIZADO EN CAMBIOS"),

                                              QMessageBox::Cancel);*/
            }
            else
            {
               WRITECAMBIOS<<ArchivoUsuario1<<" "<<passArchivo1<<" "<<nivelUsuario1<<" "<<mode1<<" "<<vidas1<<" "<<llaves1<<" "<<tiempo1<<" "<<NIV1<<" "<<NIV2<<" "<<NIV3<<" "<<NIV4<<" "<<NIV5<<" "<<NIV6<<" "<<endl;
            }
        }

        if (opcionArchivo==1)
        {
            /*QMessageBox::warning(this, tr(""),
                                          tr("N "),

                                          QMessageBox::Cancel);*/
            /*QMessageBox::warning(this, tr(" "),
                                          tr("R"),*/
           /* hide();
            QMap<QString,QList<QString>> registro;
            registro[usu]=cont_nivel;
           escribir<<usuario<<" "<<contrasena<<" "<<nivel<<endl;
           QMessageBox::warning(this, tr("REGISTRO VÁLIDO"),
                                         tr("REGISTRO EXITOSO"),

                                         QMessageBox::Cancel);*/

        }
    }

void MainWindow::guardarPartida()
{
    QString level, R;


    level=QString::number(opcion);
     QFile archivo("PARTIDA.txt");
    if(archivo.open(QIODevice::Append | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);


            datosArchivo << level<< endl;

        }
    archivo.close();
}

void MainWindow::setUser(Usuario *value)
{
    user = value;
}

void MainWindow::ganar()
{
    Win *gana;
    gana=new Win (this);
    gana->show();
    arch =false;
    ReinicioDEnivel();


}

void MainWindow::ReinicioDEnivel()
{   arch=false;
    QString  nivel= QString::number(opcion);
    //QString nivel="7";

    QString contrasena=user->getContrasena();

    QString modo=user->getModoDeJuego();

    QString usu=user->getNombre();

   // qDebug()<<"modo"<<modo;

    QString VIDAS=QString::number(vida->getlife()); //LLAVES Y VIDAS QUE DEBE RECIBIR EL ARCHIVO

    QString LLAVES=QString::number(keys->getkey());

    //user=new Usuario;
    user->setNivel(nivel);

    QList<QString>cont_nivel={contrasena,nivel};

//qDebug()<<"name "<< usu<<" pass "<<contrasena<<" level"<<nivel<<"vidas"<<VIDAS <<"LLAVES"<<LLAVES;



   // QFile archivo ("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/registro.txt");
    QFile writearchivo("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
    QFile readarchivo("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/registro.txt");
    QFile readcambios("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/cambios.txt");
    QFile writecambios("D:/E-MEDIEVAL/E-MEDIEVAL/REGISTRO/cambios.txt");
   // QFile cambios1("C:/Users/Usuario/Desktop/Nueva carpeta (2)/E-M/REGISTRO/cambios.txt");
   // archivo.open(QIODevice::ReadOnly | QIODevice::Text);

    writearchivo.open(QIODevice::WriteOnly | QIODevice::WriteOnly);
    readarchivo.open(QIODevice::WriteOnly | QIODevice::ReadOnly);

    readcambios.open(QIODevice::ReadOnly | QIODevice::ReadOnly);
    writecambios.open(QIODevice::ReadOnly | QIODevice::WriteOnly);

  //  cambios1.open(QIODevice::ReadOnly | QIODevice::WriteOnly);
   // QTextStream datosArchivo (&archivo);
    QTextStream WRITEARCHIVO (&writearchivo);
    QTextStream READARCHIVO (&readarchivo);

    QTextStream READCAMBIOS (&readcambios);
     QTextStream WRITECAMBIOS (&writecambios);


    //QString linea= CAMBIOS.readLine();
    while (!READCAMBIOS.atEnd())
    {

        READCAMBIOS>>ArchivoUsuario>>passArchivo>>nivelUsuario>>mode>>Vidas>>Llaves;

         //qDebug()<<"name "<< ArchivoUsuario<<" pass "<<passArchivo<<" level "<<nivelUsuario<<" modo "<<mode<<" vidas "<<Vidas<<" llaves "<<Llaves;
        if (usu==ArchivoUsuario)
        {

        WRITEARCHIVO<<usu<<" "<<contrasena<<" "<<"1"<<" "<<modo<<" "<<"5"<<" "<<"0"<<endl; //MODIFICO EL REGISTRO PARA INGRESAR CON NUEVO NIVEL
        //write2<<usu<<" "<<contrasena<<" "<<nivel<<" "<<modo<<endl;
        opcionArchivo=0;

        }
        else
        {
            //DEJO EL REGISTRO IGUAL SI ESE USUARIO NO SE LE MODIFICÓ EL NIVEL
            WRITEARCHIVO<< ArchivoUsuario<<" "<<passArchivo<<" "<<nivelUsuario<<" "<<mode<<" "<<Vidas<<" "<<Llaves<<endl;
        }

    }
    while (!READARCHIVO.atEnd())
    {
        READARCHIVO>>ArchivoUsuario1>>passArchivo1>>nivelUsuario1>>mode1>>vidas1>>llaves1>>endl;
        if (usu==ArchivoUsuario1)
        {
            WRITECAMBIOS<<usu<<" "<<contrasena<<" "<<"1"<<" "<<modo<<" "<<"5"<<" "<<"0"<<endl;
            opcionArchivo=0;

        }
        else
        {
            WRITECAMBIOS<<ArchivoUsuario1<<" "<<passArchivo1<<" "<<nivelUsuario1<<" "<<mode1<<" "<<vidas1<<" "<<llaves1<<" "<<endl;
        }
    }


}

void MainWindow::perder()
{
    Lose *pierde;
    pierde=new Lose (this);
    pierde->show();;
    arch =false;
    ReinicioDEnivel();
    this->close();
}

void MainWindow::instrucciones()
{
    Instrucciones *instr;
    instr=new Instrucciones (this);
    instr->show();


}

//------------------------------------------------------NIVELES--------------------------------------------------


void MainWindow:: niveles(int opcion,int jugadores,int nivel1,int nivel2,int nivel3,int nivel4,int nivel5,int nivel6)
{
    if (opcion==0)
    {
        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (actualizar()));
        timer->start(1440);

        //..................CREANDO LA ESCENA.............

        scene->setBackgroundBrush(QPixmap(":/I/I/MAINMENU.png"));
        if (opcion==0)
        {
         scene->setSceneRect(0,0,790,550);

        }

       // 310,300
        //LLAVE

        personaje1=new Objeto(180,410,30, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);
        personaje1->hide();

        personaje2=new Objeto(180,410,30, ":/I/I/PERSONAJE2.png");
        scene->addItem(personaje2);
        personaje2->hide();

        enemigo1= new Objeto (475,225,60,":/I/I/ENEMIGO.png");
        scene->addItem(enemigo1);
        enemigo1->hide();

        dragon= new Objeto (305,180,40,":/I/I/dragon.png");
        scene->addItem(dragon);
        dragon->hide();

        bolaH= new Objeto (-25,420, 30,":/I/I/BOLADEMETAL.png");
        scene->addItem(bolaH);
        bolafuego= new Particula (505,505,200,30,":/I/I/BOLADEFUEGO.png");
        scene->addItem(bolafuego);

        //intro=new QMediaPlayer ();
        //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


        //intro->play();

        muros.push_back(new Pared (200,-450,800,100, ""));
        scene->addItem(muros.back());

        muros.push_back(new Pared (200,150,800,100, ""));
        scene->addItem(muros.back());

        muros.push_back(new Pared (250,100,100,800, ""));
        scene->addItem(muros.back());

        muros.push_back(new Pared (-550,100,100,800, ""));
        scene->addItem(muros.back());

        for (int i=0;i<muros.size();i++)
            {
            muros.at(i)->hide();

            }

        piedras.push_back(new Objeto(175,30,40,":/I/I/P1.png"));
        scene->addItem(piedras.back());

        //CANTIDAD DE VIDAS
        vida=new vidas();
        vida->setLife(5);
        vida->setPos(200,-90);
        scene->addItem(vida);
        vida->hide();


        //CANTIDAD DE LLAVES
        keys=new llaves();
        keys->setKey(0);
        keys->setPos(70,-90);
        scene->addItem(keys);

        //CANTIDAD DE Tiempo
        tiempo=new Timer();
        tiempo->settime(313);
        tiempo->setPos(435,-90);

    }
    if (opcion==1)
    {

        //------------------------SONIDOS-----------------
            //intro->stop();
            //key=new QMediaPlayer ();
            //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

            //------------------------TIMER------------------
            //timer= new QTimer;
            //connect(timer,SIGNAL(timeout()), this, SLOT (actualizar()));
            //timer->start(1440);


            scene->setSceneRect(0,0,400,400);
            scene->setBackgroundBrush(QPixmap(":/I/I/LN1.jpg"));
            start->hide();
            instruccion->hide();
            registrar->hide();



            vida->show();
            //qDebug()<<"numero de jugadores"<<jugadores<<endl;
            if(jugadores==2)
               {scene->addItem(tiempo);
                personaje2->setPos(-120,420);
                personaje2->show();
               }

            bolaH->hide();
            scene->addItem(vida);
            scene->addItem(keys);

            personaje1->setPos(-120,420);
            personaje1->show();

            for (int i=0; i<llavesL.size();i++)
                {

                    if(keys->getLlave2()=="1")
                    {

                        if (llavesL.at(i)->getPosx()==-65 and llavesL.at(i)->getPosy()==220)
                        {
                                llavesL.at(i)->show();
                        }
                else
                    {
                            llavesL.at(i)->hide();
                    }
                    }
                 else
                 {   llavesL.at(i)->hide();

                 }

                }

            //vida->show();
            //vida->setPos(120,35);

            for (int i=0; i<piedras.size();i++)
                {if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
                        {piedras.at(i)->hide();
                        }
                }

            enemigo1->setPos(475,225);
            enemigo1->show();

           dragon->setPos(305,180);
            dragon->show();

            /*bolafuego= new Particula (0,505,505,200,30,":/I/I/BOLA DE FUEGO.png");
            scene->addItem(bolafuego);*/

            rigidez=3;
            friccion=10;
            xmenor=60;
            xmayor=330;
            /*piedras.push_back(new Objeto(170,35,40,":/I/I/ROCAS.png"));
            scene->addItem(piedras.back());
            piedras.back()->hide();*/

            items();

            teletransportacion();


    }
    if (opcion==2)
    {



        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        /*timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);


        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
       scene->setBackgroundBrush(QPixmap(":/I/I/LN1.jpg"));
        scene->setSceneRect(0,0,400,400);

        personaje1=new Personaje(180,410,30, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);

        personaje2=new Personaje(0,0,45, ":/I/I/PERSONAJE2.png");
        scene->addItem(personaje2);

        llave= new Objeto (470,35,30,":/I/I/llave1.png");
        scene->addItem(llave);*/
        scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/HIELO.png"));
        start->hide();
        instruccion->hide();
        registrar->hide();

        bolaH->hide();

        if(jugadores==2)
           {scene->addItem(tiempo);
            personaje2->setPos(360,420);
            personaje2->show();
           }
        qDebug()<<"LLAVES N2"<<keys->getkey();
        for (int i=0; i<piedras.size();i++)
            {
                if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
                    {
                        piedras.at(i)->show();
                    }
                else if (keys->getkey()==5)
                     {
                        for (int i=0; i<piedras.size();i++)
                            {
                                if (piedras.at(i)->posx==175 and piedras.at(i)->posy==30)
                                    {

                                        piedras.at(i)->hide();


                                    }
                            }
                     }
            }

        personaje1->show();
        personaje1->setPos(360,420);

        enemigo1->hide();

        dragon->show();
        scene->addItem(dragon);
        bolafuego->setPos(305,180);

        for (int i=0; i<llavesL.size();i++)
            {if(keys->getLlave3()=="1")
                {if (llavesL.at(i)->getPosx()==470 and llavesL.at(i)->getPosy()==35)
                    {llavesL.at(i)->show();
                    }
                else
                    {llavesL.at(i)->hide();
                    }
                }
            else
                {llavesL.at(i)->hide();
                }
            }

        vida->show();
        //vida->setPos(120,35);

        keys->setPos(70,-90);
        scene->addItem(keys);

        rigidez=4;
        friccion=20;
        ymenor=-15;
        ymayor=420;
        xmayor=520;
        xmenor=-35;
        items();

        teletransportacion();

    }
    if (opcion==3)
    {




        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        /*timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);*/

        scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/H1.jpg"));
        start->hide();
        instruccion->hide();
        registrar->hide();
        vida->show();

        if(jugadores==2)
           {scene->addItem(tiempo);
            personaje2->setPos(-120,420);
            personaje2->show();
           }

        for (int i=0; i<piedras.size();i++)
            {
             if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
               {
                piedras.at(i)->hide();
                }
            }

        for (int i=0; i<llavesL.size();i++)
            {if(keys->getLlave4()=="1")
                {if (llavesL.at(i)->getPosx()==480 and llavesL.at(i)->getPosy()==45)
                    {llavesL.at(i)->show();
                    }
                else
                    {llavesL.at(i)->hide();
                    }
                }
            else
                {llavesL.at(i)->hide();
                }
            }


        personaje1->show();
        personaje1->setPos(-120,420);

        enemigo1->show();
        enemigo1->setPos(-120,80);
        dragon->setPos(435,270);
       dragon->show();

        bolafuego->setPos(-20,345);
        bolaH->hide();

        /*totem= new Personaje (0,0,60,"");
        scene->addItem(totem);
        timer->start();*/

        rigidez=1;
        friccion=20;
        xmenor=-120;
        xmayor=520;
        ymayor=350;
        ymenor=-5;
        items();

        teletransportacion();



    }
    if (opcion==4)
    {
        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        /*timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);

        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;*/
        scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/ARENA.jpg"));
        start->hide();
        instruccion->hide();
        registrar->hide();
        vida->show();

        for (int i=0; i<piedras.size();i++)
            {
             if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
               {
                piedras.at(i)->hide();
                }
            }

        if(jugadores==2)
           {scene->addItem(tiempo);
            personaje2->setPos(180,420);
            personaje2->show();
           }

        for (int i=0; i<llavesL.size();i++)
            {if(keys->getLlave5()=="1")
                {if (llavesL.at(i)->getPosx()==490 and llavesL.at(i)->getPosy()==55)
                    {llavesL.at(i)->show();
                    }
                else
                    {llavesL.at(i)->hide();
                    }
                }
            else
                {llavesL.at(i)->hide();
                }
            }

        bolaH->hide();
       enemigo1->show();
        enemigo1->setPos(-120,105);

        personaje1->show();
        personaje1->setPos(180,420);
        bolafuego->setPos(-20,345);
        xmenor=-120;
        xmayor=520;
        ymayor=350;
        ymenor=5;
        rigidez=6;
        friccion=10;

        items();

        teletransportacion();

    }
    if (opcion==5)
    {
        //qDebug()<<" ENTRO AL NIVEL 5";
        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/L3.jpg"));

        start->hide();
        instruccion->hide();
        registrar->hide();
        vida->show();

        for (int i=0; i<piedras.size();i++)
            {
             if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
               {
                piedras.at(i)->hide();
                }
            }

        if(jugadores==2)
           {scene->addItem(tiempo);
            personaje2->setPos(-120,420);
            personaje2->show();
           }

        personaje1->setPos(-120,420);
        personaje1->show();

        enemigo1->show();
        enemigo1->setPos(100,10);
        bolaH->setPos(0,215);
        bolaH->show();

        bolafuego->setX(165);

        dragon->setPos(355,215);
        dragon->show();
         //qDebug()<<"LLAVES CUANDO ENTRA AL NIVEL "<<keys->getLlave1()<<" "<<keys->getLlave2()<<" "<<keys->getLlave3()<<" "<<keys->getLlave4()<<" "<<keys->getLlave5()<<" "<<keys->getLlave6()<<endl;
        for (int i=0; i<llavesL.size();i++)
             {
                if(keys->getLlave6()=="1")
                {
                    //qDebug()<<"MOSTRANDO LA LLAVE 5"<<endl;
                if (llavesL.at(i)->getPosx()==10 and llavesL.at(i)->getPosy()==100)
                    {
                    llavesL.at(i)->show();

                    }
                else
                    {
                    llavesL.at(i)->hide();
                    }
                }
            else
                {
                llavesL.at(i)->hide();

                }
            }

        keys->setPos(70,-90);
        scene->addItem(keys);
        xmenor=55;
        xmayor=320;
        ymenor=110;
        ymayor=370;
        rigidez=3;
        friccion=20;
        items();

        teletransportacion();


    }
    if (opcion==6)
    {
        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/L7.png"));
        start->hide();
        instruccion->hide();
        registrar->hide();
        vida->show();

        for (int i=0; i<piedras.size();i++)
            {
             if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
               {
                piedras.at(i)->hide();
                }
            }

        if(jugadores==2)
           {scene->addItem(tiempo);
            personaje2->setPos(-120,420);
            personaje2->show();
           }

        /*for (int i=0; i<llavesL.size();i++)
             {
                if(keys->getLlave1()=="1")
                {
                    qDebug()<<"MOSTRANDO LA LLAVE 5"<<endl;
                if (llavesL.at(i)->getPosx()==460 and llavesL.at(i)->getPosy()==25)
                    {
                    llavesL.at(i)->show();

                    }
                else
                    {
                    llavesL.at(i)->hide();
                    }
                }
            else
                {
                llavesL.at(i)->hide();

                }
            }
        */


        personaje1->show();
        personaje1->setPos(-120,420);

        enemigo1->show();
        enemigo1->setPos(-95,125);

        dragon->show();
        dragon->setPos(445,360);
        bolafuego->setPos(-5,345);
        bolaH->hide();
        bolafuego->setX(95);
        xmenor=-120;
        xmayor=520;
        ymenor=-45;
        ymayor=410;
        rigidez=1;
        friccion=30;

        items();

        teletransportacion();

    }
    if (opcion==7)
    {
        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

       scene->setSceneRect(0,0,400,400);
        scene->setBackgroundBrush(QPixmap(":/I/I/LAVA1.png"));

        for (int i=0; i<piedras.size();i++)
            {
             if (piedras.at(i)->getPosx()==175 and piedras.at(i)->getPosy()==30)
               {
                piedras.at(i)->hide();
                }
            }

        start->hide();
        instruccion->hide();
        registrar->hide();
        bolaH->hide();
        vida->show();

        if (personaje1->x()==520 and personaje1->y()==360) //puerta derecha conexión parte de arriba
                {
                personaje1->setPos(520,60);
                }
         if (personaje1->x()==-120 and personaje1->y()==60) //puerta final
                {
                ganar();
                ReinicioDEnivel();
                this->close();
                }

         if(jugadores==2)
            {scene->addItem(tiempo);
             personaje2->setPos(-115,350);
             personaje2->show();
            }

        enemigo1->setPos(-95,105);
        enemigo1->show();

        dragon->setPos(320,355);
        dragon->show();

        personaje1->setPos(-115,350);
        personaje1->show();

        xmenor=-50;
        xmayor=520;
        ymayor=350;
        rigidez=11;
        friccion=30;

        items();
        teletransportacion();

    }
}

void MainWindow::items()
{

   /* llave= new Objeto (470,35,30,":/IMAGENES/llave1.png");
    scene->addItem(llave);*/

    for (int i=0;i<muros.size();i++)
        { if(muros.at(i)->getPosx()==200 and muros.at(i)->getPosy()==-450)
            {muros.at(i)->show();
             scene->addItem(muros.at(i));}

          else if(muros.at(i)->getPosx()==200 and muros.at(i)->getPosy()==150)
                    {muros.at(i)->show();
                    scene->addItem(muros.at(i));}

          else if(muros.at(i)->getPosx()==250 and muros.at(i)->getPosy()==100)
                    {muros.at(i)->show();
                    scene->addItem(muros.at(i));}

          else if(muros.at(i)->getPosx()==-550 and muros.at(i)->getPosy()==100)
                    {muros.at(i)->show();
                    scene->addItem(muros.at(i));}

          else
            {muros.at(i)->hide();}
        }

    if (opcion==1)
    {
        piedras.push_back(new Objeto(-100,320,40,":/I/I/P1.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-15,290,40,":/I/I/P1.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(0,200,40,":/I/I/P1.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-50,120,40,":/I/I/P1.png"));
        scene->addItem(piedras.back());

        muros.push_back(new Pared (-350,50,50,800, ":/I/I/rocas2.png")); //muro vertical
        scene->addItem(muros.back());

        muros.push_back(new Pared (-120,50,20,50, ":/I/I/BLOQUE.jpg")); //abajo derecha conexion nivel 5
        scene->addItem(muros.back());

        muros.push_back(new Pared (-200,50,20,50, ":/I/I/BLOQUE.jpg")); //abajo izqu conexion nivel 5
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-10,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 4 ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-160,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 2 arriba ancho alto conex n 2
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-250,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 3 abajo ancho alto conex nivel 2
        scene->addItem(muros.back());
    }

    if (opcion==2)
    {
        muros.push_back(new Pared (-120,50,20,50, ":/I/I/BLOQUE.jpg")); //arriba conex nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (-200,50,20,50, ":/I/I/BLOQUE.jpg")); //arriba izq conex nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (90,-400,20,50, ":/I/I/BLOQUE.jpg")); //abajo izqu //-200
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-150,50,20, ":/I/I/BLOQUE.jpg")); //derecha arriba
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-230,50,20, ":/I/I/BLOQUE.jpg")); //derecha abajo
        scene->addItem(muros.back());

        for (int i=0;i<piedras.size();i++)
        {
        if (piedras.at(i)->x()==170 and piedras.at(i)->y()==35)
        {
            piedras.at(i)->show();
        }
        }
    }

    if (opcion==3)
    {

        muros.push_back(new Pared (150,-160,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 5 arriba ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-250,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 5 abajo ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (-420,-400,30,50, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 4 izqu abajo ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (-520,-400,30,50, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 4 derecha abajo ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (-50,-150,200,50, ":/I/I/BLOQUE.jpg")); //muro centro arriba
        scene->addItem(muros.back());

        muros.push_back(new Pared (-50,-150,50,300, ":/I/I/BLOQUE.jpg")); //muro centro  izquierda
        scene->addItem(muros.back());

        muros.push_back(new Pared (-250,-150,50,150, ":/I/I/BLOQUE.jpg")); //muro centro derecha
        scene->addItem(muros.back());

    }

    if (opcion==4)
    {
        //_------ muros extra
        muros.push_back(new Pared (-100,-300,50,200, ":/I/I/BLOQUE.jpg")); //VERTICAL ABAJO
        scene->addItem(muros.back());

        //muros.push_back(new Pared (150,-300,300,50, ":/IMAGENES/BLOQUE.jpg")); //HORIZONTAL ABAJO
        //scene->addItem(muros.back());


        //muros puertas

        muros.push_back(new Pared (150,-10,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 1 ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (-220,50,30,50, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 3
        scene->addItem(muros.back());

    }

    if (opcion==5)
    {
        /* muros.push_back(new Pared (0,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro derecha conexion nivel 7
         scene->addItem(muros.back());
         muros.push_back(new Pared (-320,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro izquierda conexion nivel 7
         scene->addItem(muros.back());*/

         muros.push_back(new Pared (-120,-400,20,50, ":/I/I/BLOQUE.jpg")); //abajo derecha conexion nivel 1
         scene->addItem(muros.back());

         muros.push_back(new Pared (-200,-400,20,50, ":/I/I/BLOQUE.jpg")); //abajo izqu conexion nivel 1
         scene->addItem(muros.back());

         muros.push_back(new Pared (150,-160,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 2 arriba ancho alto conex n 2
         scene->addItem(muros.back());

         muros.push_back(new Pared (150,-250,50,30, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 3 abajo ancho alto conex nivel 2
         scene->addItem(muros.back());

         muros.push_back(new Pared (-500,-150,50,20, ":/I/I/BLOQUE.jpg")); //derecha arriba conex nivel 3
         scene->addItem(muros.back());

         muros.push_back(new Pared (-500,-230,50,20, ":/I/I/BLOQUE.jpg")); //derecha abajo conex nivel 3
         scene->addItem(muros.back());




         //muros.push_back(new Pared (0,200,50,800, ":/IMAGENES/BLOQUE.jpg"));
         //scene->addItem(muros.back());

    }

    if (opcion==6)
    {

        muros.push_back(new Pared (30,200,50,400, ":/I/I/BLOQUE.jpg")); //centro derecha conexion nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (-370,200,50,400, ":/I/I/BLOQUE.jpg")); //centro izquierda conexion nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (-170,-200,50,400, ":/I/BLOQUE.jpg")); //centro izquierda conexion nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-200,50,20, ":/I/I/BLOQUE.jpg")); //derecha arriba conex nivel 1
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-280,50,20, ":/I/I/BLOQUE.jpg")); //derecha abajo conex nivel 1
        scene->addItem(muros.back());


        muros.push_back(new Pared (85,50,30,50, ":/I/I/BLOQUE.jpg")); //puerta conexion nivel 2
        scene->addItem(muros.back());

        boton=new Objeto(255,420,40,"");
    }

    if (opcion==7)
    {
        muros.push_back(new Pared (200,-200,800,50, ":/I/I/rocas2.png")); //muro centro
        scene->addItem(muros.back());

        muros.push_back(new Pared (85,-400,30,50, ":/I/I/BLOQUE.jpg")); //puerta abajo conexion nivel 2
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-0,50,30, ":/I/I/BLOQUE.jpg")); //puerta final
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-90,50,30, ":/I/I/BLOQUE.jpg")); //Puerta final
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-10,50,20, ":/I/I/BLOQUE.jpg")); //puerta segunda parte derecha (arriba)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-90,50,20, ":/I/I/BLOQUE.jpg")); //puerta segunda parte derecha (abajo)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-310,50,20, ":/I/I/BLOQUE.jpg")); //puerta primera parte derecha (arriba)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-390,50,20, ":/I/I/BLOQUE.jpg")); //puerta primera parte derecha (abajo)
        scene->addItem(muros.back());
    }

}

void MainWindow::clean()
{
     for (int i=0;i<piedras.size();i++)
         {
         piedras.at(i)->hide();
         }


}

void MainWindow::teletransportacion()
{   qDebug()<<"jugadores moodo"<<jugadores;
    if (jugadores==1)
    {if (opcion==1)
    {
        if (personaje1->x()==170 and personaje1->y()==-20) //puerta arriba //conexion nivel 5
        {

            clean();

            opcion=5;
            niveles(opcion, jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(170,345);
            personaje2->setPos(115,350);
        }

        if (personaje1->x()==520 and personaje1->y()==-20) //puerta arriba //conexion nivel 4
        {
            clean();
            opcion=4;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-80,-20);
            personaje2->setPos(-55,-20);
        }
        if (personaje1->x()==-120 and personaje1->y()==220)
        {

            clean();
            opcion=6;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(455,250);
        }



    }
    if (opcion==2)
    {

        if (personaje1->x()==170 and personaje1->y()==-20) //puerta arriba //conexion nivel 7
        {
            clean();
            opcion=7;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-115,350);
            personaje2->setPos(-10,335);
        }
        if (personaje1->x()==520 and personaje1->y()==200) //puerta izquierda //conexion nivel 5
        {
            clean();
            opcion=5;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-65,215);
            personaje2->setPos(-50,320);
        }
        if (personaje1->x()==-120 and personaje1->y()==420) //puerta abajo //conexion nivel 6
        {
            clean();
            opcion=6;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-120,5);
            personaje2->setPos(-60,30);
        }
        /*if (personaje1->x()==520 and personaje1->y()==200) //puerta derecha //conexion nivel 3
        {
            clean();
            opcion=3;
            niveles(opcion);
        }*/
    }
    if (opcion==3)
    {

        if (personaje1->x()==-115 and personaje1->y()==220) //puerta izquierda //conexion nivel 5
        {
            clean();
            opcion=5;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(455,205);
            personaje2->setPos(375,205);
        }
        if (personaje1->x()==485 and personaje1->y()==420) //puerta izquierda //conexion nivel 4
        {
            clean();
            opcion=4;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(280,20);
            personaje2->setPos(350,-20);
        }

    }

    if (opcion==4)
    {

    if (personaje1->x()==-115 and personaje1->y()==-20) //puerta izquierda //conexion nivel 1
    {
        clean();
        opcion=1;
        niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
        personaje1->setPos(515,-20);
        personaje2->setPos(430,-20);

    }
    if (personaje1->x()==280 and personaje1->y()==-20) //puerta arriba //conexion nivel 3
    {
        clean();
        opcion=3;
        niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
        personaje1->setPos(475,360);

    }

    }

    if (opcion==5)
    {

        if (personaje1->x()==170 and personaje1->y()==415) //puerta abajo//conexion nivel 1
        {
            clean();
            opcion=1;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(155,45);
            personaje2->setPos(105,40);

        }
        if (personaje1->x()==520 and personaje1->y()==200) //puerta derecha//conexion nivel 3
        {
            clean();
            opcion=3;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-70,220);
            personaje2->setPos(-70,305);

        }
        if (personaje1->x()==-120 and personaje1->y()==220) //puerta izquierda //conexion nivel 2
        {
            clean();
            opcion=2;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(460,205);
            personaje2->setPos(470,115);

        }


    }
    if (opcion==6)
    {

        if (personaje1->x()==515 and personaje1->y()==250) //puerta derecha conex nivel 1
        {
            clean();
            opcion=1;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-110,220);
            personaje2->setPos(-70,220);

        }
        if (personaje1->x()==-120 and personaje1->y()==-15) //puerta arriba //conexion nivel 2
        {
            clean();
            opcion=2;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-115,355);

        }
    }
    if (opcion==7)
    {
        if (personaje1->x()==520 and personaje1->y()==360) //puerta derecha conexión parte de arriba
        {


            personaje1->setPos(520,60);

        }
        if (personaje1->x()==-120 and personaje1->y()==60) //puerta final
        {


            ganar();
            this->close();

        }


    }
    }

    if (jugadores==2)
    {if (opcion==1)
    {
        if (personaje1->x()==170 and personaje1->y()==-20 and personaje2->x()==170 and personaje2->y()==-20) //puerta arriba //conexion nivel 5
        {

            clean();

            opcion=5;
            niveles(opcion, jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(170,345);
            personaje2->setPos(170,345);
        }

        if (personaje1->x()==520 and personaje1->y()==-20 and personaje2->x()==520 and personaje2->y()==-20) //puerta arriba //conexion nivel 4
        {
            clean();
            opcion=4;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-80,-20);
            personaje2->setPos(-80,-20);
        }
        if (personaje1->x()==-120 and personaje1->y()==220 and personaje2->x()==-120 and personaje2->y()==220)
        {

            clean();
            opcion=6;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(455,250);
            personaje2->setPos(455,250);
        }



    }
    if (opcion==2)
    {

        if (personaje1->x()==170 and personaje1->y()==-20 and personaje2->x()==170 and personaje2->y()==-20) //puerta arriba //conexion nivel 7
        {
            clean();
            opcion=7;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-115,350);
            personaje2->setPos(-115,350);
        }
        if (personaje1->x()==520 and personaje1->y()==200 and personaje2->x()==520 and personaje2->y()==200) //puerta izquierda //conexion nivel 5
        {
            clean();
            opcion=5;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-65,215);
            personaje2->setPos(-65,215);
        }
        if (personaje1->x()==-120 and personaje1->y()==420 and personaje2->x()==-120 and personaje2->y()==420) //puerta abajo //conexion nivel 6
        {
            clean();
            opcion=6;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-120,5);
            personaje2->setPos(-120,5);
        }
        /*if (personaje1->x()==520 and personaje1->y()==200) //puerta derecha //conexion nivel 3
        {
            clean();
            opcion=3;
            niveles(opcion);
        }*/
    }
    if (opcion==3)
    {

        if (personaje1->x()==-115 and personaje1->y()==220 and personaje2->x()==-115 and personaje2->y()==220) //puerta izquierda //conexion nivel 5
        {
            clean();
            opcion=5;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(455,205);
            personaje2->setPos(455,205);
        }
        if (personaje1->x()==485 and personaje1->y()==420 and personaje2->x()==485 and personaje2->y()==420) //puerta izquierda //conexion nivel 4
        {
            clean();
            opcion=4;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(280,20);
            personaje2->setPos(280,20);
        }

    }

    if (opcion==4)
    {

    if (personaje1->x()==-115 and personaje1->y()==-20 and personaje2->x()==-115 and personaje2->y()==-20) //puerta izquierda //conexion nivel 1
    {
        clean();
        opcion=1;
        niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
        personaje1->setPos(515,-20);
        personaje2->setPos(515,-20);

    }
    if (personaje1->x()==280 and personaje1->y()==-20 and personaje2->x()==280 and personaje2->y()==-20) //puerta arriba //conexion nivel 3
    {
        clean();
        opcion=3;
        niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
        personaje1->setPos(475,360);
        personaje2->setPos(475,360);

    }

    }

    if (opcion==5)
    {

        if (personaje1->x()==170 and personaje1->y()==415 and personaje2->x()==170 and personaje2->y()==415) //puerta abajo//conexion nivel 1
        {
            clean();
            opcion=1;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(155,45);
            personaje2->setPos(155,45);

        }
        if (personaje1->x()==520 and personaje1->y()==200 and personaje2->x()==520 and personaje2->y()==200) //puerta derecha//conexion nivel 3
        {
            clean();
            opcion=3;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-70,220);
            personaje2->setPos(-70,220);

        }
        if (personaje1->x()==-120 and personaje1->y()==220 and personaje2->x()==-120 and personaje2->y()==220) //puerta izquierda //conexion nivel 2
        {
            clean();
            opcion=2;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(460,205);
            personaje2->setPos(460,205);

        }


    }
    if (opcion==6)
    {

        if (personaje1->x()==515 and personaje1->y()==250 and personaje2->x()==515 and personaje2->y()==250) //puerta derecha conex nivel 1
        {
            clean();
            opcion=1;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-110,220);
            personaje2->setPos(-110,220);

        }
        if (personaje1->x()==-120 and personaje1->y()==-15 and personaje2->x()==-120 and personaje2->y()==-15) //puerta arriba //conexion nivel 2
        {
            clean();
            opcion=2;
            niveles(opcion,jugadores,nivel1,nivel2,nivel3,nivel4,nivel5,nivel6);
            personaje1->setPos(-115,355);
            personaje2->setPos(-115,355);

        }
    }
    if (opcion==7)
    {
        if (personaje1->x()==520 and personaje1->y()==360 and personaje2->x()==520 and personaje2->y()==360) //puerta derecha conexión parte de arriba
        {


            personaje1->setPos(520,60);
            personaje2->setPos(520,60);

        }
        if (personaje1->x()==-120 and personaje1->y()==60 and personaje2->x()==-120 and personaje2->y()==60) //puerta final
        {


            ganar();
            this->close();

        }


    }
    }


}

//--------------------------------------------------FISICAS--------------------------------------------------


/*void MainWindow::lanzarfuego()
{
    if (opcion==1)
            {x=dragon->getPosx();
             y=dragon->getPosy();         //(an,posxx,posyy,velocidad,r,path)
            cuerpos.push_back(new Particula (0,x, y,100,30,":/I/I/BOLADEFUEGO.png"));
            scene->addItem(cuerpos.back());
            }

    if (opcion==3)
        {
                                         //(an,posxx,posyy,velocidad,r,path)
           cuerpos.push_back(new Particula (0,520,330,300,30,":/I/I/BOLADEFUEGO.png"));
           scene->addItem(cuerpos.back());
        }
    if (opcion==4)
        {                                  //(an,posxx,posyy,velocidad,r,path)
            cuerpos.push_back(new Particula (0,520,330,400,30,":/I/I/BOLADEFUEGO.png"));
            scene->addItem(cuerpos.back());
        }
    if (opcion==5)
       {                                  //(an,posxx,posyy,velocidad,r,path)
           cuerpos.push_back(new Particula (0,515,325,500,30,":/I/I/BOLADEFUEGO.png"));
            scene->addItem(cuerpos.back());
        }
    if (opcion==6)
        {                                //(an,posxx,posyy,velocidad,r,path)
           cuerpos.push_back(new Particula (0,445,360,600,30,":/I/I/BOLADEFUEGO.png"));
           scene->addItem(cuerpos.back());
        }
    if (opcion==7)
        {                                //(an,posxx,posyy,velocidad,r,path)
           cuerpos.push_back(new Particula (0,500,325,600,30,":/I/I/BOLADEFUEGO.png"));
           scene->addItem(cuerpos.back());
        }

}*/

void MainWindow::moverfuego()
{
    if(ban2==false)
    {bolafuego->setY(bolafuego->y()+2*friccion*M*G);
     if(bolafuego->y()>=ymayor)
     {ban2=true;}
     if(bolaH->collidesWithItem(bolafuego))
     {ban2=true;}
    }
    if(ban2==true)
        {bolafuego->setY(bolafuego->y()-2*friccion*M*G);
       if(bolafuego->y()<=ymenor)
        {ban2=false;
        }
       if(bolaH->collidesWithItem(bolafuego))
       {ban2=false;}
        }
    if(personaje1->collidesWithItem(bolafuego))
    {
        vida->decrease();
        personaje1->subir(1,1);
        if (vida->getlife()==0)
        {
            perder();
            ReinicioDEnivel();
        }
    }
    if(personaje2->collidesWithItem(bolafuego))
    {
        vida->decrease();
        personaje2->subir(1,1);
        if (vida->getlife()==0)
        {
            perder();
            ReinicioDEnivel();
        }
    }

}

void MainWindow::resorte(char letra , Objeto *personaje)
{
   if (personaje==personaje1)
    {

    if (letra=='A')
    {personaje1-> setPos(personaje1->x()+5*rigidez,personaje1->y());
    }
    if (letra=='D')
    {personaje1-> setPos(personaje1->x()-5*rigidez,personaje1->y());
    }
    if (letra=='W')
    {personaje1->setPos(personaje1->x(),personaje1->y()+5*rigidez);
    }
    if(letra=='S')
    {personaje1->setPos(personaje1->x(),personaje1->y()-5*rigidez);
    }
    }

   if(personaje==personaje2)
   {if(letra=='J')
       {personaje2-> setPos(personaje2->x()+5*rigidez,personaje2->y());
       }
    if(letra=='L')
        {personaje2-> setPos(personaje2->x()-5*rigidez,personaje2->y());
        }
    if(letra=='I')
        {personaje2->setPos(personaje2->x(),personaje2->y()+5*rigidez);
        }
    if(letra=='K')
        {personaje2->setPos(personaje2->x(),personaje2->y()-5*rigidez);
        }
   }
}

void MainWindow::moverEnemigo( )
{
    if(ban==false)
    {enemigo1->setX(enemigo1->x()+2*friccion*M*G);
     if(enemigo1->x()>=xmayor)
     {ban=true;}
     if(bolaH->collidesWithItem(enemigo1))
     {ban=true;}
    }
    if(ban==true)
        {enemigo1->setX(enemigo1->x()-2*friccion*M*G);
       if(enemigo1->x()<=xmenor)
        {ban=false;}
       if(bolaH->collidesWithItem(bolafuego))
       {ban=false;}
        }
    if(personaje1->collidesWithItem(enemigo1))
        {
            vida->decrease();
            personaje1->derecha(1,1);
            if (vida->getlife()==0)
            {
                perder();
                ReinicioDEnivel();
            }
        }
    if(personaje2->collidesWithItem(enemigo1))
        {
            vida->decrease();
            personaje2->derecha(1,1);
            if (vida->getlife()==0)
            {
                perder();
                ReinicioDEnivel();
            }
        }
}

//-------------------------------------------------DESTRUCTOR---------------------------------------------------------------


MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::actualizar()
{switch(opcion)
       { case 1:
            moverEnemigo();
            if(jugadores==2)
            {tiempo->decrease();
                if (tiempo->gettime()==0)
                {
                    perder();
                    ReinicioDEnivel();
                }
            }
        break;

        case 2:
            moverfuego();
            if(jugadores==2)
            {tiempo->decrease();
                if (tiempo->gettime()==0)
                {
                    perder();
                    ReinicioDEnivel();
                }
            }
            break;
        default:
            moverEnemigo();
            moverfuego();
            if(jugadores==2)
            {tiempo->decrease();
                if (tiempo->gettime()==0)
                {
                    perder();
                    ReinicioDEnivel();
                }
            }
            break;
        }
}
