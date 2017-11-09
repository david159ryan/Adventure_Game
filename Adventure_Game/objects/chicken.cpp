#include "chicken.h"
#include "door.h"
#include "game_logic/july5.h"

Chicken::Chicken(string name) : InventoryObject(name)
{

}

void Chicken::Interact(Verb verb, Object *target)
{
    if(verb == USE)
    {
        Use(target);
    }
}

void Chicken::Use()
{
    return;
}

void Chicken::Use(Object * target)
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
        k->setActionText("talkto","I wonder what you unlock...");
        July5::GetInstance().AddToInventory(k);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
}
