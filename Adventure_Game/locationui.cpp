#include "locationui.h"
#include "iostream"
#include "eventmanager.h"

QImage GetBackgroundString(string);
QImage GetObjectImageString(string);

LocationUI::LocationUI(MainWindow * window) :
    Updateable()
{
    this->window = window;
    July5::GetInstance().RegisterListener(Event::LocationChanged, this);
    July5::GetInstance().RegisterListener(Event::ActionPerformed, this);
}

void LocationUI::Update(Event event)
{
    switch(event)
    {
    case Event::ActionPerformed:
        ActionPerformed();
        break;
    case Event::LocationChanged:
        LocationChanged();
        break;
    default:
        break;
    }
}

void LocationUI::LocationChanged()
{
    Location * newLocation = July5::GetInstance().GetCurrentLocation();
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
            ObjectButton * b = new ObjectButton(o);
            QPixmap pixmap = QPixmap::fromImage(GetObjectImageString(o->GetName()));
            QIcon ButtonIcon(pixmap);
            b->setIcon(ButtonIcon);
            b->setIconSize(pixmap.rect().size());
            b->setGeometry(100,100,pixmap.rect().size().width(),pixmap.rect().size().height());
            scenes[name]->addWidget(b);
        }
    }
    QGraphicsScene * scene = scenes[name];
    // Both need to fade
    window->LoadScene(scene);
    window->PlayMusic(name);
}

void LocationUI::ActionPerformed()
{
    window->SetActionLabelText(July5::GetInstance().GetLastActionText());
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
