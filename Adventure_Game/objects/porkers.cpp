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

void Porkers::Use(Object * target)
{
    string text;
    if (target->GetName()=="gargoyle")
    {
        target->setActionText("talkto", "<font size=\"1\" color=\"red\">"
                                        "<i>First sunrise, then sunset.<br>"
                                         "Of two remaining, south is best.<br>"
                                         "Hurry child, for I do fret...<br>"
                                         "The old bird returns to her nest."
                                         "</i></font>");
        target->Interact(TALKTO);
        July5::GetInstance().RemoveFromInventory(this);
        July5::GetInstance().FireEvent(Event::StartTimer);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
}
