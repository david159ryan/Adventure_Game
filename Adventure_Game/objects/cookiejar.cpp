#include "cookiejar.h"
#include "key.h"
#include "game_logic/july5.h"
CookieJar::CookieJar(string name) : Object(name)
{

}

void CookieJar::Interact(Verb verb)
{
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
    Key *k = new Key("Living Room Key");
    July5::GetInstance().AddToInventory(k);
    July5::GetInstance().FireEvent(Event::ActionPerformed);
}
