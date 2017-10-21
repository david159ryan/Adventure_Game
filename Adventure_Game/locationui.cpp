#include "locationui.h"
#include "iostream"
#include "eventmanager.h"

LocationUI::LocationUI(QString title, QHBoxLayout * layout) :
    Updateable()
{
    frame = new CliFrame;
    frame->setWindowTitle(title);
    layout->addWidget(frame);
    frame->show();

    eventManager.RegisterListener("LocationChange", this);
}

void LocationUI::Update(void)
{
    cout << "location updating to " << locationManager.GetCurrentLocation() << endl;

}
