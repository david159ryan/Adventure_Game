#ifndef UPDATEABLE_H
#define UPDATEABLE_H

#include "event.h"

class Updateable
{
public:
    Updateable();
    ~Updateable();
    void virtual Update(Event event)=0;
};

#endif // UPDATEABLE_H
