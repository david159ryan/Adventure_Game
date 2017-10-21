#ifndef DOOR_H
#define DOOR_H
#include "object.h"
#include "key.h"

class Door : public Object
{
public:
    Door(int id, string name, July5 *game, int keyID, string locationName);
    void SetKeyID(int keyID);
    string GetLocationName();
    bool Unlock(Key * key);
    string Use() override;

private:
    int lockID_;     //If != 0 then keyID is the ID of the key that unlocks this door
    string locationName_;    //Name of the room this door will take you to
};

#endif // DOOR_H
