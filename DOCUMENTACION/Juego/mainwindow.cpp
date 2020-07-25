#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


niveles(opcion);

//-----------------------------BOTÓN START---------------------------

start=new QPushButton("INICIAR JUEGO", this);

start->setGeometry(QRect( QPoint(310,160), // Valores por defecto 250x160
QSize(200, 50) ));
//Valores por defecto : 200x 50

connect(start, SIGNAL (clicked()),this, SLOT (botonInicio()));
start->setStyleSheet("background-color: gray");


//-----------------------------BOTÓN CONTINUAR PARTIDA------------------

continuarPartida=new QPushButton ("CONTINUAR PARTIDA ",this);

continuarPartida->setGeometry(QRect( QPoint(310,300),
QSize(200, 50) ));

connect(continuarPartida, SIGNAL (clicked()),this, SLOT (continuar()));
continuarPartida->setStyleSheet("background-color: gray");

//-----------------------------BOTÓN GUARDAR JUEGO ------------------

guardar=new QPushButton ("GUARDAR PARTIDA",this);

guardar->setGeometry(QRect( QPoint(0,0),
QSize(200, 50) ));

connect(guardar, SIGNAL (clicked()),this, SLOT (continuar()));
guardar ->setStyleSheet("background-color: red");

bolaFuego=new Objeto(0,0,30, ":/IMAGENES/BOLA DE FUEGO.png");

/*
timer->stop();
connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
timer->start(dt);*/



/*LISTA.append(new Particula(0,0,0,0,50000,200));
LISTA.append(new Particula(-5000,0,0,0,70,70));
LISTA.append(new Particula(5000,0,0,0,70,70)); */   //Planetas agregados directamente
// LISTA.append(new Graficar(0,-5000,2,0,70,70));
//LISTA.append(new Graficar(0,5000,-2,0,70,70));



}


//-------------------------------------------------KEYPRESSEVENT--------------------------------------------------

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

 qDebug()<<personaje1->pos()<<personaje1->x();

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

//------------------------------------------------CAMBIO DE NIVEL 1 A 2-------------------------------------------------
teletransportacion();
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




//------------------------------------------------CAMBIO DE NIVEL 2 A 3-------------------------------------------------
teletransportacion();
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
if (evento->key()==Qt::Key_4)
 {

    /*clean();
    opcion=4;
    niveles(opcion);*/

 }

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

/*if(evento->key()==Qt::Key_0)
{

    guardarPartida();

}*/

if(evento->key()==Qt::Key_1)
{

    clean();
    opcion=1;
    niveles (opcion);

}
if(evento->key()==Qt::Key_2)
{

    clean();
    opcion=2;
    niveles (opcion);

}
if(evento->key()==Qt::Key_3)
{

    clean();
    opcion=3;
    niveles (opcion);

}
if(evento->key()==Qt::Key_4)
{

    clean();
    opcion=4;
    niveles (opcion);

}
if(evento->key()==Qt::Key_5)
{

    clean();
    opcion=5;
    niveles (opcion);

}
if(evento->key()==Qt::Key_6)
{

    clean();
    opcion=6;
    niveles (opcion);

}
if(evento->key()==Qt::Key_7)
{

    clean();
    opcion=7;
    niveles (opcion);

}
}

void MainWindow::coaliciones(char letra , Personaje *personaje)
{
   if (personaje==personaje1)
    {

    if (letra=='A')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());

    //---------------------------GIRO DEL PERSONAJE1 (A)------------------------------

    personaje1->setTransformOriginPoint(0,0);
    personaje1->setRotation(180);
    personaje1->izquierda();


    //------------------------------COALISIONES1 (A) ----------------------------

    if(personaje1->collidesWithItem(bolaH))
    {
    bolaH->izquierda();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
    enemigo1->izquierda();
    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }

    //------------------------EVALUAR COALISIONES CON MUROS 1(A)------------------

    for (int i=0;i<muros.size();i++)
    {
    if (personaje1->collidesWithItem(muros.at(i)))
    {

    personaje1->derecha();
    }
    }


    //--------------------EVALUAR COALISIONES CON PIEDRAS 1(A)--------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->derecha();
    }
    }

    //--------------------------CAPTURAR LLAVES 1(A)-------------------------------
    if (personaje1->collidesWithItem(llave))
    {
    //key->play();
    scene->removeItem(llave);


    //llaves+=1;

    }

    //--------------------------PUERTA 1(A)-------------------------------------------
    if (personaje1->collidesWithItem(puerta))
    {

    personaje1->derecha();
    //remover escena
    }






    }
    if (letra=='D')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());

    //--------------------------GIRO DEL PERSONAJE 1(D)---------------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->setRotation(0);
    personaje1->derecha();

    //---------------------------COALISIONES 1(D)----------------------------

    if(personaje1->collidesWithItem(bolaH))

    {
    bolaH->derecha();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
    x = enemigo1->x();
    y = enemigo1->y();
    enemigo1->derecha();
    //bolaFuego->setPosx(personaje1->pos());
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }

    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }
    //----------------------EVALUAR COALISIONES CON MUROS 1(D)------------------
    for (int i=0;i<muros.size();i++)
    {
    if (personaje1->collidesWithItem(muros.at(i)))
    {



    personaje1->izquierda();
    }
    }
    //----------------------EVALUAR COALISIONES CON PIEDRAS 1(D)----------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->izquierda();
    }
    }

    //----------------------------CAPTURAR LLAVES 1(D)----------------------------------
    if (personaje1->collidesWithItem(llave))
    {
    //key->play();
    scene->removeItem(llave);


    //llaves+=1;

    }

    //--------------------------PUERTA 1(D)------------------------------
    if (personaje1->collidesWithItem(puerta))
    {
    personaje1->izquierda();
    //remover escena
    }
    }
    if (letra=='W')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());


    //-------------------------GIRO DE PERSONAJE 1(W)-----------------------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->setRotation(270);
    personaje1->subir();


    //----------------------------COALISIONES 1(W)--------------------------------

    if(personaje1->collidesWithItem(bolaH))
    {
    bolaH->subir();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
    enemigo1->subir();


    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }
    //----------------EVALUAR COALISIONES CON MUROS 1(W))-----------------------
    for (int i=0;i<muros.size();i++)
    {
    if (personaje1->collidesWithItem(muros.at(i)))
    {


    personaje1->bajar();
    }
    }
    //-------------------EVALUAR COALISIONES CON PIEDRAS 1(W)---------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (personaje1->collidesWithItem(piedras.at(i)))
    {

    personaje1->bajar();
    }
    }

    //-----------------------------CAPTURAR LLAVES 1(W)----------------------------
    if (personaje1->collidesWithItem(llave))
    {
    //key->play();
    scene->removeItem(llave);

    //llaves+=1;

    }

    //-----------------------------------PUERTA 1(W)-------------------------------
    if (personaje1->collidesWithItem(puerta))
    {
    personaje1->bajar();
    //remover escena
    }


    }
    if (letra=='S')
    {
   //lanzamiento(-40,personaje1->x(),70,personaje1->y());


      //---------------------------GIRO DE PERSONAJE 1(S)---------------------------
      personaje1->setTransformOriginPoint(0,0);
      personaje1->setRotation(90);
      personaje1->bajar();


      //------------------------------COALISIONES 1(S)-----------------------------
      if(personaje1->collidesWithItem(bolaH))
      {
              bolaH->bajar();
      }
      if(personaje1->collidesWithItem(enemigo1))


      {

          x = enemigo1->x();
          y = enemigo1->y();
              enemigo1->bajar();
              //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
              //scene->addItem(cuerpos.back());

              timer->start(30);
      }
      for (int i=0;i<cuerpos.size();i++)
      {
          if (personaje1->collidesWithItem(cuerpos.at(i)))
             {
              scene->removeItem(cuerpos.at(i));
              cuerpos.removeOne(cuerpos.at(i));
              //vidas-=1;
              }
      }

        //-----------------------EVALUAR COALISIONES CON MUROS 1(S)----------------

      for (int i=0;i<muros.size();i++)
      {
          if (personaje1->collidesWithItem(muros.at(i)))
          {

              personaje1->subir();
          }
      }
      //----------------------EVALUAR COALISIONES CON PIEDRAS 1(S)---------------

      for (int i=0;i<piedras.size();i++)
          {
              if (personaje1->collidesWithItem(piedras.at(i)))
              {

                  personaje1->subir();
              }
          }

      //--------------------------CAPTURAR LLAVES 1(S)-------------------------
      if (personaje1->collidesWithItem(llave))
          {
              //key->play();
             scene->removeItem(llave);

               //llaves+=1;

          }

      //-------------------------PUERTA 1(S)-----------------------------------

      if (personaje1->collidesWithItem(puerta))
              {
                  personaje1->subir();
                  //remover escena
              }





    }



    }

   if (personaje==personaje2)
   {

    if (letra=='I')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());


    //-------------------GIRO DE PERSONAJE 2(I)-------------------
    personaje2->setTransformOriginPoint(0,0);
    personaje2->setRotation(270);
    personaje2->subir();


    //--------------------------COALISIONES 2(I)------------------------

    if(personaje2->collidesWithItem(bolaH))
    {
    bolaH->subir();
    }
    if(personaje2->collidesWithItem(enemigo1))

    {
    enemigo1->subir();


    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje2->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }
    //-----------------------------EVALUAR COALISIONES CON MUROS 2(I)------------------

    for (int i=0;i<muros.size();i++)
    {
    if (personaje2->collidesWithItem(muros.at(i)))
    {


    personaje2->bajar();
    }
    }
    //-------------------------------EVALUAR COALISIONES CON PIEDRAS 2(I)--------------

    for (int i=0;i<piedras.size();i++)
    {
    if (personaje2->collidesWithItem(piedras.at(i)))
    {

    personaje2->bajar();
    }
    }

    //------------------------------------CAPTURAR LLAVES 2(I)--------------------

    if (personaje2->collidesWithItem(llave))
    {
    //key->play();
    scene->removeItem(llave);

    //llaves+=1;

    }

    //------------------------------------PUERTA 2(I)----------------------------------
    if (personaje2->collidesWithItem(puerta))
    {
    personaje2->bajar();
    //remover escena
    }


    }

    if (letra=='J')
    {

        //lanzamiento(-40,personaje1->x(),70,personaje1->y());

        //---------GIRO DEL PERSONAJE-------
        personaje2->setTransformOriginPoint(0,0);
        personaje2->setRotation(180);
        personaje2->izquierda();


        //------------------------COALISIONES 2(J)----------------------------------

        if(personaje2->collidesWithItem(bolaH))
        {
        bolaH->izquierda();
        }
        if(personaje2->collidesWithItem(enemigo1))

        {
        enemigo1->izquierda();
        x = enemigo1->x();
        y = enemigo1->y();
        //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
        //scene->addItem(cuerpos.back());

        timer->start(30);
        }
        for (int i=0;i<cuerpos.size();i++)
        {
        if (personaje2->collidesWithItem(cuerpos.at(i)))
        {
        scene->removeItem(cuerpos.at(i));
        cuerpos.removeOne(cuerpos.at(i));
        //vidas-=1;
        }
        }
        //-----------------------EVALUAR COALISIONES CON MUROS 2(J)---------------------
        for (int i=0;i<muros.size();i++)
        {
        if (personaje2->collidesWithItem(muros.at(i)))
        {

        personaje2->derecha();
        }
        }


        //-------------------------EVALUAR COALISIONES CON PIEDRAS 2(J)--------------

        for (int i=0;i<piedras.size();i++)
        {
        if (personaje2->collidesWithItem(piedras.at(i)))
        {

        personaje2->derecha();
        }
        }

        //----------------------------CAPTURAR LLAVES 2(J)-----------------------

        if (personaje2->collidesWithItem(llave))
        {
        //key->play();
        scene->removeItem(llave);


        //llaves+=1;

        }

        //----------------------------------PUERTA 2(J)-------------------------------

        if (personaje2->collidesWithItem(puerta))
        {

        personaje2->derecha();
        //remover escena
        }








    }


    if (letra=='L')
    {
    //lanzamiento(-40,personaje1->x(),70,personaje1->y());

    //---------GIRO DEL PERSONAJE-------
    personaje2->setTransformOriginPoint(0,0);
    personaje2->setRotation(0);
    personaje2->derecha();

    //-------------------------------COALISIONES 2(L) --------------------------------
    if(personaje2->collidesWithItem(bolaH))

    {
    bolaH->derecha();
    }
    if(personaje2->collidesWithItem(enemigo1))

    {
    x = enemigo1->x();
    y = enemigo1->y();
    enemigo1->derecha();
    //bolaFuego->setPosx(personaje1->pos());
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }

    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje2->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }
    //------------------------EVALUAR COALISIONES CON MUROS 2(L)--------------------------
    for (int i=0;i<muros.size();i++)
    {
    if (personaje2->collidesWithItem(muros.at(i)))
    {



    personaje2->izquierda();
    }
    }
    //---------------------EVALUAR COALISIONES CON PIEDRAS 2(L)----------------------------

    for (int i=0;i<piedras.size();i++)
    {
    if (personaje2->collidesWithItem(piedras.at(i)))
    {

    personaje2->izquierda();
    }
    }

    //------------------------------CAPTURAR LLAVES 2(L)--------------------------------

    if (personaje2->collidesWithItem(llave))
    {
    //key->play();
    scene->removeItem(llave);


    //llaves+=1;

    }

    //-------------------------------------PUERTA 2(L)-----------------------------
    if (personaje2->collidesWithItem(puerta))
    {
    personaje2->izquierda();
    //remover escena
    }
    }


    if (letra=='K')
    {
   //lanzamiento(-40,personaje1->x(),70,personaje1->y());


      //---------------------------------GIRO DE PERSONAJE 2(K)----------------------
      personaje2->setTransformOriginPoint(0,0);
      personaje2->setRotation(90);
      personaje2->bajar();


      //----------------------------------COALISIONES 2(K)--------------------------------

      if(personaje2->collidesWithItem(bolaH))
      {
              bolaH->bajar();
      }
      if(personaje2->collidesWithItem(enemigo1))


      {

          x = enemigo1->x();
          y = enemigo1->y();
              enemigo1->bajar();
              //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
              //scene->addItem(cuerpos.back());

              timer->start(30);
      }
      for (int i=0;i<cuerpos.size();i++)
      {
          if (personaje2->collidesWithItem(cuerpos.at(i)))
             {
              scene->removeItem(cuerpos.at(i));
              cuerpos.removeOne(cuerpos.at(i));
              //vidas-=1;
              }
      }

        //--------------------------EVALUAR COALISIONES CON MUROS 2(K)--------------------------

      for (int i=0;i<muros.size();i++)
      {
          if (personaje2->collidesWithItem(muros.at(i)))
          {

              personaje2->subir();
          }
      }
      //-----------------------------EVALUAR COALISIONES CON PIEDRAS 2(K)----------------------
      for (int i=0;i<piedras.size();i++)
          {
              if (personaje2->collidesWithItem(piedras.at(i)))
              {

                  personaje2->subir();
              }
          }

      //-----------------------------CAPTURAR LLAVES 2(K)------------------------------------
      if (personaje2->collidesWithItem(llave))
          {
              //key->play();
             scene->removeItem(llave);

               //llaves+=1;

          }

      //------------------------------PUERTA 2(K)------------------------------------------

      if (personaje2->collidesWithItem(puerta))
              {
                  personaje2->subir();
                  //remover escena
              }





    }
   }

}





//------------------------------------------------------NIVELES--------------------------------------------------


void MainWindow::botonInicio()
{
    opcion=1;
    niveles(opcion);
}
void MainWindow::continuar()
{

     QString l;
     QFile archivo("PARTIDA.txt");
     QTextStream datosArchivo(&archivo);
    if (!archivo.exists())
    {
        qDebug()<<" EL ARCHIVO SELECCIONADO NO EXISTE ";

    }
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        if (!archivo.isOpen())
        {
            qDebug()<<" EL ARCHIVO NO SE HA PODIDO ABRIR ";

        }
           l=archivo.readAll();
           qDebug()<<l;
           if (l==1)
           {
               opcion=1;
           }
           if (l==2)
           {
               opcion=1;
           }
           if (l==3)
           {
               opcion=1;
           }


        }
        archivo.close();
}
void MainWindow:: niveles(int opcion)
{
    if (opcion==0)
    {

        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);

        /*QMovie *movie= new QMovie (":/IMAGENES/MENU.gif");
        label->setMovie(movie);
        movie->start();
        */
       /* QMovie *movie= new QMovie (":/IMAGENES/MENU.gif");
           label = new QLabel(this);
           label->setMovie(movie);
           movie->start();*/

        scene->setBackgroundBrush(QPixmap(":/I/I/MAINMENU.png"));
        scene->setSceneRect(0,0,790,550);

        //intro=new QMediaPlayer ();
        //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


        //intro->play();



    }
    if (opcion==1)
    {
        {


            //intro->stop();
            //key=new QMediaPlayer ();
            //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

            timer= new QTimer;
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
            scene->setBackgroundBrush(QPixmap(":/I/I/L1.jpg"));
            scene->setSceneRect(0,0,400,400);

            personaje1=new Personaje(180,410,30,1,10, ":/I/I/PERSONAJE1.png");
            scene->addItem(personaje1);

            personaje2=new Personaje(0,0,45,10,0, ":/IMAGENES/IMAGENES/PERSONAJE2.png");
            scene->addItem(personaje2);

            llave= new Objeto (470,35,30,":/IMAGENES/IMAGENES/llave1.png");
            scene->addItem(llave);

            /*piedras.push_back(new Objeto(-120,305,40,":/IMAGENES/IMAGENES/rocas2.png"));
            scene->addItem(piedras.back());

            piedras.push_back(new Objeto(-30,275,40,":/IMAGENES/IMAGENES/rocas2.png"));
            scene->addItem(piedras.back());

            piedras.push_back(new Objeto(-10,180,40,":/IMAGENES/IMAGENES/rocas2.png"));
            scene->addItem(piedras.back());

            piedras.push_back(new Objeto(-50,105,40,":/IMAGENES/IMAGENES/rocas2.png"));
            scene->addItem(piedras.back());

            piedras.push_back(new Objeto(-120,85,40,":/IMAGENES/IMAGENES/rocas2.png"));
            scene->addItem(piedras.back());*/

            muros.push_back(new Pared (-350,50,50,800, ":/IMAGENES/IMAGENES/rocas2.png")); //muro vertical
            scene->addItem(muros.back());

            muros.push_back(new Pared (-120,50,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo derecha conexion nivel 1
            scene->addItem(muros.back());

            muros.push_back(new Pared (-200,50,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo izqu conexion nivel 1
            scene->addItem(muros.back());

            muros.push_back(new Pared (-500,-10,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 4 ancho alto
            scene->addItem(muros.back());





            items();



        }
    }
    if (opcion==2)
    {
        //intro->stop();
        //key=new QMediaPlayer ();
        //key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        timer= new QTimer;
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
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/IMAGENES/O1.jpg"));
        scene->setSceneRect(0,0,400,400);

        personaje1=new Personaje(180,350,30,1,10, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);
        llave= new Objeto (180,65,30,":/IMAGENES/IMAGENES/llave1.png");
        scene->addItem(llave);

        /*piedras.push_back(new Objeto(-120,305,40,":/IMAGENES/rocas2.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-30,275,40,":/IMAGENES/rocas2.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-10,180,40,":/IMAGENES/rocas2.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-50,105,40,":/IMAGENES/rocas2.png"));
        scene->addItem(piedras.back());

        piedras.push_back(new Objeto(-120,85,40,":/IMAGENES/rocas2.png"));
        scene->addItem(piedras.back());

        muros.push_back(new Pared (-350,50,50,800, ":/IMAGENES/BLOQUE.jpg"));
        scene->addItem(muros.back());*/

        muros.push_back(new Pared (-120,50,20,50, ":/IMAGENES/BLOQUE.jpg")); //arriba conex nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (-200,50,20,50, ":/IMAGENES/BLOQUE.jpg")); //arriba izq conex nivel 7
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-150,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha arriba
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-230,50,20, ":/IMAGENES/BLOQUE.jpg")); //muro derecha abajo
        scene->addItem(muros.back());

        /*muros.push_back(new Pared (-4,-400,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo derecha //-120
        scene->addItem(muros.back());*/

        muros.push_back(new Pared (90,-400,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo izqu //-200
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-150,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha arriba
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-230,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha abajo
        scene->addItem(muros.back());





        items();
    }
    if (opcion==3)
    {


        timer->stop();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/IMAGENES/ARENA.jpg"));
        scene->setSceneRect(0,0,400,400);

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        timer->start();
        personaje1=new Personaje(495,410,30,2, 0, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);

         enemigo1= new Personaje (140,340,45,2,0,":/I/I/ENEMIGO.png");
         scene->addItem(enemigo1);
         puerta=new Objeto(200,-30, 50,"" ); //puerta arriba
         scene->addItem(puerta);


         puerta=new Objeto(550,210, 50,"" ); //puerta izquierda
         puerta->setRotation(90);
         scene->addItem(puerta);

         totem= new Personaje (0,0,60 ,1,0, "");
         scene->addItem(totem);
         timer->start();
         muros.push_back(new Pared (150,-160,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 5 arriba ancho alto
         scene->addItem(muros.back());

         muros.push_back(new Pared (150,-250,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 5 abajo ancho alto
         scene->addItem(muros.back());

         muros.push_back(new Pared (-420,-400,30,50, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 4 izqu abajo ancho alto
         scene->addItem(muros.back());

         muros.push_back(new Pared (-520,-400,30,50, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 4 derecha abajo ancho alto
         scene->addItem(muros.back());

         muros.push_back(new Pared (-50,-150,200,50, ":/IMAGENES/BLOQUE.jpg")); //muro centro arriba
         scene->addItem(muros.back());

         muros.push_back(new Pared (-50,-150,50,300, ":/IMAGENES/BLOQUE.jpg")); //muro centro  izquierda
         scene->addItem(muros.back());

         muros.push_back(new Pared (-250,-150,50,150, ":/IMAGENES/BLOQUE.jpg")); //muro centro derecha
         scene->addItem(muros.back());

        items();



    }
    if (opcion==4)
    {

        timer->stop();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/HIELO FONDO.png"));
        scene->setSceneRect(0,0,400,400);
        muros.push_back(new Pared (-100,50,50,200, ":/IMAGENES/BLOQUE.jpg"));//vertical arriba
        scene->addItem(muros.back());

        //muros.push_back(new Pared (150,-110,300,50, ":/IMAGENES/BLOQUE.jpg"));//HORIZONTAL ARRIBA
        //scene->addItem(muros.back());

        muros.push_back(new Pared (-100,-300,50,200, ":/IMAGENES/BLOQUE.jpg")); //VERTICAL ABAJO
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-300,300,50, ":/IMAGENES/BLOQUE.jpg")); //HORIZONTAL ABAJO
        scene->addItem(muros.back());

        piedras.push_back(new Objeto(350,210,70,":/I/I/HIELO.png"));
        scene->addItem(piedras.back());
        llave= new Objeto (470,400,30,":/I/I/llave1.png");
        scene->addItem(llave);
        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        timer->start();
       personaje1=new Personaje(495,410,30,2,0, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);
        enemigo1=new Personaje(495,310,40,2,0, ":/I/I/ENEMIGO.png");
        scene->addItem(enemigo1);

        enemigo1=new Personaje(50,110,40,2,0, ":/I/I/ENEMIGO.png");
        scene->addItem(enemigo1);

        //_------ muros extra
        muros.push_back(new Pared (-100,-300,50,200, ":/IMAGENES/BLOQUE.jpg")); //VERTICAL ABAJO
        scene->addItem(muros.back());

        //muros.push_back(new Pared (150,-300,300,50, ":/IMAGENES/BLOQUE.jpg")); //HORIZONTAL ABAJO
        //scene->addItem(muros.back());


        //muros puertas

        muros.push_back(new Pared (150,-10,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 1 ancho alto
        scene->addItem(muros.back());

        muros.push_back(new Pared (-220,50,30,50, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 3
        scene->addItem(muros.back());






        items();


    }
    if (opcion==5)
    {
    //intro->stop();
            //key=new QMediaPlayer ();
           // key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

            timer= new QTimer;
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
            scene->setBackgroundBrush(QPixmap(":/IMAGENES/IMAGENES/PisoPiedra.jpg"));
            scene->setSceneRect(0,0,400,400);

            personaje1=new Personaje(175,420,30,1,10, ":/I/I/PERSONAJE1.png");
            scene->addItem(personaje1);

            boton= new Objeto(195,360,30, ":/IMAGENES/IMAGENES/pngocean.com (1).png");
            scene->addItem(boton);

            boton= new Objeto(-40,35,30, ":/IMAGENES/IMAGENES/pngocean.com (1).png");
            scene->addItem(boton);

            boton= new Objeto(475,35,30, ":/IMAGENES/IMAGENES/pngocean.com (1).png");
            scene->addItem(boton);


           /* muros.push_back(new Pared (0,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro derecha conexion nivel 7
            scene->addItem(muros.back());

            muros.push_back(new Pared (-320,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro izquierda conexion nivel 7
            scene->addItem(muros.back());*/

            muros.push_back(new Pared (-120,-400,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo derecha conexion nivel 1
            scene->addItem(muros.back());

            muros.push_back(new Pared (-200,-400,20,50, ":/IMAGENES/BLOQUE.jpg")); //abajo izqu conexion nivel 1
            scene->addItem(muros.back());

            muros.push_back(new Pared (150,-160,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 2 arriba ancho alto conex n 2
            scene->addItem(muros.back());

            muros.push_back(new Pared (150,-250,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 3 abajo ancho alto conex nivel 2
            scene->addItem(muros.back());

            muros.push_back(new Pared (-500,-150,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha arriba conex nivel 3
            scene->addItem(muros.back());

            muros.push_back(new Pared (-500,-230,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha abajo conex nivel 3
            scene->addItem(muros.back());




            //muros.push_back(new Pared (0,200,50,800, ":/IMAGENES/BLOQUE.jpg"));
            //scene->addItem(muros.back());














            items();

    }
    if (opcion==6)
    {
        timer->stop();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/I/I/LAVA.png"));
        scene->setSceneRect(0,0,400,400);

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        timer->start();
        personaje1=new Personaje(495,410,30,2, 0, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);

         enemigo1= new Personaje (485,20,60,2,0,":/I/I/ENEMIGO.png");
         scene->addItem(enemigo1);

         enemigo1= new Personaje (75,0,55,2,0,":/I/I/ENEMIGO.png");
         scene->addItem(enemigo1);




         totem= new Personaje (0,0,60 ,1,0, ":/IMAGENES/IMAGENES/TOTEM ARENA.png");
         scene->addItem(totem);
         timer->start();

         muros.push_back(new Pared (30,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro derecha conexion nivel 7
         scene->addItem(muros.back());

         muros.push_back(new Pared (-370,200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro izquierda conexion nivel 7
         scene->addItem(muros.back());

         muros.push_back(new Pared (-170,-200,50,400, ":/IMAGENES/BLOQUE.jpg")); //centro izquierda conexion nivel 7
         scene->addItem(muros.back());

         muros.push_back(new Pared (-500,-200,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha arriba conex nivel 1
         scene->addItem(muros.back());

         muros.push_back(new Pared (-500,-280,50,20, ":/IMAGENES/BLOQUE.jpg")); //derecha abajo conex nivel 1
         scene->addItem(muros.back());


         muros.push_back(new Pared (85,50,30,50, ":/IMAGENES/BLOQUE.jpg")); //puerta conexion nivel 2
         scene->addItem(muros.back());

         boton=new Objeto(255,420,40,"");
        items();

    }
    if (opcion==7)
    {
        timer->stop();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/I/I/LAVA.png"));
        scene->setSceneRect(0,0,400,400);

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        //timer->start();
        personaje1=new Personaje(0,0,30,2, 0, ":/I/I/PERSONAJE1.png");
        scene->addItem(personaje1);

        /*enemigo1= new Personaje (395,210,60,2,0,":/I/I/PERSONAJE1.png");
        scene->addItem(enemigo1);*/

        /*puerta=new Objeto(200,-30, 50,":/I/I/Door1.png" );
        scene->addItem(puerta);*/
         /*totem= new Personaje (0,0,60 ,1,0, ":/I/I/Door1.png");
          *
         scene->addItem(totem);
         timer->start();*/
        muros.push_back(new Pared (200,-200,800,50, ":/IMAGENES/IMAGENES/rocas2.png")); //muro centro
        scene->addItem(muros.back());

        muros.push_back(new Pared (85,-400,30,50, ":/IMAGENES/BLOQUE.jpg")); //puerta abajo conexion nivel 2
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-0,50,30, ":/IMAGENES/BLOQUE.jpg")); //puerta final
        scene->addItem(muros.back());

        muros.push_back(new Pared (150,-90,50,30, ":/IMAGENES/BLOQUE.jpg")); //Puerta final
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-10,50,20, ":/IMAGENES/BLOQUE.jpg")); //puerta segunda parte derecha (arriba)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-90,50,20, ":/IMAGENES/BLOQUE.jpg")); //puerta segunda parte derecha (abajo)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-310,50,20, ":/IMAGENES/BLOQUE.jpg")); //puerta primera parte derecha (arriba)
        scene->addItem(muros.back());

        muros.push_back(new Pared (-500,-390,50,20, ":/IMAGENES/BLOQUE.jpg")); //puerta primera parte derecha (abajo)
        scene->addItem(muros.back());



        items();

    }
}

void MainWindow::items()
{


   /* llave= new Objeto (470,35,30,":/IMAGENES/llave1.png");
    scene->addItem(llave);*/

    bolaH= new Objeto (75,160, 30,":/IMAGENES/IMAGENES/BOLADEMETAL.png");
    scene->addItem(bolaH);



    muros.push_back(new Pared (200,-450,800,100, ""));
    scene->addItem(muros.back());

    muros.push_back(new Pared (200,150,800,100, ""));
    scene->addItem(muros.back());

    muros.push_back(new Pared (250,100,100,800, ""));
    scene->addItem(muros.back());

    muros.push_back(new Pared (-550,100,100,800, ""));
    scene->addItem(muros.back());




   /*
   piedras.push_back(new Objeto(-50,100,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(-120,110,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());*/




   /*puerta=new Objeto(200,-30, 50,":/IMAGENES/PUERTA.png" ); //puerta arriba
   scene->addItem(puerta);

   puerta=new Objeto(-140,200, 50,":/IMAGENES/PUERTA.png" ); //puerta derecha
   puerta->setRotation(270);
   scene->addItem(puerta);

   puerta=new Objeto(550,210, 50,":/IMAGENES/PUERTA.png" ); //puerta izquierda
   puerta->setRotation(90);
   scene->addItem(puerta);*/

   /*dragon=new Sprite ();
   dragon->setPos(110,345);
   scene->addItem(dragon);*/

}

void MainWindow::clean()
{
    scene->removeItem(enemigo1);
    delete (enemigo1);
    scene->removeItem(personaje1);
    delete (personaje1);


     for (int i=0;i<cuerpos.size();i++)
     {

             scene->removeItem(cuerpos.at(i));
             delete (cuerpos.at (i));
             cuerpos.removeOne(cuerpos.at(i));



     }
     for (int i=0;i<piedras.size();i++)
         {
         scene->removeItem(piedras.at(i));
         delete (piedras.at (i));
         piedras.removeOne(piedras.at(i));


         }

     for (int i=0;i<muros.size();i++)
         {
         scene->removeItem(muros.at(i));
         delete (muros.at (i));
         muros.removeOne(muros.at(i));

         }

     scene->removeItem(puerta);
     delete (puerta);
}

void MainWindow::teletransportacion()
{
    if (opcion==1)
    {
        if (personaje1->x()==170 and personaje1->y()==-20) //puerta arriba //conexion nivel 7
        {
            opcion=5;
            niveles(opcion);
        }

    }
    if (opcion==2)
    {
        if (personaje1->x()==170 and personaje1->y()==-20) //puerta arriba //conexion nivel 7
        {
            opcion=2;
            niveles(opcion);
        }
        if (personaje1->x()==120 and personaje1->y()==200) //puerta izquierda //conexion nivel 5
        {
            opcion=5;
            niveles(opcion);
        }
        if (personaje1->x()==90 and personaje1->y()==-400) //puerta abajo //conexion nivel 1
        {
            opcion=1;
            niveles(opcion);
        }
        if (personaje1->x()==520 and personaje1->y()==200) //puerta derecha //conexion nivel 3
        {
            opcion=3;
            niveles(opcion);
        }
    }
    if (opcion==3)
    {
        if (personaje1->x()==-115 and personaje1->y()==220) //puerta izquierda //conexion nivel 2
        {
            opcion=2;
            niveles(opcion);
        }
        if (personaje1->x()==485 and personaje1->y()==420) //puerta izquierda //conexion nivel 4
        {
            opcion=4;
            niveles(opcion);
        }

    }

    if (opcion==4)
    {

    if (personaje1->x()==-115 and personaje1->y()==-20) //puerta izquierda //conexion nivel 1
    {
        opcion=1;
        niveles(opcion);
        personaje1->setPos(515,-20);

    }
    if (personaje1->x()==185 and personaje1->y()==-20) //puerta arriba //conexion nivel 3
    {
        opcion=3;
        niveles(opcion);
        personaje1->setPos(475,360);

    }

    }

    if (opcion==5)
    {
        if (personaje1->x()==170 and personaje1->y()==415) //puerta arriba //conexion nivel 7
        {
            opcion=7;
            niveles(7);
            //personaje1->setPos(515,-20);

        }

        if (personaje1->x()==170 and personaje1->y()==415) //puerta abajo//conexion nivel 1
        {
            opcion=1;
            niveles(1);
            //personaje1->setPos(515,-20);

        }
        if (personaje1->x()==520 and personaje1->y()==200) //puerta derecha//conexion nivel 3
        {
            opcion=3;
            niveles(opcion);
            //personaje1->setPos(515,-20);

        }
        if (personaje1->x()==-120 and personaje1->y()==220) //puerta izquierda //conexion nivel 2
        {
            opcion=2;
            niveles(opcion);
            //personaje1->setPos(515,-20);

        }


    }
    if (opcion==6)
    {

        if (personaje1->x()==515 and personaje1->y()==250) //puerta derecha conex nivel 1
        {

            opcion=1;
            niveles(opcion);
            //personaje1->setPos(515,-20);

        }
        if (personaje1->x()==-115 and personaje1->y()==-20) //puerta arriba //conexion nivel 2
        {

            opcion=2;
            niveles(opcion);
            //personaje1->setPos(515,-20);

        }
    }
    if (opcion==7)
    {
        if (personaje1->x()==520 and personaje1->y()==360) //puerta derecha conex nivel 1
        {


            personaje1->setPos(520,60);

        }


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


//--------------------------------------------------FISICAS--------------------------------------------------


void MainWindow::CoeficienteRestitucion()
{

}

void MainWindow::aceleracion(int)
{

}


void MainWindow:: lanzamiento ()
{

          /*  int xinicial=0;
            int xfinal=personaje1->x();
             int yinicial=0;
            int yfinal=personaje1->y();

    while ((xinicial!=xfinal) or (yinicial!=yfinal))
        {

            if (xinicial<xfinal)
            {

                xinicial++;

                if(yinicial<yfinal)
                {
                    yinicial++;

                }

                if (yinicial>yfinal)
                {
                    yinicial--;

                }

            path++;
            }
            //cout<<" PATH: "<<"( "<<xinicial<<" ; "<<yfinal<<" ) "<<endl;

            else
            if(xinicial>xfinal)

            {

                xinicial--;
                if(yinicial<yfinal)
                {
                    yinicial++;

                }
                if (yinicial>yfinal)
                {
                    yinicial--;

                }


                path++;
                }
            if(path%10==0)
            {if (i==1)
            {
                bolaFuego->setPos(xinicial,yinicial);
                scene->addItem(bolaFuego);
                timer->start(30);

            }

            if(i==100)
            {
                bolaFuego->setPos(xinicial,yinicial);
                scene->addItem(bolaFuego);
                i=0;
                timer->start(30);
            }

            i++;

}
    }
*/


}


void MainWindow::lanzarfuego()
{
if (opcion==1)
{



       /* x = enemigo1->x();
        y = enemigo1->y();
       cuerpos.push_back(new Particula (0,x, y,100,30,":/IMAGENES/BOLA DE FUEGO.png"));
        scene->addItem(cuerpos.back());

        timer->start(30);*/

}
}




void MainWindow::mover()
{/*
    for (QList<Particula*> :: iterator it=cuerpos.begin(); it!=cuerpos.end(); it++)
    {
        (*it)->CalcularVelocidad();
        (*it)->ActualizarPosicion();


    }
    for (int i=0;i<cuerpos.size();i++)
    {
        if (personaje1->collidesWithItem(cuerpos.at(i)))
           {
            scene->removeItem(cuerpos.at(i));
            cuerpos.removeOne(cuerpos.at(i));
            //vidas-=1;
            }
    }

*/
}

void MainWindow::moverEnemigo( )
{

    if(ban==false)
    {
        enemigo1->setX(enemigo1->x()+2);

     if(enemigo1->x()<100)
     {
         enemigo1->setX(enemigo1->x()+2 /**enemigo1->aceleracion+2*/);
     }
     else if (enemigo1->x()<300)
        {
         enemigo1->setX(enemigo1->x()+2/**enemigo1->aceleracion*/);
     }
     else if (enemigo1->x()<500)
        {
         enemigo1->setX(enemigo1->x()+2/**enemigo1->aceleracion+1*/);
     }
     else if(enemigo1->x()>514)
     {
         ban=true;
     }
    }
    if(ban==true)
        {
        enemigo1->setX(enemigo1->x()-2);

        if(enemigo1->x()<100)
           {
            enemigo1->setX(enemigo1->x()-2/**enemigo1->aceleracion+2*/);
            }
        else if (enemigo1->x()<300)
           {
            enemigo1->setX(enemigo1->x()-2/**enemigo1->aceleracion*/);
        }
        else if (enemigo1->x()<500)
           {
            enemigo1->setX(enemigo1->x()-2/**enemigo1->aceleracion+1*/);
        }
       if(enemigo1->x()<-116)
        {
           ban=false;
        }
        }


}



//-------------------------------------------------DESTRUCTOR---------------------------------------------------------------


MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::actualizar()
{

    for (int i=0; i<LISTA.size();i++)
    {
        for(int j=0; j<LISTA.size();j++)
        {
            if(i!=j)
            {
                //LISTA.at(i) ->Acacelx(*LISTA.at(j));


               // LISTA.at(i) ->Acacely(*LISTA.at(j));
            }
        }
    }
   /* for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();


    }*/

}

