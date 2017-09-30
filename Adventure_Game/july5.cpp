#include "july5.h"

July5::July5()
{

}

string July5::ProcessCommand(string command)
{
    Location *myRoom = new Location(1, "Kitchen");
    Object *o = new Object(1, "Rusty Knife", this);
    o->SetPickUpString("You pick up the Rusty Knife");
    myRoom->AddObject(o);
    return myRoom->GetObject("Rusty Knife")->PickUp();
}

