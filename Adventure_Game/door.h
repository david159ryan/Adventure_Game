#ifndef DOOR_H
#define DOOR_H
#include "object.h"

class Door : public Object
{
public:
    Door(int keyID,int roomID);
    int getkeyID();
    void setKeyID(int keyID);
    int getRoomID();

private:
    int keyID_;     //If != 0 then keyID is the ID of the key that unlocks this door
    int roomID_;    //ID of the room this door will take you to
};

#endif // DOOR_H
