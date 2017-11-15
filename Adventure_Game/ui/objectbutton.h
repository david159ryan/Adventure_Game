#ifndef OBJECTBUTTON_H
#define OBJECTBUTTON_H

#include <QToolButton>
#include <QGraphicsPixmapItem>

#include "objects/object.h"
#include "game_logic/july5.h"
#include "mainwindow.h"

class ObjectButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ObjectButton(Object *object, MainWindow *parent = nullptr);
    ~ObjectButton();
    Object * getObject();

private:
    Object* object_;
    MainWindow* window_;

signals:


public slots:
    void Interact();
};

#endif // OBJECTBUTTON_H
