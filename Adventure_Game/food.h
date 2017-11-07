#ifndef FOOD_H
#define FOOD_H
#include "inventoryobject.h"
#include "verb.h"

class Food : public InventoryObject
{
public:
    Food(string name);
    void Interact(Verb verb, Object *target) override;

private:
    void Use();
    void Use(Object * target);
};

#endif
