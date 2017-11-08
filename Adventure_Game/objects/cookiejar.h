#ifndef COOKIEJAR_H
#define COOKIEJAR_H

#include "object.h"
#include "game_logic/verb.h"

class CookieJar : public Object
{
public:
    CookieJar(string name);
    void Interact(Verb verb) override;

private:
    void PickUp();
    bool used;
};

#endif // COOKIEJAR_H
