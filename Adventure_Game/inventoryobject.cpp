#include "inventoryobject.h"

InventoryObject::InventoryObject(string name) :
    Object(name)
{

}

string InventoryObject::PickUp()
{
    return "You pick up the " + this->GetName() + ".";
}
