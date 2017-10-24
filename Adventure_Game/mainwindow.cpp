#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    QRect rec = QApplication::desktop()->screenGeometry();
    ui->graphicsView->setFixedHeight(rec.height());
    ui->graphicsView->setFixedWidth(rec.width());
    ui->graphicsView->setBackgroundBrush(Qt::black);
    setCentralWidget(ui->graphicsView);
    player = new QMediaPlayer;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadScene(QGraphicsScene * scene)
{
    this->scene = scene;
    ui->graphicsView->setScene(scene);
//    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::PlayMusic(string name)
{
    // TODO: Fade previous music out and fade new music in.
    string path = "qrc:/sfx/music/"+name+".mp3";
    QString pathString = QString::fromLocal8Bit(path.c_str());
    player->setMedia(QUrl(pathString));
    player->play();
}

void MainWindow::showEvent(QShowEvent *) {
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

QGraphicsView * MainWindow::GetGraphicsView()
{
    return ui->graphicsView;
}

void MainWindow::ClickButton()
{
    object->Use();
}

void MainWindow::ConnectButton(QToolButton * b, Object * o)
{
    object = o;
    QObject::connect(b, SIGNAL(clicked()), this, SLOT(ClickButton()));
}

