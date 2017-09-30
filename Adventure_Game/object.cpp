#include "object.h"
#include <stdio.h>

using namespace std;


Object::Object(int id, string name)
{
    name_ = name;
    id_ = id;
    push_ = "I can't push that.";
    pull_ = "Granny wouldn't want me to pull that.";
    pickUp_ = "I can't pick that up. That's Grandma's.";
    use_ = "I don't know what to do with that. Maybe Granny knows.";
    useTarget_ = "I don't think I should use this on the %s.";
    lick_ = "That tastes funny.";
    lookAt_ = "Hmm.. that didn't look that way earlier.";
    talkTo_ = "Hello. Can you hear me? Do you want to be my friend?";
    close_ = "I can't close that.";
    open_ = "It won't open.";
    openTarget_ = "It won't open the %s.";
}

Object::Object(int id)
{
    Object(id, "Invalid Object");
}

string Object::Push()
{
    return push_;
}

string Object::Pull()
{
    return pull_;
}

string Object::PickUp()
{
    return pickUp_;
}

string Object::Use(Object * target)
{
    return useTarget_;
}

string Object::Use()
{
    return use_;
}

string Object::Open()
{
    return open_;
}

string Object::Open(Object *target)
{
    return openTarget_;
}

string Object::Close()
{
    return close_;
}

string Object::Lick()
{
    return lick_;
}

string Object::LookAt()
{
    return lookAt_;
}

string Object::TalkTo()
{
    return talkTo_;
}

string Object::Name() const
{
    return name_;
}

void Object::SetPushString(string newString)
{
    push_ = newString;
}
void Object::SetPullString(string newString)
{
    pull_ = newString;
}
void Object::SetPickUpString(string newString)
{
    pickUp_ = newString;
}
void Object::SetUseTargetString(string newString)
{
    useTarget_ = newString;
}
void Object::SetUseString(string newString)
{
    use_ = newString;
}
void Object::SetOpenString(string newString)
{
    open_ = newString;
}
void Object::SetOpenTargetString(string newString)
{
    openTarget_ = newString;
}
void Object::SetCloseString(string newString)
{
    close_ = newString;
}
void Object::SetLickString(string newString)
{
    lick_ = newString;
}
void Object::SetLookAtString(string newString)
{
    lookAt_ = newString;
}
void Object::SetTalkToString(string newString)
{
    talkTo_ = newString;
}
void Object::setType(string type)
{
    type_ = type;
}
string Object::getType()
{
    return type_;
}
