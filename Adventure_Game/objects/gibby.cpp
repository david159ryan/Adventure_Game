#include "gibby.h"
#include "game_logic/july5.h"

Gibby::Gibby(string name) : Object(name)
{

}

void Gibby::Interact(Verb verb)
{
    Object::Interact(verb);
    switch (verb)
    {
    case PULL:
        Pull();
        break;
    default:
        break;
    }
}

void Gibby::Pull()
{
    July5::GetInstance().FireEvent(Event::RestartGame);
}
