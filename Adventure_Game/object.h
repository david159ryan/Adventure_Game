#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
public:
    Object();
    Object(std::string name);
    std::string Name() const;
    virtual std::string Push();
    virtual std::string Pull();
    virtual std::string PickUp();
    virtual std::string Use(Object target);

private:
    std::string name_;

};

#endif // OBJECT_H
