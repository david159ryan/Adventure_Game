#include "inventory.h"

Inventory::Inventory()
{

}

void Inventory::AddItem(InventoryObject * o)
{
    if(items_.size() < 10)
    {
        items_.push_back(o);
    }
}

void Inventory::RemoveItem(InventoryObject * o)
{
    items_.remove(o);
}

InventoryObject * Inventory::GetItem(string item)
{
    list<InventoryObject*>::iterator it;
    for(it=items_.begin();it!=items_.end();it++)
        if((*it)->GetName()==item)
            return (*it);
    return nullptr;
}

list<InventoryObject *> Inventory::GetItems()
{
    return items_;
}

string Inventory::ToString()
{
    string result = "";
    list<InventoryObject*>::iterator it;
    for(it=items_.begin();it!=items_.end();it++)
        result += (*it)->GetName() + "\n";
    return result;
}


