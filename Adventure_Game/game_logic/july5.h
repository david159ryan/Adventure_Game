#ifndef JULY5_H
#define JULY5_H

#include "string"

#include "locationmanager.h"
#include "inventory.h"
#include "verbmanager.h"
#include "verb.h"

#include "utility/audiomanager.h"
#include "utility/eventmanager.h"
#include "objects/inventoryobject.h"

using namespace std;

class July5
{
public:
    //https://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104
    static July5& GetInstance()
    {
        static July5 instance;
        return instance;
    }

    static const int MAX_INVENTORY = 10;
    static const int TIMER_START = 5;
    void GoToLocation(string locationName);
    void RegisterListener(Event event, Updateable *updateable);
    void UnRegisterListener(Event event, Updateable *updateable);
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
    void Restart();
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
    InventoryObject * activeObject_;
    list<Object *> orphans_;
};

#endif // JULY5_H
