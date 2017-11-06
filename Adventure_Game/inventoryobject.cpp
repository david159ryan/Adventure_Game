#include "inventoryobject.h"
#include "july5.h"

InventoryObject::InventoryObject(string name) :
    Object(name)
{

}

InventoryObject::~InventoryObject()
{

}

void InventoryObject::Interact(Verb verb)
{
    switch(verb)
    {
    case PICKUP:
        July5::GetInstance().AddToInventory(this);
        break;
    case USE:
        July5::GetInstance().SetActiveItem(this);
        break;
    default:
        Object::Interact(verb);
        break;
    }
}
