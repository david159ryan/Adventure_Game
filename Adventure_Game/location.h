#ifndef LOCATION_H
#define LOCATION_H
#include "object.h"
#include <vector>

using namespace std;

class Location
{
public:
    Location(int id);
    void AddObject(Object o);
    void RemoveObject(Object o);

private:
    vector<Object> objects_;
    int locID_;
};

#endif // LOCATION_H
