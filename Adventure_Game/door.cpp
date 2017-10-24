#include "door.h"
#include "locationmanager.h"

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
        locked_ = true;
        return true;
    }
    return false;
}

string Door::Use()
{
    if(locked_)
    {
        return "The door is firmly locked";
    }
    else
    {
        locationManager.GoToLocation(this->GetLocationName());
        return "You walk through the door";
    }
}




