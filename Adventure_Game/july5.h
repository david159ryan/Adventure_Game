#ifndef JULY5_H
#define JULY5_H

#include "string"

#include "locationmanager.h"
#include "audiomanager.h"
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
    void GoToLocation(string locationName);
    void RegisterListener(Event event, Updateable *updateable);
    void FireEvent(Event event);
    Location * GetCurrentLocation();
    void AddLocation(Location *);

    void SetLastActionText(string text);
    string GetLastActionText();
    Verb CurrentVerb();
    void SetVerb(Verb verb);
    void AddToInventory(InventoryObject *o);
    list<InventoryObject *> GetItems();
    void Start();
    void PlayOneShot(string sound);

private:
    July5();
    July5(July5 const&);            // Don't Implement.
    void operator=(July5 const&);   // Don't implement
    Inventory playerInventory;
    LocationManager locationManager;
    AudioManager audioManager;
    EventManager eventManager;
    VerbManager verbManager;

    string lastActionText_;
};

#endif // JULY5_H
