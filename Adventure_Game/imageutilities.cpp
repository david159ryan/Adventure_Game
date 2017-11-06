#include "imageutilities.h"


QImage ImageUtilities::GetBackgroundString(std::string name)
{
    std::string imageName = ":/gfx/backgrounds/" + name + ".png";
    QString qImageString = QString::fromLocal8Bit(imageName.c_str());
    QImage image(qImageString);
    return image;
}

QImage ImageUtilities::GetObjectImageString(std::string name)
{
    std::string imageName = ":/gfx/interactables/" + name + ".png";
    QString qImageString = QString::fromLocal8Bit(imageName.c_str());
    QImage image(qImageString);
    return image;
}
