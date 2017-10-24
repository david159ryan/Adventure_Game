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

void Location::RemoveObject(Object o)
{

}

Object * Location::GetObjectAt(int i)
{
    return objects_.at(i);
}

int Location::GetObjectNum()
{
    return objects_.size();
}

Object * Location::GetObject(string name)
{
    for(unsigned long i = 0; i < objects_.size(); i++)
    {
        if (objects_.at(i)->GetName() == name)
        {
            return (objects_.at(i));
        }
    }
    return nullptr;
}

string Location::GetName()
{
    return name_;
}
