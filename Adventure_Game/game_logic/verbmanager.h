#ifndef VERBMANAGER_H
#define VERBMANAGER_H

#include "verb.h"

class VerbManager
{
    public:
        VerbManager();

        Verb CurrentVerb();
        void SetVerb(Verb verb);
    private:
        Verb verb_;

 };

#endif // VERBMANAGER_H
