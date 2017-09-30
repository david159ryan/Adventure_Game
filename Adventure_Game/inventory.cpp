#include "inventory.h"

Inventory::Inventory()
{

}

void Inventory::AddItem(InventoryObject * o)
{
    items_.push_back(o);
}

void Inventory::RemoveItem(InventoryObject * o)
{
    items_.remove(o);
}

InventoryObject * Inventory::GetItemByID(int ItemID)
{
    list<InventoryObject*>::iterator it;
    for(it=items_.begin();it!=items_.end();it++)
        if((*it)->GetID()==ItemID)
            return (*it);
    return nullptr;
}

string Inventory::ToString()
{
    string result = "";
    list<InventoryObject*>::iterator it;
    for(it=items_.begin();it!=items_.end();it++)
        result += (*it)->GetName() + "\n";
    return result;
}


