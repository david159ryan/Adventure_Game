#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include "object.h"


class InventoryObject : public Object
{
public:
    InventoryObject();
    string PickUp();
};

#endif // INVENTORYOBJECT_H
