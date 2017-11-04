#include "object.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Object::Object(string name)
{
    name_ = name;
    actionMap_ = {
        { PUSH , "I can't push that." },
        { PULL , "Granny wouldn't want me to pull that." },
        { PICKUP , "I can't pick that up. That's Grandma's." },
        { USE , "I don't know what to do with that. Maybe Granny knows." },
        { USETARGET , "I don't think I should use this on the ." },
        { LICK , "That tastes funny." },
        { LOOKAT , "Hmm.. that didn't look that way earlier." },
        { TALKTO , "Hello. Can you hear me? Do you want to be my friend?" },
        { CLOSE , "I can't close that." },
        { OPEN , "It won't open." },
        { OPENTARGET , "It won't open the ." }
    };
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

void Object::setActionText(string action, string text)
{
    map<string, Verb>::const_iterator it = VerbMap.find(action);
    if (it != VerbMap.end()){
        actionMap_[it->second] = text;
    }
}

void Object::SetName(string name)
{
    name_ = name;
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
    return actionMap_[verb];
}

string Object::Interact(Verb verb, Object *target)
{
    return actionMap_[verb] + target->GetName();
}
