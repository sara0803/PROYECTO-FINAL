/*#include "gifanimation.h"

#include <QLabel>
#include <QMovie>

GifAnimation::GifAnimation(QObject *parent)
    :QObject(parent)
{

    mLabel= new QLabel(this);
    mMovie=new QMovie(this);
}

void GifAnimation::startMovie()
{
    mMovie ->setFileName(mFilename);
    mMovie->start();
    mLabel->setMovie(mMovie);
}
*/
