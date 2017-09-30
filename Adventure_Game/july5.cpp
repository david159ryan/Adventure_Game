#include "july5.h"

July5::July5()
{

}

std::string July5::processCommand(std::string command)
{
    Location *myRoom = new Location(1, "Kitchen");
    Object *o = new RustyKnife;
    o->SetPickUpString("You pick up the Rusty Knife");
    myRoom->AddObject(o);
    return myRoom->GetObject("Rusty Knife")->PickUp();
}

