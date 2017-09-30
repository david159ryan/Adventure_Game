#include "key.h"
#include "door.h"

Key::Key(int keyID)
{
    keyID_ = keyID;
    setType("key");
}

string Key::Use(Object target)
{
    //if(target.getType()=="door")
        //if(dynamic_cast<Door>(target).getKeyID()==keyID_)
            //dynamic_cast<Door>(target).setKeyID(0);
    return "The door is unlocked now!";
}
