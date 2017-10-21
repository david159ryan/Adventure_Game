#ifndef CLIFRAME_H
#define CLIFRAME_H

#include <QFrame>
#include <QGraphicsPixmapItem>
#include "july5.h"

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QImage;
class QPixmap;
QT_END_NAMESPACE

namespace Ui {
class CliFrame;
}

class CliFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CliFrame(QWidget *parent = 0);
    ~CliFrame();
    void CallUpdate();

public slots:
    void ProcessCommand();

private:
    Ui::CliFrame *ui;
    July5 *game;
    QGraphicsScene * scene;
    QGraphicsEllipseItem * ellipse;
    QGraphicsRectItem * rect;
    QGraphicsPixmapItem * pixmap;
};

#endif // CLIFRAME_H
