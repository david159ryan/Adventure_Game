#ifndef KEY_H
#define KEY_H
#include "inventoryobject.h"

class Key : public InventoryObject
{
public:
    Key(int id, string name, July5 *game, int keyID);
    int GetKeyID();
    string Use(Object *target) override;
private:
    int keyID_;
};

#endif // KEY_H
