#ifndef INVENTORYOBJECT_H
#define INVENTORYOBJECT_H

#include "object.h"


class InventoryObject : public Object
{
public:
    InventoryObject(std::string name);
    ~InventoryObject();
    void Interact(Verb verb) override;
    virtual void Interact(Verb verb, Object * target)  = 0;

};

#endif // INVENTORYOBJECT_H
