#include "basementblock.h"
#include "door.h"
#include "game_logic/july5.h"

BasementBlock::BasementBlock(string name) : Object(name)
{

}
void BasementBlock::Interact(Verb verb)
{
    switch(verb)
    {
        case PULL:
        case PUSH:
            Move();
            break;
        default:
            Object::Interact(verb);
    }
}

void BasementBlock::Move()
{
    SetY(308);
    //July5::GetInstance().FireEvent(Event::ItemMoved);
}
