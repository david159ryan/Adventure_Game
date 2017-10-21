#ifndef JULY5_H
#define JULY5_H

#include "locationmanager.h"
#include "consoleutilities.h"

#include "object.h"
#include "inventory.h"
#include "key.h"
#include "door.h"

using namespace std;

class July5
{
public:
    July5();
    Inventory playerInventory;
    Object ** items;

public:
    string ProcessCommand(string command);

    void TEST_MakeSomeItems();
};

#endif // JULY5_H
