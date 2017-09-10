#include "july5.h"

July5::July5()
{

}

std::string July5::processCommand(std::string command)
{
    Object *o = new RustyKnife();
    return o->PickUp();
}

