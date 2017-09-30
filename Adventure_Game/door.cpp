#include "door.h"

Door::Door(int keyID,int roomID)
{
    keyID_ = keyID;
    roomID_ = roomID;
    setType("door");
}

int Door::getkeyID()
{
    return keyID_;
}

void Door::setKeyID(int keyID)
{
    keyID_ = keyID;
}

int Door::getRoomID()
{
    return roomID_;
}
