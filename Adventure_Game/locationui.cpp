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
    July5::GetInstance().RegisterListener(Event::ItemPickedUp, this);

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
        cout << "making location with " << newLocation->GetObjectNum() << " objects" << endl;

        int oSize = newLocation->GetObjectNum();
        for(int i = 0; i < oSize; i++)
        {
            Object * o = newLocation->GetObjectAt(i);
            cout << "making button " << o->GetName() << endl;
            ObjectButton * b = new ObjectButton(o);
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
    window->SetActionLabelText(July5::GetInstance().GetLastActionText());
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
                    delete qt;
                    qt = NULL;
                    pProxy = NULL;
                }
            }
        }
    }

}
