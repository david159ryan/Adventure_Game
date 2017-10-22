#include "locationui.h"
#include "iostream"
#include "eventmanager.h"

QImage GetBackgroundString(string);

LocationUI::LocationUI(MainWindow * window) :
    Updateable()
{
    this->window = window;
    eventManager.RegisterListener("LocationChange", this);
}

void LocationUI::Update(void)
{
    Location * newLocation = locationManager.GetCurrentLocation();
    string name = newLocation->GetName();

    if(scenes.find(name) == scenes.end())
    {
        scenes[name] = new QGraphicsScene();
        QImage qimage = GetBackgroundString(name);
        QRectF sceneRect = window->GetGraphicsView()->sceneRect();
        QPixmap image = QPixmap::fromImage(qimage);
        QGraphicsPixmapItem* pPixmap = scenes[name]->addPixmap(image);
        window->GetGraphicsView()->fitInView(pPixmap);
    }
    QGraphicsScene * scene = scenes[name];
    window->LoadScene(scene);
    window->PlayMusic(name);
}

QImage GetBackgroundString(string name)
{
    string imageName = ":/gfx/backgrounds/" + name + ".png";
    QString qImageString = QString::fromLocal8Bit(imageName.c_str());
    QImage image(qImageString);
    return image;
}
