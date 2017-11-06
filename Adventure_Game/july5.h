#ifndef JULY5_H
#define JULY5_H

#include "string"

#include "locationmanager.h"
#include "verbmanager.h"
#include "verb.h"
#include "eventmanager.h"
#include "inventory.h"
#include "inventoryobject.h"

using namespace std;

class July5
{
public:
    static July5& GetInstance()
    {
        static July5 instance;
        return instance;
    }

    static const int MAX_INVENTORY = 10;

    void GoToLocation(string locationName);
    void RegisterListener(Event event, Updateable *updateable);
    void FireEvent(Event event);
    void Interact(Object * obj);
    Location * GetCurrentLocation();
    void AddLocation(Location *);

    void SetLastActionText(string text);
    void SetActiveItem(InventoryObject * obj);
    bool hasActiveItem();
    InventoryObject * GetActiveObject();
    string GetLastActionText();
    Verb CurrentVerb();
    void SetVerb(Verb verb);
    void AddToInventory(InventoryObject *o);
    void RemoveFromInventory(InventoryObject *o);
    list<InventoryObject *> GetItems();
    void KillOrphans();
    void Start();

private:
    July5();
    July5(July5 const&);            // Don't Implement.
    void operator=(July5 const&);   // Don't implement

    Inventory playerInventory;
    LocationManager locationManager;
    EventManager eventManager;
    VerbManager verbManager;

    string lastActionText_;
    InventoryObject * activeObject_;
    list<Object *> orphans_;
};

#endif // JULY5_H
