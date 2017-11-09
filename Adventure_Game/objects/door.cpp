#include "door.h"
#include "game_logic/july5.h"

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
    if(!locked_)
        Use();
    else
        Object::Interact(verb);
}

void Door::Use()
{
    string text;
    if(locked_)
    {
        July5::GetInstance().PlayOneShot("lockedDoor");
        locked_ = "The door is firmly locked";
    }
    else
    {
        July5::GetInstance().GoToLocation(this->GetLocationName());
        text = "<font color=\"yellow\">You walk through the door</font>";
    }
    July5::GetInstance().SetLastActionText(text);
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



