#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    July5::GetInstance().RegisterListener(Event::InventoryChanged, this);

    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    QRect rec = QApplication::desktop()->screenGeometry();
    ui->centralwidget->setFixedHeight(rec.height());
    ui->centralwidget->setFixedWidth(rec.width());
    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->actionLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->actionLabel->setWindowOpacity(0);
    ui->actionLabel->setVisible(false);
    setCentralWidget(ui->centralwidget);
    player = new QMediaPlayer;
    PlayMusic("kitchen");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadScene(QGraphicsScene * scene)
{

    this->scene = scene;
    ui->graphicsView->setScene(scene);
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
    ui->actionLabel->setVisible(true);

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    eff->setProperty("opacity", 0);
    ui->actionLabel->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(1000);
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::Linear);
    a->start();

    QPropertyAnimation *b = new QPropertyAnimation(eff, "opacity");
    b->setDuration(2000);
    b->setStartValue(1);
    b->setEndValue(0);
    b->setEasingCurve(QEasingCurve::Linear);
    QTimer::singleShot(4000, b, SLOT(start()));

}


void MainWindow::showEvent(QShowEvent *) {
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
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

void MainWindow::on_lookAtButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::LOOKAT);
}

void MainWindow::on_talkToButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::TALKTO);
}

void MainWindow::on_pickUpButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PICKUP);
}

void MainWindow::on_pullButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PULL);
}

void MainWindow::Update(Event event)
{
    if(event == Event::InventoryChanged)
    {
        list<InventoryObject *> inv = July5::GetInstance().GetItems();
        int count = 1;
        list<InventoryObject*>::iterator it;
        for(it = inv.begin(); it != inv.end() ; ++it, ++count)
        {
            string s = "inventory" + to_string(count);
            cout << s << endl;
            QToolButton * qt = ui->playerInventory->findChild<QToolButton *>(QString::fromStdString(s));
            QPixmap pixmap = QPixmap::fromImage(ImageUtilities::GetObjectImageString((*it)->GetTexture()));
            QIcon icon(pixmap);
            qt->setIcon(QIcon(pixmap));
            qt->setIconSize(QSize(qt->size().width() - 10, qt->size().height() - 10));
        }
    }
}
