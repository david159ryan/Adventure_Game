#ifndef KEY_H
#define KEY_H
#include "object.h"

class Key : public Object
{
public:
    Key(string name,int keyID);
    int GetKeyID();
    string Use(Object target);
private:
    int keyID_;
};

#endif // KEY_H
