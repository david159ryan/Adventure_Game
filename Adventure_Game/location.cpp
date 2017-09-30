#include "location.h"

Location::Location(int id)
{
    locID_ = id;
}

void Location::AddObject(Object o)
{
    objects_.push_back(o);
}

void Location::RemoveObject(Object o)
{

}
