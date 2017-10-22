#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "updateable.h"
#include "mainwindow.h"
#include <string>
#include "cliframe.h"
#include <QBoxLayout>
#include <QString>
#include <QGraphicsScene>
#include <map>

using namespace std;

class LocationUI : public virtual Updateable
{
public:
    LocationUI(MainWindow * window);
    void Update(void);
private:
    map<string, QGraphicsScene*> scenes;
    MainWindow * window;
};

#endif // LOCATIONUI_H
