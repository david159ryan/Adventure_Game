#include "july5.h"
#include "maploader.h"

July5::July5()
{
    eventManager = EventManager();
    verbManager = VerbManager();
    locationManager = LocationManager();
    playerInventory = Inventory(MAX_INVENTORY);
}

void July5::GoToLocation(string locationName)
{
    KillOrphans();
    locationManager.GoToLocation(locationName);
    eventManager.FireEvent(Event::LocationChanged);
}

void July5::RegisterListener(Event event, Updateable *updateable)
{
    eventManager.RegisterListener(event, updateable);
}

void July5::UnRegisterListener(Event event, Updateable *updateable)
{
    eventManager.RegisterListener(event, updateable);
}

void July5::FireEvent(Event event)
{
    eventManager.FireEvent(event);
}

void July5::Interact(Object *obj)
{
    if (hasActiveItem() )
    {
        activeObject_->Interact(CurrentVerb(), obj);
        activeObject_ = NULL;
        return;
    }

    obj->Interact(CurrentVerb());
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

void July5::SetActiveItem(InventoryObject *obj)
{
    activeObject_ = obj;
}

bool July5::hasActiveItem()
{
    return activeObject_ != NULL;
}

InventoryObject * July5::GetActiveObject()
{
    return activeObject_;
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
    SetLastActionText("<font color=\"yellow\">You got a "+o->GetName()+".<i>");
    FireEvent(Event::ActionPerformed);
    playerInventory.AddItem(o);
    FireEvent(ItemPickedUp);
}

void July5::RemoveFromInventory(InventoryObject *o)
{
    playerInventory.RemoveItem(o);
    orphans_.push_back(o);
    FireEvent(ItemRemoved);
}

list<InventoryObject *> July5::GetItems()
{
    return playerInventory.GetItems();
}

void July5::KillOrphans()
{

    for(list<Object*>::iterator it = orphans_.begin(); it != orphans_.end(); it++)
    {
        delete (*it);
    }
    orphans_.clear();
}

void July5::PlayOneShot(string sound)
{
    audioManager.PlayOneShot(sound);
}

void July5::Start()
{
    MapLoader mp;
    mp.LoadMap("://map/map.txt");
    GoToLocation("menu");
    audioManager.PlayMusic("kitchen");
}

void July5::Restart()
{
    playerInventory.clearLocations();
    locationManager.ClearAllLocations();
    FireEvent(Event::ItemRemoved);
    Start();
}


