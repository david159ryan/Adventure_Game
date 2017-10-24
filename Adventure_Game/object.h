#ifndef OBJECT_H
#define OBJECT_H

#include "mainwindow.h"
#include <QApplication>
#include <string>

using namespace std;

class Object: public QObject
{
    Q_OBJECT

public:
    Object(QObject *parent) : QObject(parent)
    {}
    Object(string name);
    string GetName();
    void SetName(string name);
    virtual string Push();
    virtual string Pull();
    virtual string PickUp();
    virtual string Use(Object * target);
    virtual string Use();
    virtual string Open();
    virtual string Open(Object * target);
    virtual string Close();
    virtual string Lick();
    virtual string LookAt();
    virtual string TalkTo();

    virtual void SetPushString(string newString);
    virtual void SetPullString(string newString);
    virtual void SetPickUpString(string newString);
    virtual void SetUseTargetString(string newString);
    virtual void SetUseString(string newString);
    virtual void SetOpenString(string newString);
    virtual void SetOpenTargetString(string newString);
    virtual void SetCloseString(string newString);
    virtual void SetLickString(string newString);
    virtual void SetLookAtString(string newString);
    virtual void SetTalkToString(string newString);

    string getType();
    void setType(string type);
    void ConnectButton(QToolButton * b);

public slots:
    void Interact();

private:
    string name_;
    string type_;
    string push_;
    string pull_;
    string pickUp_;
    string use_;
    string useTarget_;
    string lick_;
    string lookAt_;
    string talkTo_;
    string close_;
    string open_;
    string openTarget_;
};

#endif // OBJECT_H
