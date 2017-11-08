#ifndef IMAGEUTILITIES_H
#define IMAGEUTILITIES_H

#include <QImage>
#include <QString>
#include "string"

class ImageUtilities
{
public:
    static QImage GetBackgroundString(std::string name);
    static QImage GetObjectImageString(std::string name);
private:
    ImageUtilities(){}
};

#endif // IMAGEUTILITIES_H
