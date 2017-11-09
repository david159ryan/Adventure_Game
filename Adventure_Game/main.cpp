#include "mainwindow.h"
#include <QApplication>
#include <QBoxLayout>
#include "locationui.h"
#include "game_logic/july5.h"

using namespace std;

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(gfx);

    QApplication a(argc, argv);

    QHBoxLayout *layout = new QHBoxLayout;
    MainWindow *window = new MainWindow;
    window->setWindowTitle("July 5th");
    layout->addWidget(window);
    window->setWindowState(Qt::WindowFullScreen);

    new LocationUI(window);
    July5::GetInstance().Start();

    window->show();

    return a.exec();
}
