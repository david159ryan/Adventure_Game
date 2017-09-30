#include "july5.h"

July5::July5() :
    locationManager(2)
{
    Location * newLocation;
    newLocation = locationManager.AddLocation("kitchen");
    // use newLocation to add objects to the location
    newLocation = locationManager.AddLocation("hallway");
    locationManager.GoToLocation(1);
}

std::string July5::processCommand(std::string command)
{

    if (locationManager.GetCurrentLocation()->GetID() == 0)
    {
        return locationManager.GoToLocation(1);
    }
    else
    {
        return locationManager.GoToLocation(0);
    }
}

