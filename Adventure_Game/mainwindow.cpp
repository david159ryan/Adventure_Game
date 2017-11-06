#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    July5::GetInstance().RegisterListener(ItemPickedUp, this);
    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    QRect rec = QApplication::desktop()->screenGeometry();
    ui->centralwidget->setFixedHeight(rec.height());
    ui->centralwidget->setFixedWidth(rec.width());

    // Hackey, disgusting... to get around that layouts aren't updating
    ui->graphicsFrame->setFixedWidth(rec.width());
    ui->graphicsFrame->setFixedHeight(int (rec.height()*(675/float (900))));

    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->actionLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->fadeToBlack->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->actionLabel->setWindowOpacity(0);
    ui->actionLabel->setVisible(false);
    setCentralWidget(ui->centralwidget);

    playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    PlayMusic("kitchen");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadScene(QGraphicsScene * scene)
{
    ui->graphicsView->setFixedSize(ui->graphicsFrame->size());
    this->scene = scene;

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    eff->setProperty("opacity", 0);
    ui->fadeToBlack->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(750);
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::Linear);
    a->start();

    QTimer::singleShot(750, this, SLOT(fadeInFromBlack()));
}

void MainWindow::fadeInFromBlack()
{
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect());

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *b = new QPropertyAnimation(eff, "opacity");
    eff->setProperty("opacity", 0);
    ui->fadeToBlack->setGraphicsEffect(eff);
    b->setDuration(1000);
    b->setStartValue(1);
    b->setEndValue(0);
    b->setEasingCurve(QEasingCurve::Linear);
    b->start();
}

void MainWindow::PlayMusic(string name)
{
    // TODO: Fade previous music out and fade new music in.
    string path = "qrc:/sfx/music/"+name+".mp3";
    QString pathString = QString::fromLocal8Bit(path.c_str());
    playlist->addMedia(QUrl(pathString));
    player->play();
}

void MainWindow::SetActionLabelText(string text)
{
    ui->actionLabel->setText(QString::fromStdString(text));
    ui->actionLabel->adjustSize();
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

    if(event == Event::ItemPickedUp)
    {
        list<InventoryObject *> inv = July5::GetInstance().GetItems();
        string s = "inventory" + to_string(inv.size() - 1);
        cout << s << endl;
        QToolButton * qt = ui->playerInventory->
                findChild<QToolButton *>(QString::fromStdString(s));
        QPixmap pixmap = QPixmap::fromImage(
                    ImageUtilities::GetObjectImageString(inv.back()->GetTexture()));
        QIcon icon(pixmap);
        qt->setIcon(QIcon(pixmap));
        qt->setIconSize(QSize(qt->size().width() - 10, qt->size().height() - 10));


    }
}

void MainWindow::on_inventory0_clicked()
{
    InventoryClicked(0);
}

void MainWindow::on_inventory1_clicked()
{
    InventoryClicked(1);
}

void MainWindow::on_inventory2_clicked()
{
    InventoryClicked(2);
}

void MainWindow::on_inventory3_clicked()
{
    InventoryClicked(3);
}

void MainWindow::on_inventory4_clicked()
{
    InventoryClicked(4);
}

void MainWindow::on_inventory5_clicked()
{
    InventoryClicked(5);
}

void MainWindow::on_inventory6_clicked()
{
    InventoryClicked(6);
}

void MainWindow::on_inventory7_clicked()
{
    InventoryClicked(7);
}

void MainWindow::on_inventory8_clicked()
{
    InventoryClicked(8);
}

void MainWindow::on_inventory9_clicked()
{
    InventoryClicked(9);
}

void MainWindow::InventoryClicked(int index)
{
    Verb current = July5::GetInstance().CurrentVerb();
    list<InventoryObject*> items = July5::GetInstance().GetItems();

    if(current == PICKUP || index >= items.size())
    {
        July5::GetInstance().SetVerb(NONE);
        return;
    }

    list<InventoryObject*>::iterator it;
    int i = 0;
    for(it = items.begin(); it != items.end() && i < index; ++it, ++i)
        ;
    (*it)->Interact(current);
}
