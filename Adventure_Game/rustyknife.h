#ifndef RUSTYKNIFE_H
#define RUSTYKNIFE_H

#include "object.h"


class RustyKnife : public Object
{
public:
    RustyKnife();
    std::string PickUp() override;
};

#endif // RUSTYKNIFE_H
