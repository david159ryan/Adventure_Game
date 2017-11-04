#include "objectbutton.h"

ObjectButton::ObjectButton( Object *object, QWidget *parent) : QToolButton(parent)
{
    object_ = object;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(Interact()));
    this->setObjectName(QString::fromStdString(object_->GetName()));
    this->setStyleSheet("QToolButton { background-color: rgba(0,0,0,0) }");
    this->setToolTip(QString::fromStdString(object_->GetName()));
    this->setToolTipDuration(-1);
}

void ObjectButton::Interact()
{
    Verb v = July5::GetInstance().CurrentVerb();
    object_->Interact(v);
    July5::GetInstance().SetVerb(Verb::NONE);
}
