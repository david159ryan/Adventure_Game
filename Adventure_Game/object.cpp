#include "object.h"

Object::Object()
{
    name_ = "Unknown Item";
}

Object::Object(std::string name)
{
    name_ = name;
}

std::string Object::Push()
{
    return name_ + " cannot be pushed.";
}

std::string Object::Pull()
{
    return name_ + " cannot be pulled.";
}

std::string Object::PickUp()
{
    return name_ + " cannot be picked up.";
}

std::string Object::Use(Object target)
{
    return "cannot use " + name_ + " on " + target.Name();
}


std::string Object::Name() const
{
    return name_;
}

