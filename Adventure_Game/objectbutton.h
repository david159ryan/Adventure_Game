#ifndef OBJECTBUTTON_H
#define OBJECTBUTTON_H

#include <QToolButton>
#include <QGraphicsPixmapItem>

#include "object.h"
#include "july5.h"

class ObjectButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ObjectButton(Object *object, QWidget *parent = nullptr);

private:
    Object* object_;

signals:


public slots:
    void Interact();
};

#endif // OBJECTBUTTON_H
