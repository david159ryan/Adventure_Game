#ifndef KEY_H
#define KEY_H
#include "inventoryobject.h"
#include "verb.h"

class Key : public InventoryObject
{
public:
    Key(string name);
    void Interact(Verb verb, Object *target) override;

private:
    void Use(Object * target);
};

#endif // KEY_H
