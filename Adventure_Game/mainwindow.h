#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFile>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LoadScene(QGraphicsScene * scene);
    void showEvent(QShowEvent *event);
    Ui::MainWindow *ui;
    QGraphicsView * GetGraphicsView();
    void PlayMusic(string name);

private:
    QGraphicsScene *scene;
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
};

#endif // MAINWINDOW_H
