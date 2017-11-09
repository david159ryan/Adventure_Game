#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "mainwindow.h"

#include <QBoxLayout>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QToolButton>

#include <map>
#include <string>

#include "ui/objectbutton.h"
#include "utility/updateable.h"
#include "utility/imageutilities.h"

using namespace std;

class LocationUI : public virtual Updateable
{
public:
    LocationUI(MainWindow * window);
    ~LocationUI();
    void Update(Event);
private:
    map<string, QGraphicsScene*> scenes;
    //map<string, list<QGraphicsProxyWidget> items;
    MainWindow * window;
    void LocationChanged();
    void ActionPerformed();
    void ItemPickedUp();
    void RestartGame();
};

#endif // LOCATIONUI_H
