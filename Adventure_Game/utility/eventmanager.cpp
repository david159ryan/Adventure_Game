#include "eventmanager.h"

using namespace std;

EventManager::EventManager()
{

}

void EventManager::RegisterListener(Event event, Updateable * updateable)
{
    if(events.find(event) == events.end())
    {
        events[event] = list<Updateable*>();
    }
    events[event].push_back(updateable);
}

void EventManager::UnRegisterListener(Event event, Updateable * updateable)
{
    if(events.find(event) == events.end())
    {
        list<Updateable*> e = events[event];
        for(list<Updateable*>::iterator it = e.begin(); it != e.end(); ++it)
        {
            if((*it) == updateable)
            {
                e.erase(it);
            }
        }
    }
    events[event].push_back(updateable);
}

void EventManager::FireEvent(Event event)
{
    if(events.find(event) != events.end())
    {
        for(list<Updateable*>::iterator list_iter = events[event].begin();
            list_iter != events[event].end(); list_iter++)
        {
            (*list_iter)->Update(event);
        }
    }
}
