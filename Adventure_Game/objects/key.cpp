#include "key.h"
#include "door.h"
#include "game_logic/july5.h"

Key::Key(string name) : InventoryObject(name)
{
    SetTexture("key");

}

void Key::Interact(Verb verb, Object *target)
{
    if(verb == USE)
    {
        Use(target);
    }
}

void Key::Use()
{
    return;
}

void Key::Use(Object * target)
{
    Door* door = dynamic_cast<Door*>(target);
    string text;
    if (door) {
        if(door->Unlock(this))
        {
            July5::GetInstance().RemoveFromInventory(this);
            text = "<font color=\"yellow\">The " + this->GetName() + " unlocks the " + door->GetName() + ".</font>";
        }
        else
        {
            text = "The " + this->GetName() + " doesn't work on the " + door->GetName() + ".";
        }
        July5::GetInstance().SetLastActionText(text);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
    July5::GetInstance().FireEvent(Event::ActionPerformed);
}
