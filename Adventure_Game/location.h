#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
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
    Object * GetObjectAt(int i);
    int GetObjectNum();
    Object * GetObject(string name);
    void RemoveObject(Object o);
    void SetName(string name);

private:
    vector<Object*> objects_;
    string name_;
};

#endif // LOCATION_H
