/*#ifndef GIFANIMATION_H
#define GIFANIMATION_H

#include <QObject>
#include <QLabel>
class QLabel;
class QMovie;

class GifAnimation: public QObject
{
public:
    GifAnimation(QObject *parent = 0);

     void startMovie();
    void setFileMovie (const QString &ruta);

    void setFilename (const QString &filename)
    {
        mFilename=filename;
    }

    QString getFilename() const
    {
        return mFilename;
    }

private:

    QLabel *mLabel;
    QMovie *mMovie;
    QString mFilename;
};

#endif // GIFANIMATION_H
*/
