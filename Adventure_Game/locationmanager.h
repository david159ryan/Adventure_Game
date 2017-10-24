#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include "location.h"
#include "eventmanager.h"
#include <vector>

using namespace std;

class LocationManager
{
private:
    Location * currentLocation_;
    vector<Location> locations_;
public:
    LocationManager();
    void AddLocation(Location location);
    Location * GetCurrentLocation();
    void GoToLocation(string locationName);
};

extern LocationManager locationManager;

#endif // LOCATIONMANAGER_H
