#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include "object.h"


class InventoryObject : public Object
{
public:
    InventoryObject(std::string name);
    void Interact(Verb verb) override;
    void Interact(Verb verb, Object * target) override;

};

#endif // INVENTORYOBJECT_H
