#ifndef KEY_H
#define KEY_H
#include "inventoryobject.h"

class Key : public InventoryObject
{
public:
    Key(string name);
    string Interact(Verb verb, Object *target) override;
};

#endif // KEY_H
