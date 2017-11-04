#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "updateable.h"
#include "mainwindow.h"
#include <string>
#include <QBoxLayout>
#include <QString>
#include <QGraphicsScene>
#include <map>
#include <QToolButton>
#include "objectbutton.h"

using namespace std;

class LocationUI : public virtual Updateable
{
public:
    LocationUI(MainWindow * window);
    void Update(Event);
private:
    map<string, QGraphicsScene*> scenes;
    MainWindow * window;
    void LocationChanged();
    void ActionPerformed();
};

#endif // LOCATIONUI_H
