#include "cookiejar.h"
#include "key.h"
#include "game_logic/july5.h"
CookieJar::CookieJar(string name) : Object(name)
{
    used = false;
}

void CookieJar::Interact(Verb verb)
{
    if(used)
    {
        Object::Interact(verb);
        return;
    }

    switch(verb)
    {
    case USE:
    case OPEN:
    case PICKUP:
        PickUp();
        break;
    default:
        Object::Interact(verb);
        break;
    }
}

void CookieJar::PickUp()
{
    used = true;
    Key *k = new Key("Living Room Key");
    setActionText("use", "It was a coo-key jar...");
    setActionText("pickup", "It was a coo-key jar...");
    setActionText("open", "It was a coo-key jar...");
    July5::GetInstance().AddToInventory(k);
    July5::GetInstance().SetLastActionText("<font color=\"yellow\">You find a key<i>");
    July5::GetInstance().FireEvent(Event::ActionPerformed);
}
