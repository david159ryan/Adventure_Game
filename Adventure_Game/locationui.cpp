#include "locationui.h"
#include "iostream"
#include "eventmanager.h"

QImage GetBackgroundString(string);
QImage GetObjectImageString(string);

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
        // set up a scene.. add background image
        scenes[name] = new QGraphicsScene();
        QImage qimage = GetBackgroundString(name);
        QPixmap image = QPixmap::fromImage(qimage);
        QGraphicsPixmapItem* pPixmap = scenes[name]->addPixmap(image);
        window->GetGraphicsView()->fitInView(pPixmap);

        //add interactable objects
        cout << "making location with " << newLocation->GetObjectNum() << " objects" << endl;

        int oSize = newLocation->GetObjectNum();
        for(int i = 0; i < oSize; i++)
        {
            Object * o = newLocation->GetObjectAt(i);
            cout << "making button " << o->GetName() << endl;
            QToolButton * b = new QToolButton();
            QPixmap pixmap = QPixmap::fromImage(GetObjectImageString(o->GetName()));
            QIcon ButtonIcon(pixmap);
            b->setIcon(ButtonIcon);
            b->setIconSize(pixmap.rect().size());
            b->setStyleSheet("QToolButton { background-color: rgba(0,0,0,0) }");
            b->setGeometry(500,500,pixmap.rect().size().width(),pixmap.rect().size().height());
            window->ConnectButton(b, o);
            scenes[name]->addWidget(b);
        }
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

QImage GetObjectImageString(string name)
{
    string imageName = ":/gfx/interactables/" + name + ".png";
    QString qImageString = QString::fromLocal8Bit(imageName.c_str());
    QImage image(qImageString);
    return image;
}
