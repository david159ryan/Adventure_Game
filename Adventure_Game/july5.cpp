#include "july5.h"
#include "maploader.h"

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

void July5::FireEvent(Event event)
{
    eventManager.FireEvent(event);
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

void July5::AddToInventory(InventoryObject *o)
{
    playerInventory.AddItem(o);
    FireEvent(ItemPickedUp);
}

list<InventoryObject *> July5::GetItems()
{
    return playerInventory.GetItems();
}

void July5::Start()
{
    MapLoader mp;
    mp.LoadMap("../Adventure_Game/map/map.txt");
}

