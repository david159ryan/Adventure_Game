#include "location.h"

Location::Location(int id, string name)
{
    locID_ = id;
    name_ = name;
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
    for(int i = 0; i < objects_.size(); i++)
    {
        if (objects_.at(i)->Name() == name)
        {
            return objects_.at(i);
        }
    }
}
