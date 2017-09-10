#ifndef CLIFRAME_H
#define CLIFRAME_H

#include <QFrame>
#include "july5.h"

namespace Ui {
class CliFrame;
}

class CliFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CliFrame(QWidget *parent = 0);
    ~CliFrame();

public slots:
    void processCommand();

private:
    Ui::CliFrame *ui;
    July5 *game;
};

#endif // CLIFRAME_H
