#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <map>
#include "game_logic/verb.h"

using namespace std;

class Object
{
public:
    Object(string name);
    virtual ~Object();
    string GetName();
    void SetName(string name);
    int GetX();
    int GetY();
    string GetTexture();
    void setActionText(string action, string text);
    void SetX(int x);
    void SetY(int y);
    void SetTexture(string tex);
    void SetSound(string sound);
    string GetSound();

    string getType();
    void setType(string type);
    virtual void Interact(Verb verb);
    virtual void Interact(Verb verb, Object * target);

private:
    map<Verb, string> actionMap_;
    string name_;
    string texture_;
    string type_;
    string sound_;
    int x_;
    int y_;
};

#endif // OBJECT_H
