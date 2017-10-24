#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <map>
#include <string>
#include <iterator>
#include <list>
#include "updateable.h"

using namespace std;

class EventManager
{
private:
    map<string, list<Updateable *> > events;
public:
    EventManager();
    void RegisterListener(string eventName, Updateable * updateable);
    void FireEvent(string eventName);
};

extern EventManager eventManager;

#endif // EVENTMANAGER_H
