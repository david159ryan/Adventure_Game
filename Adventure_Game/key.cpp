#include "key.h"
#include "door.h"

Key::Key(string name, int keyID) : Object(name)
{
    keyID_ = keyID;
    setType("key");
}

int Key::GetKeyID()
{
    return keyID_;
}

string Key::Use(Object target)
{
    if(target.getType()=="door")
        //if(dynamic_cast<Door>(target).Unlock(this))
            return "The door is unlocked now!";
          else
            return "Invalid key!";
}
