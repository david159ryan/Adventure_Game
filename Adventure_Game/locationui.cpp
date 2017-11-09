#include "locationui.h"
#include "utility/eventmanager.h"

QImage GetBackgroundString(string);
QImage GetObjectImageString(string);

LocationUI::LocationUI(MainWindow * window) :
    Updateable()
{
    this->window = window;
    July5::GetInstance().RegisterListener(Event::LocationChanged, this);
    July5::GetInstance().RegisterListener(Event::ActionPerformed, this);
    July5::GetInstance().RegisterListener(Event::ItemPickedUp, this);
    July5::GetInstance().RegisterListener(Event::RestartGame, this);
}

LocationUI::~LocationUI()
{
    for(map<string, QGraphicsScene*>::iterator it = scenes.begin(); it != scenes.end(); it++)
    {
        delete (*it).second;
    }
    scenes.clear();
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
    case Event::ItemPickedUp:
        ItemPickedUp();
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
        QImage qimage = ImageUtilities::GetBackgroundString(name);
        QPixmap image = QPixmap::fromImage(qimage);
        QGraphicsPixmapItem* pPixmap = scenes[name]->addPixmap(image);
        window->GetGraphicsView()->fitInView(pPixmap);

        //add interactable objects
        list<Object*> objects = newLocation->GetObjects();
        cout << "making location with " << objects.size() << " objects" << endl;

        for(list<Object*>::iterator it = objects.begin(); it != objects.end(); ++it)
        {
            Object * o = (*it);
            cout << "making button " << o->GetName() << endl;
            ObjectButton * b = new ObjectButton(o, window);
            QPixmap pixmap = QPixmap::fromImage(ImageUtilities::GetObjectImageString(o->GetTexture()));
            QIcon ButtonIcon(pixmap);
            b->setIcon(ButtonIcon);
            b->setIconSize(pixmap.rect().size());
            b->setGeometry(o->GetX(),o->GetY(),
                           pixmap.rect().size().width(),pixmap.rect().size().height());
            scenes[name]->addWidget(b);
        }
    }
    QGraphicsScene * scene = scenes[name];
    // Both need to fade
    window->LoadScene(scene);
}

void LocationUI::ActionPerformed()
{
    string text = July5::GetInstance().GetLastActionText();
    if (!text.empty())
    {
        window->SetActionLabelText(text);
    }
}

void LocationUI::ItemPickedUp()
{
    Object *o = July5::GetInstance().GetItems().back();
    QGraphicsScene * current = scenes[July5::GetInstance().GetCurrentLocation()->GetName()];
    QList<QGraphicsItem*> graphicsItemList = current->items();

    foreach(QGraphicsItem* pGraphicsItem, graphicsItemList)
    {
        QGraphicsProxyWidget* pProxy = qgraphicsitem_cast<QGraphicsProxyWidget*>(pGraphicsItem);
        if(pProxy)
        {
            cout << pProxy->widget()->objectName().toStdString() << endl;
            QToolButton* qt = qobject_cast<QToolButton*>(pProxy->widget());
            if(qt)
            {
                if (qt->objectName().toStdString() == o->GetName())
                {
                    current->removeItem(pProxy);
                }
            }
        }
    }
}

void LocationUI::RestartGame()
{
    July5::GetInstance().UnRegisterListener(Event::LocationChanged, this);
    July5::GetInstance().UnRegisterListener(Event::ActionPerformed, this);
    July5::GetInstance().UnRegisterListener(Event::ItemPickedUp, this);
    July5::GetInstance().UnRegisterListener(Event::RestartGame, this);
    delete this;
}
