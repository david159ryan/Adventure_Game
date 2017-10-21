#include "mainwindow.h"
#include <QApplication>
#include <QBoxLayout>
#include "cliframe.h"
#include "eventmanager.h"
#include "locationui.h"

using namespace std;

EventManager eventManager;
LocationManager locationManager;

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(gfx);
    eventManager = EventManager();
    locationManager = LocationManager();

    QApplication a(argc, argv);

    QHBoxLayout *layout = new QHBoxLayout;

    LocationUI *locationUI = new LocationUI("July 5th", layout);

    return a.exec();
}
