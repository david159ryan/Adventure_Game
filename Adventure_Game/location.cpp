#include "location.h"

Location::Location()
{
    locID_ = 0;
    name_ = "Invalid Location";
}

Location::Location(int id, string name)
{
    locID_ = id;
    name_ = name;
}

Location::~Location()
{
    // Destroy stuff
}

void Location::AddObject(Object * o)
{
    objects_.push_back(o);
}

void Location::RemoveObject(Object * o)
{

}

Object * Location::GetObject(string name)
{
    for(unsigned long i = 0; i < objects_.size(); i++)
    {
        if (objects_.at(i)->GetName() == name)
        {
            return objects_.at(i);
        }
    }
    return nullptr;
}

int Location::GetID()
{
    return locID_;
}

string Location::GetName()
{
    return name_;
}
