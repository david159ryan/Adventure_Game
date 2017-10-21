#ifndef LOCATION_H
#define LOCATION_H
#include "object.h"
#include <vector>

using namespace std;

class Location
{
public:
    Location();
    Location(string name);
    ~Location();
    string GetName();
    void AddObject(Object * o);
    Object * GetObject(string name);
    void RemoveObject(Object * o);

private:
    vector<Object *> objects_;
    string name_;
};

#endif // LOCATION_H
