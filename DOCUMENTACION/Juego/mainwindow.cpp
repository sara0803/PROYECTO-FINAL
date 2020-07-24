#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


niveles(opcion);


start=new QPushButton("INICIAR JUEGO", this);

start->setGeometry(QRect( QPoint(310,160), // Valores por defecto 250x160
QSize(200, 50) ));
//Valores por defecto : 200x 50

connect(start, SIGNAL (clicked()),this, SLOT (botonInicio()));
start->setStyleSheet("background-color: gray");

saveData=new QPushButton ("CONTINUAR PARTIDA ",this);


saveData->setGeometry(QRect( QPoint(310,300),
QSize(200, 50) ));

connect(saveData, SIGNAL (clicked()),this, SLOT (guardarPartida()));
saveData->setStyleSheet("background-color: gray");

bolaFuego=new Objeto(0,0,30, ":/IMAGENES/BOLADEFUEGO.png");

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

 if (((personaje1->x()==250 or personaje2->x()==250)    and (personaje1->y()==390 or personaje2->y()==390 )) )
 {


    opcion=2;
    niveles(opcion);

 }

}

//--------------------------------------------------EVENTO PERSONAJE 1 NIVEL 2-------------------------------------------------

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




//------------------------------------------------CAMBIO DE NIVEL 2 A 3-------------------------------------------------

 if ((personaje1->x()==250 and personaje1->y()==390) )
 {

    niveles(3);

 }


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
    resorte('A', personaje1);
    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    /*for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }
    */
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
    resorte('D', personaje1);
    //bolaFuego->setPosx(personaje1->pos());
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }

    /*for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }*/
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
    resorte('W', personaje1);


    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    /*for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje1->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }*/
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
              resorte('S', personaje1);
              //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
              //scene->addItem(cuerpos.back());

              timer->start(30);
      }
      /*for (int i=0;i<cuerpos.size();i++)
      {
          if (personaje1->collidesWithItem(cuerpos.at(i)))
             {
              scene->removeItem(cuerpos.at(i));
              cuerpos.removeOne(cuerpos.at(i));
              //vidas-=1;
              }
      }
      */
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
    resorte('I', personaje2);


    x = enemigo1->x();
    y = enemigo1->y();
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    /*for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje2->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }*/
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
        resorte('J', personaje2);
        x = enemigo1->x();
        y = enemigo1->y();
        //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
        //scene->addItem(cuerpos.back());

        timer->start(30);
        }
        /*for (int i=0;i<cuerpos.size();i++)
        {
        if (personaje2->collidesWithItem(cuerpos.at(i)))
        {
        scene->removeItem(cuerpos.at(i));
        cuerpos.removeOne(cuerpos.at(i));
        //vidas-=1;
        }
        }*/
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
    resorte('L', personaje2);
    //bolaFuego->setPosx(personaje1->pos());
    //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
    //scene->addItem(cuerpos.back());

    timer->start(30);
    }
    /*
    for (int i=0;i<cuerpos.size();i++)
    {
    if (personaje2->collidesWithItem(cuerpos.at(i)))
    {
    scene->removeItem(cuerpos.at(i));
    cuerpos.removeOne(cuerpos.at(i));
    //vidas-=1;
    }
    }*/
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
           resorte('K', personaje2);
              //cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
              //scene->addItem(cuerpos.back());

              timer->start(30);
      }
      /*for (int i=0;i<cuerpos.size();i++)
      {
          if (personaje2->collidesWithItem(cuerpos.at(i)))
             {
              scene->removeItem(cuerpos.at(i));
              cuerpos.removeOne(cuerpos.at(i));
              //vidas-=1;
              }
      }
        */
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

        scene->setBackgroundBrush(QPixmap(":/IMAGENES/MAINMENU.png"));
        scene->setSceneRect(0,0,790,550);

        intro=new QMediaPlayer ();
        intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


        //intro->play();



    }
    if (opcion==1)
    {


        //intro->stop();
        key=new QMediaPlayer ();
        key->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/KEY.wav"));

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);

       /* QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(magnetismo()));
        cronometro2->start(1000);*/

       /* parabolico= new QTimer;
        parabolico->stop();
        connect(parabolico,SIGNAL(timeout()),this,SLOT(Mover()));
        parabolico->start(40);*/
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/PisoPiedra.jpg"));
        scene->setSceneRect(0,0,400,400);



                                    //x,y ,r,friccion,a,v,ang,path
            personaje1=new Personaje(495,410,30,1,10, ":/IMAGENES/PERSONAJE1.png");
            scene->addItem(personaje1);

            personaje2=new Personaje(0,0,45,1,10, ":/IMAGENES/PERSONAJE2.png");
            scene->addItem(personaje2);

            enemigo1= new Personaje (-105,310,60,1,5,":/IMAGENES/ENEMIGO.png"); //antes -105, 310
            scene->addItem(enemigo1);

            timerEnem= new QTimer;
            timerEnem->stop();
            connect(timerEnem, SIGNAL(timeout()), this , SLOT (moverEnemigo()));
            timerEnem->start(40);

            rigidez=20;

            //particula1=new Particula( -105,310,0,0,50000,200,  ":/IMAGENES/BOLADEMETAL.png ");
            //particula2=new Particula(-5000,0,0,0,70,70 ,":/IMAGENES/BOLA DE FUEGO.png ");





           /* disparo=new QTimer;
            disparo->stop();
            connect(disparo, SIGNAL(timeout()), this , SLOT (lanzamiento));
            disparo->start(1000);*/









        items();



    }
    if (opcion==2)
    {

        timer->stop();
        clean();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/black_stone.jpg"));
        scene->setSceneRect(0,0,400,400);

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);
       /* parabolico= new QTimer;
        parabolico->stop();
        connect(parabolico,SIGNAL(timeout()),this,SLOT(Mover()));
        parabolico->start(40);
        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);*/
        timer->start();         //x,y ,r,friccion,a,v,ang,path
        personaje1=new Personaje(495,410,30,1.5,0, ":/IMAGENES/PERSONAJE1.png");
        scene->addItem(personaje1);

        enemigo1= new Personaje (-135,415,60,1.5,0, ":/IMAGENES/ENEMIGO.png");
        scene->addItem(enemigo1);


        rigidez=40;







        items();


    }
    if (opcion==3)
    {
        timer->stop();
        clean();
        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/ARENA.jpg"));
        scene->setSceneRect(0,0,400,400);

        timer= new QTimer;
        connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
        QTimer *cronometro = new QTimer(this);
        connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
        cronometro->start(1000);
       /* parabolico= new QTimer;
        parabolico->stop();
        connect(parabolico,SIGNAL(timeout()),this,SLOT(Mover()));
        parabolico->start(40);
        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);*/
        timer->start();         //x,y ,r,friccion,a,v,ang,path
        personaje1=new Personaje(495,410,30,1.2, 1, ":/IMAGENES/PERSONAJE1.png");
        scene->addItem(personaje1);

        enemigo1= new Personaje (395,210,60,1.5,1,":/IMAGENES/SERPIENTE1(1).png");
         scene->addItem(enemigo1);

         totem= new Personaje (0,0,60 ,1,1.5, ":/IMAGENES/TOTEMARENA.png");
         scene->addItem(totem);
         timer->start();

         rigidez=80;

        items();

    }

}

void MainWindow::items()
{


    llave= new Objeto (415,360,30,":/IMAGENES/llave1.png");
    scene->addItem(llave);

    bolaH= new Objeto (75,160, 30,":/IMAGENES/BOLADEMETAL.png");
    scene->addItem(bolaH);

    puerta=new Objeto(465,25, 80,":/IMAGENES/Door1.png" );
    scene->addItem(puerta);


    muros.push_back(new Pared (200,-450,800,100, ":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());

    muros.push_back(new Pared (200,150,800,100, ":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());

    muros.push_back(new Pared (250,100,100,800, ":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());

    muros.push_back(new Pared (-550,100,100,800, ":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());



   piedras.push_back(new Objeto(135,110,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(280,220,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(275,115,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(140,220,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(135,170,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(205,110,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(275,160,40,":/IMAGENES/rocas2.png"));
   scene->addItem(piedras.back());

   dragon=new Sprite ();
   dragon->setPos(110,345);
   scene->addItem(dragon);

}

void MainWindow::clean()
{
    scene->removeItem(enemigo1);
    delete (enemigo1);
    scene->removeItem(personaje1);
    delete (personaje1);


     /*for (int i=0;i<cuerpos.size();i++)
     {

             scene->removeItem(cuerpos.at(i));
             delete (cuerpos.at (i));
             cuerpos.removeOne(cuerpos.at(i));



     }*/
     for (int i=0;i<piedras.size();i++)
         {
         scene->removeItem(piedras.at(i));
         delete (piedras.at (i));
         piedras.removeOne(piedras.at(i));

         }



     scene->removeItem(puerta);
     delete (puerta);
}

void MainWindow::guardarPartida()
{
     QFile archivo("PLANETAS.txt");
    if(archivo.open(QIODevice::Append | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);


            //datosArchivo << text<< endl;

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
{if (opcion==1){
        x = enemigo1->x();
        y = enemigo1->y();
       cuerpos.push_back(new Particula (0,x, y,100,30,":/IMAGENES/BOLADEFUEGO.png"));
        scene->addItem(cuerpos.back());
        timer->start(30);
}

}
void MainWindow::mover()
{
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
    for (int i=0;i<cuerpos.size();i++)
    {
        if (personaje2->collidesWithItem(cuerpos.at(i)))
           {
            scene->removeItem(cuerpos.at(i));
            cuerpos.removeOne(cuerpos.at(i));
            //vidas-=1;
            }

    }
}

void MainWindow::resorte(char letra , Personaje *personaje)
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

void MainWindow::magnetismo()
{
  /*if (opcion==1)
    {float f, dx, dy,r;
    dx=enemigo1->x()-personaje1->x();
    dy=enemigo1->x()-personaje1->x();
    r=pow(dx,2)+pow(dy,2);
    f=(M*M)/(K*pow(r,2));
    x = enemigo1->x()*f;
    y = enemigo1->y()*f;
    bolaFuego->setPos(x,y);
    scene->addItem(bolaFuego);
    timer->start(30);
    }*/
}

void MainWindow::Mover()
{/*
    for(QList<particula*>::iterator it=cuerpos.begin(); it!=cuerpos.end();it++)
    {
        (*it)->CalcularVelicidad();
        (*it)->ActualizarPosicion();
    }
    double ang,x,y,v,a;
    ang= enemigo1->angulo;
    x= enemigo1->posx;
    y= enemigo1->posy;
    v= enemigo1->velocidad;
    a= (ang/180)*3.1416;
    cuerpos.push_back(new particula(rad, x, y, v));
    scene->addItem(cuerpos.back());
    //cuerpo= new particula(rad, x, y, v);
    //Scene->addItem(cuerpo);
    timer->start(30);*/

}

void MainWindow::moverEnemigo( )
{
/*
    if(ban==false)
    {enemigo1->setX(enemigo1->x()+2);
     if(enemigo1->x()<100)
        {enemigo1->setX(enemigo1->x()+2*enemigo1->aceleracion+2);}
     else if (enemigo1->x()<300)
        {enemigo1->setX(enemigo1->x()+2*enemigo1->aceleracion);}
     else if (enemigo1->x()<500)
        {enemigo1->setX(enemigo1->x()+2*enemigo1->aceleracion+1);}
     else if(enemigo1->x()>514)
     {ban=true;
     }
    }
    if(ban==true)
        {enemigo1->setX(enemigo1->x()-2);
        if(enemigo1->x()<100)
           {enemigo1->setX(enemigo1->x()-2*enemigo1->aceleracion+2);}
        else if (enemigo1->x()<300)
           {enemigo1->setX(enemigo1->x()-2*enemigo1->aceleracion);}
        else if (enemigo1->x()<500)
           {enemigo1->setX(enemigo1->x()-2*enemigo1->aceleracion+1);}
       if(enemigo1->x()<-116)
        {ban=false;
        }
        }

*/
}



//-------------------------------------------------DESTRUCTOR---------------------------------------------------------------


MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::actualizar()
{


    /*for (int i=0; i<LISTA.size();i++)
    {
        for(int j=0; j<LISTA.size();j++)
        {
            if(i!=j)
            {
                //particula1-> Acacelx(*(particula2));

               // LISTA.at(i)-> Acacely(*(LISTA.at(j) ));
            }
        }
    }
    for(int i=0;i<LISTA.size();i++)
    {
       //LISTA.at(i)->Actualizar();
        particula1->Actualizar(particula1);
        particula1->Actualizar(particula2);


    }*/
    //actualiza cada dato



//actualiza cada dato
}

