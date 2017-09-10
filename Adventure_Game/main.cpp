#include "mainwindow.h"
#include <QApplication>
#include <QBoxLayout>
#include "cliframe.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    QHBoxLayout *layout = new QHBoxLayout;
    CliFrame *frame = new CliFrame;
    layout->addWidget(frame);
    frame->show();
    //w.setLayout(layout);
    //w.show();

    return a.exec();
}
