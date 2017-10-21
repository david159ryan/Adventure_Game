#include "door.h"
#include "locationmanager.h"

Door::Door(int id, string name, July5 * game, int lockID,string locationName) :
    Object(id, name, game)
{
    lockID_ = lockID;
    locationName_ = locationName;
    setType("door");
}

void Door::SetKeyID(int keyID)
{
    lockID_ = keyID;
}

string Door::GetLocationName()
{
    return locationName_;
}

bool Door::Unlock(Key * key)
{
    if(key->GetKeyID()==lockID_)
    {
        lockID_ = 0;
        return true;
    }
    return false;
}

string Door::Use()
{
    if(lockID_ != 0)
    {
        return "The door is firmly locked";
    }
    else
    {
        locationManager.GoToLocation(this->GetLocationName());
        return "You walk through the door";
    }
}




