#include "menudoor.h"
#include "door.h"

MenuDoor::MenuDoor(string name, string locationName) : Door(name, locationName)
{

}

void MenuDoor::Interact(Verb v)
{
    switch(v)
    {
    case USE:
    case PUSH:
    case OPEN:
        Door::Use();
        break;
    default:
        Object::Interact(v);
        break;
    }
}
