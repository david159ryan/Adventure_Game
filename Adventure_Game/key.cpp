#include "key.h"
#include "door.h"
#include "july5.h"

Key::Key(string name) : InventoryObject(name)
{
}

void Key::Interact(Verb verb, Object * target)
{
    switch(verb)
    {
    case USE:
        Use(target);
        break;
    default:
        InventoryObject::Interact(verb, target);
        break;
    }

}

void Key::Use(Object * target)
{
    Door* door = dynamic_cast<Door*>(target);
    string text;
    if (door) {
        if(door->Unlock(this))
        {
            text = "The " + this->GetName() + " unlocks the " + door->GetName() + ".";
        }
        else
        {
            text = "The " + this->GetName() + " doesn't work on the " + door->GetName() + ".";
        }
    }
    else
    {
        InventoryObject::Interact(USE, target);
    }
    July5::GetInstance().SetLastActionText(text);
}
