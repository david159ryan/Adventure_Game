#include "objectbutton.h"

ObjectButton::ObjectButton( Object *object, MainWindow *parent) : QToolButton(nullptr)
{
    object_ = object;
    window_ = parent;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(Interact()));
    this->setObjectName(QString::fromStdString(object_->GetName()));
    this->setStyleSheet("QToolButton { background-color: rgba(0,0,0,0) }");
}

void ObjectButton::Interact()
{
    July5::GetInstance().Interact(object_);
    window_->UnsetInventoryButtonBorders();
}
