#include "key.h"
#include "door.h"

Key::Key(string name) : InventoryObject(name)
{
}

string Key::Interact(Verb verb, Object * target)
{
    Door* door = dynamic_cast<Door*>(target);
    if (door) {
        if(door->Unlock(this))
        {
            return "The " + this->GetName() + " unlocks the " + door->GetName() + ".";
        }
        else
        {
            return "The " + this->GetName() + " doesn't work on the " + door->GetName() + ".";
        }
    }
    else
    {
        return InventoryObject::Interact(verb, target);
    }
}
