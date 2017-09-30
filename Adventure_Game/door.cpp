#include "door.h"

Door::Door(int lockID,int locID)
{
    lockID_ = lockID;
    locID_ = locID;
    setType("door");
}

void Door::SetKeyID(int keyID)
{
    lockID_ = keyID;
}

int Door::GetRoomID()
{
    return locID_;
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

string Door::GoThroughDoor()
{
    if(lockID_ != 0)
        return "The door is firmly locked";

    //next room transition
    return "You walk through the door";
}




