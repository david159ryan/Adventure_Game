#ifndef VERBMANAGER_H
#define VERBMANAGER_H

#include "verb.h"

//https://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104
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
