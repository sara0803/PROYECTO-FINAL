#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //intro->setMedia(QUrl("qrc:/SONIDOS/SONIDOS/fantasy.mp3"));


niveles(opcion);


start=new QPushButton("INICIAR JUEGO", this);

start->setGeometry(QRect( QPoint(310,160), //250x160
QSize(200, 50) ));
//200x 50

connect(start, SIGNAL (clicked()),this, SLOT (botonInicio()));
start->setStyleSheet("background-color: gray");

saveData=new QPushButton ("CONTINUAR PARTIDA ",this);
saveData->setGeometry(QRect( QPoint(310,300), //250x160
QSize(200, 50) ));

connect(saveData, SIGNAL (clicked()),this, SLOT (guardarPartida()));
saveData->setStyleSheet("background-color: gray");

bolaFuego=new Objeto(0,0,30, ":/IMAGENES/BOLA DE FUEGO.png");

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
 qDebug()<<personaje1->pos()<<personaje1->x();

if (opcion==1)
{
    if(evento->key()==Qt::Key_A)
    {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());

       //---------GIRO DEL PERSONAJE-------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->setRotation(180);
    personaje1->izquierda();


    //---------COALISIONES-------
    if(personaje1->collidesWithItem(bolaH))
    {
            bolaH->izquierda();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
            enemigo1->izquierda();
            x = enemigo1->x();
            y = enemigo1->y();
            cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
            scene->addItem(cuerpos.back());

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
    //-------EVALUAR COALISIONES CON MUROS-----
    for (int i=0;i<muros.size();i++)
    {
        if (personaje1->collidesWithItem(muros.at(i)))
        {

            personaje1->derecha();
        }
    }


    //-------EVALUAR COALISIONES CON PIEDRAS-----

    for (int i=0;i<piedras.size();i++)
        {
            if (personaje1->collidesWithItem(piedras.at(i)))
            {

                personaje1->derecha();
            }
        }

    //-------CAPTURAR LLAVES-----
    if (personaje1->collidesWithItem(llave))
        {
             //key->play();
           scene->removeItem(llave);


             //llaves+=1;

        }

    //------------PUERTA--------------
    if (personaje1->collidesWithItem(puerta))
            {

                personaje1->derecha();
                //remover escena
            }


    }

    else if(evento->key()==Qt::Key_D)
    {
       //lanzamiento(-40,personaje1->x(),70,personaje1->y());

        //---------GIRO DEL PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(0);
        personaje1->derecha();

        //---------COALISIONES-------
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
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {



                personaje1->izquierda();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                scene->removeItem(llave);


                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->izquierda();
                    //remover escena
                }



    }
    else if(evento->key()==Qt::Key_W)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


            //---------GIRO DE PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(270);
        personaje1->subir();


        //---------COALISIONES-------
        if(personaje1->collidesWithItem(bolaH))
        {
                bolaH->subir();
        }
        if(personaje1->collidesWithItem(enemigo1))

        {
                enemigo1->subir();


                x = enemigo1->x();
                y = enemigo1->y();
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {


                personaje1->bajar();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                 scene->removeItem(llave);

                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->bajar();
                    //remover escena
                }


    }
    else if(evento->key()==Qt::Key_S)
        {
       //lanzamiento(-40,personaje1->x(),70,personaje1->y());


          //---------GIRO DE PERSONAJE-------
          personaje1->setTransformOriginPoint(0,0);
          personaje1->setRotation(90);
          personaje1->bajar();


          //---------COALISIONES-------
          if(personaje1->collidesWithItem(bolaH))
          {
                  bolaH->bajar();
          }
          if(personaje1->collidesWithItem(enemigo1))


          {

              x = enemigo1->x();
              y = enemigo1->y();
                  enemigo1->bajar();
                  cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                  scene->addItem(cuerpos.back());

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

            //-------EVALUAR COALISIONES CON MUROS-----

          for (int i=0;i<muros.size();i++)
          {
              if (personaje1->collidesWithItem(muros.at(i)))
              {

                  personaje1->subir();
              }
          }
          //-------EVALUAR COALISIONES CON PIEDRAS-----

          for (int i=0;i<piedras.size();i++)
              {
                  if (personaje1->collidesWithItem(piedras.at(i)))
                  {

                      personaje1->derecha();
                  }
              }

          //-------CAPTURAR LLAVES-----
          if (personaje1->collidesWithItem(llave))
              {
                  //key->play();
                 scene->removeItem(llave);

                   //llaves+=1;

              }

          //------------PUERTA--------------
          if (personaje1->collidesWithItem(puerta))
                  {
                      personaje1->subir();
                      //remover escena
                  }





        }

// qDebug()<<personaje1->pos()<<personaje1->x();

//-------------------------------------------EVENTO PERSONAJE 2------------------------------------------------------------
if(evento->key()==Qt::Key_I)
{

    personaje2->subir();

}
if(evento->key()==Qt::Key_J)
{
    personaje2->izquierda();


}
if(evento->key()==Qt::Key_L)
{

    personaje2->derecha();

}
if(evento->key()==Qt::Key_K)
{

    personaje2->bajar();

}
 if (((personaje1->x()==250 or personaje2->x()==250)    and (personaje1->y()==390 or personaje2->y()==390 )) )
 {


    opcion=2;
    niveles(opcion);

 }


}
if (opcion==2)
{
    if(evento->key()==Qt::Key_A)
    {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());

       //---------GIRO DEL PERSONAJE-------
    personaje1->setTransformOriginPoint(0,0);
    //personaje1->setRotation(180);
    personaje1->izquierda();


    //---------COALISIONES-------
    if(personaje1->collidesWithItem(bolaH))
    {
            bolaH->izquierda();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
            enemigo1->izquierda();
            x = enemigo1->x();
            y = enemigo1->y();
            cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
            scene->addItem(cuerpos.back());

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
    //-------EVALUAR COALISIONES CON MUROS-----
    for (int i=0;i<muros.size();i++)
    {
        if (personaje1->collidesWithItem(muros.at(i)))
        {

            personaje1->derecha();
        }
    }


    //-------EVALUAR COALISIONES CON PIEDRAS-----

    for (int i=0;i<piedras.size();i++)
        {
            if (personaje1->collidesWithItem(piedras.at(i)))
            {

                personaje1->derecha();
            }
        }

    //-------CAPTURAR LLAVES-----
    if (personaje1->collidesWithItem(llave))
        {
             //key->play();
           scene->removeItem(llave);


             //llaves+=1;

        }

    //------------PUERTA--------------
    if (personaje1->collidesWithItem(puerta))
            {

                personaje1->derecha();
                //remover escena
            }


    }

    else if(evento->key()==Qt::Key_D)
    {
       //lanzamiento(-40,personaje1->x(),70,personaje1->y());

        //---------GIRO DEL PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(0);
        personaje1->derecha();

        //---------COALISIONES-------
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
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {



                personaje1->izquierda();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                scene->removeItem(llave);


                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->izquierda();
                    //remover escena
                }



    }
    else if(evento->key()==Qt::Key_W)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


            //---------GIRO DE PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(270);
        personaje1->subir();


        //---------COALISIONES-------
        if(personaje1->collidesWithItem(bolaH))
        {
                bolaH->subir();
        }
        if(personaje1->collidesWithItem(enemigo1))

        {
                enemigo1->subir();


                x = enemigo1->x();
                y = enemigo1->y();
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {


                personaje1->bajar();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                 scene->removeItem(llave);

                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->bajar();
                    //remover escena
                }


    }
    else if(evento->key()==Qt::Key_S)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


          //---------GIRO DE PERSONAJE-------
          personaje1->setTransformOriginPoint(0,0);
          personaje1->setRotation(90);
          personaje1->bajar();


          //---------COALISIONES-------
          if(personaje1->collidesWithItem(bolaH))
          {
                  bolaH->bajar();
          }
          if(personaje1->collidesWithItem(enemigo1))


          {

              x = enemigo1->x();
              y = enemigo1->y();
                  enemigo1->bajar();
                  cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                  scene->addItem(cuerpos.back());

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

            //-------EVALUAR COALISIONES CON MUROS-----

          for (int i=0;i<muros.size();i++)
          {
              if (personaje1->collidesWithItem(muros.at(i)))
              {

                  personaje1->subir();
              }
          }
          //-------EVALUAR COALISIONES CON PIEDRAS-----

          for (int i=0;i<piedras.size();i++)
              {
                  if (personaje1->collidesWithItem(piedras.at(i)))
                  {

                      personaje1->derecha();
                  }
              }

          //-------CAPTURAR LLAVES-----
          if (personaje1->collidesWithItem(llave))
              {
                  //key->play();
                 scene->removeItem(llave);

                   //llaves+=1;

              }

          //------------PUERTA--------------
          if (personaje1->collidesWithItem(puerta))
                  {
                      personaje1->subir();
                      //remover escena
                  }





        }




 if ((personaje1->x()==250 and personaje1->y()==390) )
 {



    niveles(3);

 }

}
if (opcion==3)
{

    if(evento->key()==Qt::Key_A)
    {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());

       //---------GIRO DEL PERSONAJE-------
    personaje1->setTransformOriginPoint(0,0);
    personaje1->setRotation(180);
    personaje1->izquierda();


    //---------COALISIONES-------
    if(personaje1->collidesWithItem(bolaH))
    {
            bolaH->izquierda();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
            enemigo1->izquierda();
            x = enemigo1->x();
            y = enemigo1->y();
            cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
            scene->addItem(cuerpos.back());

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
    //-------EVALUAR COALISIONES CON MUROS-----
    for (int i=0;i<muros.size();i++)
    {
        if (personaje1->collidesWithItem(muros.at(i)))
        {

            personaje1->izquierda();
        }
    }


    //-------EVALUAR COALISIONES CON PIEDRAS-----

    for (int i=0;i<piedras.size();i++)
        {
            if (personaje1->collidesWithItem(piedras.at(i)))
            {

                personaje1->derecha();
            }
        }

    //-------CAPTURAR LLAVES-----
    if (personaje1->collidesWithItem(llave))
        {
             //key->play();
           scene->removeItem(llave);


             //llaves+=1;

        }

    //------------PUERTA--------------
    if (personaje1->collidesWithItem(puerta))
            {

                personaje1->derecha();
                //remover escena
            }


    }

    else if(evento->key()==Qt::Key_D)
    {
       //lanzamiento(-40,personaje1->x(),70,personaje1->y());

        //---------GIRO DEL PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(0);
        personaje1->derecha();

        //---------COALISIONES-------
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
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {



                personaje1->izquierda();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                scene->removeItem(llave);


                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->izquierda();
                    //remover escena
                }



    }
    else if(evento->key()==Qt::Key_W)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


            //---------GIRO DE PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        personaje1->setRotation(270);
        personaje1->subir();


        //---------COALISIONES-------
        if(personaje1->collidesWithItem(bolaH))
        {
                bolaH->subir();
        }
        if(personaje1->collidesWithItem(enemigo1))

        {
                enemigo1->subir();


                x = enemigo1->x();
                y = enemigo1->y();
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

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
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {


                personaje1->derecha();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->derecha();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {
                //key->play();
                 scene->removeItem(llave);

                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->bajar();
                    //remover escena
                }


    }
    else if(evento->key()==Qt::Key_S)
        {
       // lanzamiento(-40,personaje1->x(),70,personaje1->y());


          //---------GIRO DE PERSONAJE-------
          personaje1->setTransformOriginPoint(0,0);
          personaje1->setRotation(90);
          personaje1->bajar();


          //---------COALISIONES-------
          if(personaje1->collidesWithItem(bolaH))
          {
                  bolaH->bajar();
          }
          if(personaje1->collidesWithItem(enemigo1))


          {

              x = enemigo1->x();
              y = enemigo1->y();
                  enemigo1->bajar();
                  cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                  scene->addItem(cuerpos.back());

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

            //-------EVALUAR COALISIONES CON MUROS-----

          for (int i=0;i<muros.size();i++)
          {
              if (personaje1->collidesWithItem(muros.at(i)))
              {

                  personaje1->subir();
              }
          }
          //-------EVALUAR COALISIONES CON PIEDRAS-----

          for (int i=0;i<piedras.size();i++)
              {
                  if (personaje1->collidesWithItem(piedras.at(i)))
                  {

                      personaje1->derecha();
                  }
              }

          //-------CAPTURAR LLAVES-----
          if (personaje1->collidesWithItem(llave))
              {
                  //key->play();
                 scene->removeItem(llave);

                   //llaves+=1;

              }

          //------------PUERTA--------------
          if (personaje1->collidesWithItem(puerta))
                  {
                      personaje1->subir();
                      //remover escena
                  }





        }

// qDebug()<<personaje1->pos()<<personaje1->x();


 if ((personaje1->x()==250 and personaje1->y()==390) )
 {



    //niveles(3);

 }

}





}




MainWindow::~MainWindow()
{
    delete ui;
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


}

void MainWindow::botonInicio()
{
    opcion=1;
    niveles(opcion);
}

void MainWindow::moverEnemigo( )
{

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


}

void MainWindow::CoeficienteRestitucion()
{

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

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);


        //CREANDO LA ESCENA
        ui->setupUi(this);
        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setBackgroundBrush(QPixmap(":/IMAGENES/PisoPiedra.jpg"));
        scene->setSceneRect(0,0,400,400);




            personaje1=new Personaje(495,410,30,1,10, ":/IMAGENES/PERSONAJE1.png");
            scene->addItem(personaje1);

            personaje2=new Personaje(0,0,45,10,0, ":/IMAGENES/PERSONAJE2.png");
            scene->addItem(personaje2);

            enemigo1= new Personaje (-105,310,60,1,0,":/IMAGENES/ENEMIGO.png");
            scene->addItem(enemigo1);

            timerEnem= new QTimer;
            timerEnem->stop();
            connect(timerEnem, SIGNAL(timeout()), this , SLOT (moverEnemigo()));
            timerEnem->start(40);

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

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        timer->start();
        personaje1=new Personaje(495,410,30,2,0, ":/IMAGENES/PERSONAJE1.png");
        scene->addItem(personaje1);

        enemigo1= new Personaje (-135,415,60,1,0,":/IMAGENES/ENEMIGO.png");
        scene->addItem(enemigo1);








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

        QTimer *cronometro2 = new QTimer(this);
        connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
        cronometro2->start(1000);
        timer->start();
        personaje1=new Personaje(495,410,30,2, 0, ":/IMAGENES/PERSONAJE1.png");
        scene->addItem(personaje1);

        enemigo1= new Personaje (395,210,60,2,0,":/IMAGENES/SERPIENTE1 (1).png");
         scene->addItem(enemigo1);

         totem= new Personaje (0,0,60 ,1,0, ":/IMAGENES/TOTEM ARENA.png");
         scene->addItem(totem);
         timer->start();


        items();

    }

}

void MainWindow::aceleracion(int)
{

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



     scene->removeItem(puerta);
     delete (puerta);
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



