#ifndef LOCATION_H
#define LOCATION_H

using namespace std;

class Location
{
public:
    Location();
    void AddObject(Object o);
    void RemoveObject(Object o);

private:
    vector<Object> objects_;
};

#endif // LOCATION_H
