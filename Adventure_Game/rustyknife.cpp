#include "rustyknife.h"

RustyKnife::RustyKnife() :
    Object("Rusty Knife")
{

}

std::string RustyKnife::PickUp()
{
    return "You picked up the " + Name();
}

