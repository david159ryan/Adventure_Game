#include "locationmanager.h"

LocationManager::LocationManager(int locationNum)
{
    locations_ = new Location * [locationNum];
    locationsSize_ = 0;
}

Location * LocationManager::AddLocation(string locName)
{
    // Need to do error checking to make sure its not past the max size.
    locations_[locationsSize_] = new Location(locationsSize_, locName);
    locationsSize_++;
    return locations_[locationsSize_-1];
}

Location * LocationManager::GetCurrentLocation()
{
    return currentLocation_;
}

string LocationManager::GoToLocation(int locationId)
{
    if (locationId >= locationsSize_)
    {
        return "I don't know where that is.";
    }
    else
    {
        currentLocation_ = locations_[locationId];
        return currentLocation_->GetName(); // Temp
    }
}
