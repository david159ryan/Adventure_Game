#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include "object.h"


class InventoryObject : public Object
{
public:
    InventoryObject(std::string name);
    std::string PickUp();
};

#endif // INVENTORYOBJECT_H
