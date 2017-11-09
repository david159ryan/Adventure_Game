#ifndef INVENTORY_H
#define INVENTORY_H
#include <list>
#include "objects/inventoryobject.h"
using namespace std;


class Inventory
{
public:
    Inventory(){}
    Inventory(int maxSize);
    void AddItem(InventoryObject * o);
    void RemoveItem(InventoryObject * o);
    InventoryObject* GetItem(string item);
    list<InventoryObject *> GetItems();
    void clearLocations();
    string ToString();
    int MaxSize();

private:
    list<InventoryObject *> items_;
    size_t maxSize_;
};



#endif // INVENTORY_H
