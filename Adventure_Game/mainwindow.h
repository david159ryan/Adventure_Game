#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QWidget>
#include <QTimer>
#include <QToolButton>
#include <QFrame>
#include <QThread>
#include "game_logic/july5.h"
#include "utility/event.h"
#include "utility/imageutilities.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, Updateable
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LoadScene(QGraphicsScene * scene);
    void showEvent(QShowEvent *event);
    Ui::MainWindow *ui;
    QGraphicsView * GetGraphicsView();
    void SetActionLabelText(string text, int duration = 1000);
    void UnsetInventoryButtonBorders();
    void UnsetActionButtonBorders();

public slots:
    void UpdateTimer();
    void RestartGame();

private slots:
    void fadeInFromBlack();
    void fadeToBlack();
    void on_openButton_clicked();
    void on_lickButton_clicked();
    void on_useButton_clicked();
    void on_pushButton_clicked();
    void on_closeButton_clicked();
    void on_lookAtButton_clicked();
    void on_talkToButton_clicked();
    void on_pickUpButton_clicked();
    void on_pullButton_clicked();
    void on_inventory0_clicked();
    void on_inventory1_clicked();
    void on_inventory2_clicked();
    void on_inventory3_clicked();
    void on_inventory4_clicked();
    void on_inventory5_clicked();
    void on_inventory6_clicked();
    void on_inventory7_clicked();
    void on_inventory8_clicked();
    void on_inventory9_clicked();

private:
    QGraphicsScene *scene;
    void InventoryClicked(size_t index);
    void ItemPickedUp();
    void ItemRemoved();
    void StartTimer();
    void ItemMoved();
    QTimer *timer;
   int currentTime;

public:
   // Updateable interface
    void Update(Event event);
};

#endif // MAINWINDOW_H
