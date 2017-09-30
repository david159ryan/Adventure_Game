#ifndef DOOR_H
#define DOOR_H
#include "object.h"

class Door : public Object
{
public:
    Door(int keyID, int locationID, int id, string name);
    int getkeyID();
    void setKeyID(int keyID);
    int getLocationID();

private:
    int keyID_;     //If != 0 then keyID is the ID of the key that unlocks this door
    int locationID_;    //ID of the room this door will take you to
};

#endif // DOOR_H
