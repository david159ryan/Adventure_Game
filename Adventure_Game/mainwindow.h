#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QFile>
#include <QTimer>
#include <QToolButton>
#include <QFrame>
#include "july5.h"

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
    void SetActionLabelText(string text);
//    void ConnectButton(QToolButton * b);

private slots:
    void on_openButton_clicked();

    void on_lickButton_clicked();

    void on_useButton_clicked();

    void on_pushButton_clicked();

    void on_closeButton_clicked();

private:
    QGraphicsScene *scene;
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
};

#endif // MAINWINDOW_H
