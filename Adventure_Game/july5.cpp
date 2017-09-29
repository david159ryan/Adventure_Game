#include "july5.h"

July5::July5()
{

}

std::string July5::processCommand(std::string command)
{
    Object *o = new RustyKnife();
    o->SetPickUpString("You pick up the Rusty Knife");
    return o->PickUp();
}

