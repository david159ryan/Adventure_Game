#include "key.h"
#include "door.h"

Key::Key(int id, string name, int keyID) : Object(id, name)
{
    keyID_ = keyID;
    setType("key");
}

string Key::Use(Object * target)
{

    //if(target.getType()=="door")
        //if(dynamic_cast<Door>(target).getKeyID()==keyID_)
            //dynamic_cast<Door>(target).setKeyID(0);

    // Set the door use string (part of Door.Unlock(KeyID)?)
    //
    return "The door is unlocked now!";
}
