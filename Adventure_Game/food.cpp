#include "food.h"
#include "door.h"
#include "july5.h"

Food::Food(string name) : InventoryObject(name)
{

}

void Food::Interact(Verb verb, Object *target)
{
    if(verb == USE)
    {
        Use(target);
    }
}

void Food::Use()
{
    return;
}

void Food::Use(Object * target)
{
    string text;
    if (target->GetName()=="cage")
    {
        text = "Eat up snowball...";
        July5::GetInstance().RemoveFromInventory(this);
        Key *k = new Key("Garden Key");
        k->SetTexture("key");
        k->setActionText("lookat","It's a key.");
        k->setActionText("pickup","I already have it.");
        k->setActionText("push","I can't do that.");
        k->setActionText("pull","It's mine now.");
        k->setActionText("lick","It tastes earthy.");
        k->setActionText("open","It won't open.");
        k->setActionText("close","It doesn't close.");
        k->setActionText("talkto","What do you unlock?");
        July5::GetInstance().AddToInventory(k);
        July5::GetInstance().SetLastActionText(text);
    }
    else
    {
        Object::Interact(USETARGET, target);
    }
    July5::GetInstance().FireEvent(Event::ActionPerformed);
}
