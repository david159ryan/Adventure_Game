#ifndef JULY5_H
#define JULY5_H

#include "string"

#include "locationmanager.h"
#include "verbmanager.h"
#include "eventmanager.h"
#include "inventory.h"
#include "key.h"
#include "door.h"
#include "maploader.h"

using namespace std;

class July5
{
public:
    static July5& GetInstance()
    {
        static July5 instance;
        return instance;
    }
    Inventory playerInventory;
    void GoToLocation(string locationName);
    void RegisterListener(Event event, Updateable *updateable);
    void FireEvent(Event event);
    Location * GetCurrentLocation();
    void AddLocation(Location *);

    void SetLastActionText(string text);
    string GetLastActionText();
    Verb CurrentVerb();
    void SetVerb(Verb verb);
    void Start();

private:
    July5();
    July5(July5 const&);            // Don't Implement.
    void operator=(July5 const&);   // Don't implement

    LocationManager locationManager;
    EventManager eventManager;
    VerbManager verbManager;

    string lastActionText_;
};

#endif // JULY5_H
