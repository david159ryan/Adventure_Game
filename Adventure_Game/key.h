#ifndef KEY_H
#define KEY_H
#include "object.h"

class Key : public Object
{
public:
    Key(int id, string name, July5 *game, int keyID);
    int GetKeyID();
    string Use(Object *target) override;
private:
    int keyID_;
};

#endif // KEY_H
