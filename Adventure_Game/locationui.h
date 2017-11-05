#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "updateable.h"
#include "mainwindow.h"
#include <string>
#include <QBoxLayout>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <map>
#include <QToolButton>
#include "objectbutton.h"
#include "imageutilities.h"

using namespace std;

class LocationUI : public virtual Updateable
{
public:
    LocationUI(MainWindow * window);
    void Update(Event);
private:
    map<string, QGraphicsScene*> scenes;
    //map<string, list<QGraphicsProxyWidget> items;
    MainWindow * window;
    void LocationChanged();
    void ActionPerformed();
    void ItemPickedUp();
};

#endif // LOCATIONUI_H
