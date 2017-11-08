#include "porkers.h"
#include "door.h"
#include "game_logic/july5.h"

Porkers::Porkers(string name) : InventoryObject(name)
{

}

void Porkers::Interact(Verb verb, Object *target)
{
    if(verb == USE)
    {
        Use(target);
    }
}

void Porkers::Use()
{
    return;
}

void Porkers::Use(Object * target)
{
    string text;
    if (target->GetName()=="gargoyle")
    {
        //text = "DAS";
        July5::GetInstance().RemoveFromInventory(this);
        July5::GetInstance().FireEvent(Event::StartTimer);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
}
