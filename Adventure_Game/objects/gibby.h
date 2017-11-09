#ifndef GIBBY_H
#define GIBBY_H

#include "objects/object.h"

class Gibby : public Object
{
public:
    Gibby(string name);
    void Interact(Verb verb) override;
    void Pull();
};

#endif // GIBBY_H
