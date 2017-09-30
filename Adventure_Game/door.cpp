#include "door.h"

Door::Door(int id, string name, July5 * game, int lockID,int locationID) :
    Object(id, name, game)
{
    lockID_ = lockID;
    locationID_ = locationID;
    setType("door");
}

void Door::SetKeyID(int keyID)
{
    lockID_ = keyID;
}

int Door::GetLocationID()
{
    return locationID_;
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
        return "The door is firmly locked";

    //next room transition
    return "You walk through the door";
}




