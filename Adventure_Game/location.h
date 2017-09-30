#ifndef LOCATION_H
#define LOCATION_H
#include "object.h"
#include <vector>

using namespace std;

class Location
{
public:
    Location(int id, string name);
    void AddObject(Object * o);
    Object * GetObject(string name);
    void RemoveObject(Object * o);

private:
    vector<Object *> objects_;
    int locID_;
    string name_;
};

#endif // LOCATION_H
