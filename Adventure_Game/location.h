#ifndef LOCATION_H
#define LOCATION_H

#include <list>
#include "object.h"

using namespace std;

class Location
{
public:
    Location();
    Location(string name);
    ~Location();
    string GetName();
    void AddObject(Object *o);
    list<Object*> GetObjects() const;
    Object * GetObject(string name);
    void RemoveObject(Object * o);
    void SetName(string name);

private:
    list<Object*> objects_;
    string name_;
};

#endif // LOCATION_H
