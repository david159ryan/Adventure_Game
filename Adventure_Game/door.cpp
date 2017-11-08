#include "door.h"
#include "july5.h"

Door::Door(string name, string keyName,string locationName) :
    Object(name)
{
    keyName_ = keyName;
    locked_ = true;
    locationName_ = locationName;
    setType("door");
}

Door::Door(string name, string locationName) :
    Object(name)
{
    locked_ = false; // No key provided
    locationName_ = locationName;
    setType("door");
}

string Door::GetLocationName()
{
    return locationName_;
}

bool Door::Unlock(Key * key)
{
    if(key->GetName()==keyName_)
    {
        July5::GetInstance().PlayOneShot("unlockDoor");
        locked_ = false;
        return true;
    }
    return false;
}

void Door::Interact(Verb verb)
{
    if(verb == Verb::NONE)
    {
        verb = Verb::USE;
    }

    switch(verb)
    {
    case USE:
    case PUSH:
    case PULL:
    case OPEN:
        Use();
        break;
    default:
        Object::Interact(verb);
        break;
    }

}

void Door::Use()
{
    if(locked_)
    {
        July5::GetInstance().PlayOneShot("lockedDoor");
        July5::GetInstance().SetLastActionText( "The door is firmly locked");
    }
    else
    {
        //July5::GetInstance().PlayOneShot("openDoor");
        July5::GetInstance().GoToLocation(this->GetLocationName());
        July5::GetInstance().SetLastActionText("You walk through the door");
    }
}

void Door::SetLocation(string location)
{
    locationName_ = location;
}

void Door::SetKey(string key)
{
    keyName_ = key;
    locked_ = true;
}



