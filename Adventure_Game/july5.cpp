#include "july5.h"

July5::July5()
{
    eventManager = EventManager();
    verbManager = VerbManager();

    locationManager = LocationManager();
}

void July5::GoToLocation(string locationName)
{
    locationManager.GoToLocation(locationName);
    eventManager.FireEvent(Event::LocationChanged);
}

void July5::RegisterListener(Event event, Updateable *updateable)
{
    eventManager.RegisterListener(event, updateable);
}

Location *July5::GetCurrentLocation()
{
    return locationManager.GetCurrentLocation();
}

void July5::AddLocation(Location * location)
{
    locationManager.AddLocation(location);
}

void July5::SetLastActionText(string text)
{
    lastActionText_ = text;
}

string July5::GetLastActionText()
{
    return lastActionText_;
}

Verb July5::CurrentVerb()
{
    return verbManager.CurrentVerb();
}

void July5::SetVerb(Verb verb)
{
    return verbManager.SetVerb(verb);
}

void July5::Start()
{
    MapLoader mp;
    mp.LoadMap("../Adventure_Game/map/map.txt");
    /*
    Location * newLocation = new Location("kitchen");
    newLocation->AddObject(new Door("door", "hallway"));
    locationManager.AddLocation(newLocation);

    Location * newLocation2 = new Location("hallway");
    newLocation2->AddObject(new Door("door", "kitchen"));
    locationManager.AddLocation(newLocation2);
    GoToLocation(newLocation->GetName());
    */
}

