#ifndef INVENTORY_H
#define INVENTORY_H
#include<list>
#include "inventoryobject.h"
using namespace std;


class Inventory
{
public:
    Inventory();
    void AddItem(InventoryObject * o);
    void RemoveItem(InventoryObject * o);
    InventoryObject* GetItemByID(int ItemID);
    string ToString();

private:
    list<InventoryObject *> items_;
};



#endif // INVENTORY_H
