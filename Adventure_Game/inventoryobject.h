#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include "object.h"


class InventoryObject : public Object
{
public:
    InventoryObject(int id, string name, July5 *game);
    string PickUp() override;
};

#endif // INVENTORYOBJECT_H
