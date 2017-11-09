#ifndef MENUDOOR_H
#define MENUDOOR_H

#include "door.h"

class MenuDoor : public Door
{
public:
    MenuDoor(string name, string locationName);
    void Interact(Verb v) override;
};

#endif // MENUDOOR_H
