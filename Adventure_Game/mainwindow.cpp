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
    ui->centralwidget->setFixedHeight(rec.height());
    ui->centralwidget->setFixedWidth(rec.width());
    ui->graphicsView->setBackgroundBrush(Qt::black);
    setCentralWidget(ui->centralwidget);
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

void MainWindow::SetActionLabelText(string text)
{
    ui->actionLabel->setText(QString::fromStdString(text));
}

void MainWindow::showEvent(QShowEvent *) {
    //ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

QGraphicsView * MainWindow::GetGraphicsView()
{
    return ui->graphicsView;
}

//void MainWindow::ConnectButton(QToolButton * b, Object * o)
//{
//    QObject::connect(b, SIGNAL(clicked()), o, SLOT(Interact()));
//}



void MainWindow::on_openButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::OPEN);
}

void MainWindow::on_lickButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::LICK);
}

void MainWindow::on_useButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::USE);
}

void MainWindow::on_pushButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PUSH);
}

void MainWindow::on_closeButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::CLOSE);
}
