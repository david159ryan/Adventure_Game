#ifndef VERBMANAGER_H
#define VERBMANAGER_H

#include "verb.h"

//https://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104
class VerbManager
{
    public:
        static VerbManager& getInstance()
        {
            static VerbManager instance;
            return instance;
        }

        Verb CurrentVerb();
        void SetVerb(Verb verb);
    private:
        Verb verb_;
        VerbManager() {}
        VerbManager(VerbManager const&);    // Don't Implement.
        void operator=(VerbManager const&); // Don't implement
 };

#endif // VERBMANAGER_H
