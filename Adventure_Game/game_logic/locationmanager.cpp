#include "locationmanager.h"

LocationManager::LocationManager()
{

}

void LocationManager::AddLocation(Location *location)
{
    locations_.push_back(location);
}

Location * LocationManager::GetCurrentLocation()
{
    return currentLocation_;
}

void LocationManager::GoToLocation(string locationName)
{
    for(vector<Location*>::iterator it = locations_.begin(); it != locations_.end(); ++it) {
        if((*it)->GetName() == locationName )
        {
            currentLocation_ = *it;
            break;
        }
    }
}

void LocationManager::ClearAllLocations()
{
    for(vector<Location*>::iterator it = locations_.begin(); it != locations_.end(); ++it) {
        delete (*it);
    }
    locations_.clear();
}
