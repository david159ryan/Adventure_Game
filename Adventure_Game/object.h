#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <map>
#include "verb.h"

using namespace std;

class Object
{
public:
    Object(string name);
    string GetName();
    void SetName(string name);
    int GetX();
    int GetY();
    string GetTexture();
    void setActionText(string action, string text);
    void SetX(int x);
    void SetY(int y);
    void SetTexture(string tex);

    string getType();
    void setType(string type);
    virtual string Interact(Verb verb);
    virtual string Interact(Verb verb, Object * target);

private:
    map<Verb, string> actionMap_;
    string name_;
    string texture_;
    string type_;
    int x_;
    int y_;
};

#endif // OBJECT_H
