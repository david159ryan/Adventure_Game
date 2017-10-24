#include "cliframe.h"
#include "ui_cliframe.h"
#include "iostream"

void updateLocationUI();


CliFrame::CliFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CliFrame)
    {
        ui->setupUi(this);
        game = new July5;
        QObject::connect(ui->consoleInput, SIGNAL(returnPressed()),
                         this, SLOT(ProcessCommand()));
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);

//        QBrush redBrush(Qt::red);
//        QBrush blueBrush(Qt::blue);
//        QPen blackPen(Qt::black);
//        blackPen.setWidth(6);

//        ellipse = scene->addEllipse(10,10,100,100,blackPen,redBrush);
//        ellipse->setFlag(QGraphicsItem::ItemIsMovable);

//        QImage image(":/gfx/backgrounds/kitchen.png");
//        pixmap = scene->addPixmap(QPixmap::fromImage(image));

//        ui->graphicsView->setBackgroundBrush(Qt::yellow);
//        ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
//        ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
//        ui->graphicsView->show();
    }

void CliFrame::ProcessCommand()
{
    QString text = QString(game->ProcessCommand(
                ui->consoleInput->text().toStdString()).c_str());
    QListWidgetItem *item = new QListWidgetItem(text);
    ui->terminal->addItem(item);
    ui->terminal->scrollToBottom();
    ui->consoleInput->clear();
}

CliFrame::~CliFrame()
{
    delete ui;
}
