#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <map>
#include <iterator>
#include <list>
#include <iostream>
#include "updateable.h"
#include "event.h"

using namespace std;

class EventManager
{
private:
    map<Event, list<Updateable *> > events;

public:
    EventManager();
    void RegisterListener(Event event, Updateable * updateable);
    void UnRegisterListener(Event event, Updateable * updateable);
    void FireEvent(Event event);
};

#endif // EVENTMANAGER_H
