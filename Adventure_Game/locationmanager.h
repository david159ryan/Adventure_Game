#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include "location.h"

using namespace std;

class LocationManager
{
private:
    int locationsSize_;
    Location * currentLocation_;
    Location ** locations_;
public:
    LocationManager(int locationNum);
    Location * AddLocation(string locName);
    Location * GetCurrentLocation();
    string GoToLocation(int locationId);
};

#endif // LOCATIONMANAGER_H
