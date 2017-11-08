#include "location.h"

#include "iostream"


Location::Location()
{
    name_ = "Invalid Location";
}

Location::Location(string name)
{
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
    objects_.remove(o);
}

list<Object *> Location::GetObjects() const
{
    return objects_;
}

Object * Location::GetObject(string name)
{
    for(list<Object*>::iterator it = objects_.begin(); it != objects_.end(); ++it)
    {
        if ((*it)->GetName() == name)
        {
            return *it;
        }
    }
    return nullptr;
}

void Location::SetName(string name)
{
    name_ = name;
}

string Location::GetName()
{
    return name_;
}
