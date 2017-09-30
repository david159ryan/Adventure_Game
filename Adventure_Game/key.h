#ifndef KEY_H
#define KEY_H
#include "object.h"

class Key : public Object
{
public:
    Key(int keyID);
    string Use(Object target);
private:
    int keyID_;
};

#endif // KEY_H
