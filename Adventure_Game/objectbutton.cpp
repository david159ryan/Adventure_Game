#include "objectbutton.h"

ObjectButton::ObjectButton( Object *object, QWidget *parent) : QToolButton(parent)
{
    object_ = object;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(Interact()));
    this->setObjectName(QString::fromStdString(object_->GetName()));
    this->setStyleSheet("QToolButton { background-color: rgba(0,0,0,0) }");
}

void ObjectButton::Interact()
{
    Verb v = July5::GetInstance().CurrentVerb();
    object_->Interact(v);
    July5::GetInstance().SetVerb(Verb::NONE);
}
