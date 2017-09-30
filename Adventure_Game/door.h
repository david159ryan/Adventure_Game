#ifndef DOOR_H
#define DOOR_H
#include "object.h"
#include "key.h"

class Door : public Object
{
public:
    Door(int lockID, int locID);
    void SetKeyID(int keyID);
    int GetRoomID();
    bool Unlock(Key * key);

private:
    string GoThroughDoor();

private:
    int lockID_;     //If != 0 then lockID is the ID of the key that unlocks this door
    int locID_;    //ID of the room this door will take you to
};

#endif // DOOR_H
