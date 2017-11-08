#ifndef CHICKEN_H
#define CHICKEN_H

#include "inventoryobject.h"
#include "game_logic/verb.h"

class Chicken : public InventoryObject
{
public:
    Chicken(string name);
    void Interact(Verb verb, Object *target) override;

private:
    void Use();
    void Use(Object * target);
};

#endif
