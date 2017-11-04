#include "object.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Object::Object(string name)
{
    name_ = name;
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

string Object::GetName()
{
    return name_;
}

int Object::GetX()
{
    return x_;
}

int Object::GetY()
{
    return y_;
}

string Object::GetTexture()
{
    return texture_;
}

void Object::SetName(string name)
{
    name_ = name;
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
void Object::SetX(int x)
{
    x_=x;
}
void Object::SetY(int y)
{
    y_=y;
}
void Object::SetTexture(string tex)
{
    texture_=tex;
}
void Object::setType(string type)
{
    type_ = type;
}
string Object::getType()
{
    return type_;
}


string Object::Interact( Verb verb )
{
    switch (verb) {
    case PUSH:
        return this->Push();
        break;
    case PULL:
        return this->Pull();
        break;
    case PICKUP:
        return this->PickUp();
        break;
    case USE:
        return this->Use();
        break;
    case USETARGET:
        return this->Use();
        break;
    case OPEN:
        return this->Open();
        break;
    case OPENTARGET:
        return this->Open();
        break;
    case CLOSE:
        return this->Close();
        break;
    case LICK:
        return this->Lick();
        break;
    case LOOKAT:
        return this->LookAt();
        break;
    case TALKTO:
        return this->TalkTo();
        break;
    default:
        return this->Use();
        break;
    }
}
