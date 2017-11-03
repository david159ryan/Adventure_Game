#include "verbmanager.h"

Verb VerbManager::CurrentVerb()
{
    return verb_;
}

void VerbManager::SetVerb(Verb verb)
{
    verb_ = verb;
}
