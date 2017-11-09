#ifndef PORKERS_H
#define PORKERS_H

#include "inventoryobject.h"
#include "game_logic/verb.h"

class Porkers : public InventoryObject
{
public:
    Porkers(string name);
    void Interact(Verb verb, Object *target) override;

private:
    void Use();
    void Use(Object * target);
};

#endif
