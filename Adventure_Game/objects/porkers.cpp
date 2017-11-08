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
    if (target->GetName()=="cage")
    {
        text = "Eat up snowball...";
        July5::GetInstance().RemoveFromInventory(this);
        Key *k = new Key("Garden Key");
        k->setActionText("lookat","It's a key.");
        k->setActionText("pickup","I already have it.");
        k->setActionText("push","I can't do that.");
        k->setActionText("pull","It's mine now.");
        k->setActionText("lick","It tastes earthy.");
        k->setActionText("open","It won't open.");
        k->setActionText("close","It doesn't close.");
        k->setActionText("talkto","What do you unlock?");
        July5::GetInstance().AddToInventory(k);
        July5::GetInstance().FireEvent(Event::StartTimer);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
}
