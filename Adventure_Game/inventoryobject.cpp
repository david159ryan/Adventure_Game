#include "inventoryobject.h"
#include "july5.h"

InventoryObject::InventoryObject(string name) :
    Object(name)
{

}

void InventoryObject::Interact(Verb verb)
{
    switch(verb)
    {
    case PICKUP:
        July5::GetInstance().AddToInventory(this);
        break;
    default:
        Object::Interact(verb);
        break;
    }
}

void InventoryObject::Interact(Verb verb, Object * target)
{
    Object::Interact(verb, target);
}


