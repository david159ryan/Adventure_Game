#include "door.h"

Door::Door(int keyID,int locationID, int id, string name) : Object(id, name)
{
    keyID_ = keyID;
    locationID_ = locationID;
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

int Door::getLocationID()
{
    return locationID_;
}
