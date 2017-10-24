#ifndef DOOR_H
#define DOOR_H
#include "object.h"
#include "key.h"

class Door : public Object
{
public:
    Door(string name, string keyName, string locationName);
    Door(string name, string locationName);
    string GetLocationName();
    bool Unlock(Key * key);
    string Use();

private:
    string keyName_;     //If != 0 then keyID is the ID of the key that unlocks this door
    string locationName_;    //Name of the room this door will take you to
    bool locked_;
};

#endif // DOOR_H
