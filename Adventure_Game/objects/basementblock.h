#ifndef BASEMENTBLOCK_H
#define BASEMENTBLOCK_H

#include "inventoryobject.h"
#include "game_logic/verb.h"

class BasementBlock : public Object
{
public:
    BasementBlock(string name);
    void Interact(Verb verb) override;

private:
    bool moved_;
    void Move();
};

#endif
