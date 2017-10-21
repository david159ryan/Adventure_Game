#include "eventmanager.h"

using namespace std;

map<string, list<Updateable*>> events;

EventManager::EventManager()
{

}

void EventManager::RegisterListener(string eventName, Updateable * updateable)
{
    if(events.find(eventName) == events.end())
    {
        list<Updateable*> newList;
        events[eventName] = newList;
    }
    events[eventName].push_back(updateable);
}

void EventManager::FireEvent(string eventName)
{
    if(events.find(eventName) != events.end())
    {
        for(list<Updateable*>::iterator list_iter = events[eventName].begin();
            list_iter != events[eventName].end(); list_iter++)
        {
            (*list_iter)->Update();
        }
    }
}
