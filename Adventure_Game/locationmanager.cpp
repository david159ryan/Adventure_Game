#include "locationmanager.h"

LocationManager::LocationManager()
{
}

Location * LocationManager::AddLocation(Location location)
{
    locations_.push_back(location);
}

Location * LocationManager::GetCurrentLocation()
{
    return currentLocation_;
}

void LocationManager::GoToLocation(string locationName)
{
    for(vector<Location>::iterator it = locations_.begin(); it != locations_.end(); ++it) {
        if(it->GetName() == locationName )
        {
            currentLocation_ = &*it;
            eventManager.FireEvent("LocationChange");
            break;
        }
    }
}
