#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "locationui.h"

#include "iostream"

#include <QFontDatabase>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect rec = QApplication::desktop()->screenGeometry();

    QFontDatabase::addApplicationFont(":/jmh_horror/JMHHORROR-HORROR.ttf");
    ui->frame->setFont(QFont("JMHHORROR-HORROR", 30, QFont::Normal));

    // Register listeners
    July5::GetInstance().RegisterListener(Event::ItemPickedUp, this);
    July5::GetInstance().RegisterListener(Event::ItemRemoved, this);
    July5::GetInstance().RegisterListener(Event::StartTimer, this);
    July5::GetInstance().RegisterListener(Event::RestartGame, this);

    ui->graphicsFrame->setFixedWidth(rec.width());
    ui->graphicsFrame->adjustSize();

    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    ui->actionLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->actionLabel->setWindowOpacity(0);
    ui->actionLabel->setVisible(false);

    ui->fadeToBlack->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    ui->timerLabel->setVisible(false);

    ui->centralwidget->setFixedHeight(rec.height());
    ui->centralwidget->setFixedWidth(rec.width());

    setCentralWidget(ui->centralwidget);
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

void MainWindow::fadeToBlack()
{
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect());

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *b = new QPropertyAnimation(eff, "opacity");
    eff->setProperty("opacity", 1);
    ui->fadeToBlack->setGraphicsEffect(eff);
    b->setDuration(5000);
    b->setStartValue(0);
    b->setEndValue(1);
    b->setEasingCurve(QEasingCurve::Linear);
    QTimer::singleShot(0, b, SLOT(start()));
}

void MainWindow::SetActionLabelText(string text, int duration)
{
    ui->actionLabel->setText(QString::fromStdString(text));
    ui->actionLabel->adjustSize();
    ui->actionLabel->setVisible(true);

    int mY = QCursor::pos().y();
    int mid = ui->graphicsView->size().height()/2;
    int l = ui->actionLabel->pos().y();

    if(mY < mid && l < mid)
    {
        ui->actionLabel->move(ui->actionLabel->pos().x(), l + mid);
    }
    else if(mY > mid && l > mid)
    {
        ui->actionLabel->move(ui->actionLabel->pos().x(), l - mid);
    }

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
    b->setDuration(duration);
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

void MainWindow::Update(Event event)
{

    switch(event)
    {
    case Event::ItemPickedUp:
        ItemPickedUp();
        break;
    case Event::ItemRemoved:
        ItemRemoved();
        break;
    case Event::StartTimer:
        StartTimer();
        break;
    case Event::RestartGame:
        RestartGame();
        break;
    default:
        break;
    }
}

void MainWindow::ItemPickedUp()
{
    list<InventoryObject *> inv = July5::GetInstance().GetItems();
    string s = "inventory" + to_string(inv.size() - 1);
    QToolButton * qt = ui->playerInventory->
            findChild<QToolButton *>(QString::fromStdString(s));
    QPixmap pixmap = QPixmap::fromImage(
                ImageUtilities::GetObjectImageString(inv.back()->GetTexture()));
    qt->setIcon(QIcon(pixmap));
    qt->setIconSize(QSize(qt->size().width() - 10, qt->size().height() - 10));
}

void MainWindow::StartTimer()
{
    currentTime = July5::TIMER_START;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateTimer()));
    timer->start(5000);
    ui->timerLabel->setText("1:00");
    ui->timerLabel->setVisible(true);
}

void MainWindow::UpdateTimer()
{
    currentTime--;
    string text = ((currentTime < 10 ) ? "0:0" : "0:") + to_string(currentTime);
    ui->timerLabel->setText(QString::fromStdString(text));
    if(currentTime == 0)
    {
        timer->stop();
        SetActionLabelText("Granny's home...", 3000);
        fadeToBlack();
        QTimer::singleShot(4000, this, SLOT(GrannyRestart()));
    }
}

void MainWindow::GrannyRestart()
{
    July5::GetInstance().FireEvent(Event::RestartGame);
}

void MainWindow::RestartGame()
{
    timer->stop();
    ui->graphicsView->items().clear();
    ui->timerLabel->setVisible(false);
    new LocationUI(this);
    July5::GetInstance().Restart();
}

void MainWindow::ItemRemoved()
{
    list<InventoryObject *> inv = July5::GetInstance().GetItems();
    string s = "inventory";
    for(int i = 0; i < July5::MAX_INVENTORY; i++)
    {
        QToolButton * qt = ui->playerInventory->
                findChild<QToolButton *>(QString::fromStdString(s + to_string(i)));
        qt->setIcon(QIcon());
    }

    int count = 0;
    for(list<InventoryObject *>::iterator it = inv.begin(); it != inv.end(); ++it, ++count)
    {
        QToolButton * qt = ui->playerInventory->
                findChild<QToolButton *>(QString::fromStdString(s + to_string(count)));
        if((*it) != NULL ) {

            QPixmap pixmap = QPixmap::fromImage(
                        ImageUtilities::GetObjectImageString((*it)->GetTexture()));
            qt->setIcon(QIcon(pixmap));
            qt->setIconSize(QSize(qt->size().width() - 10, qt->size().height() - 10));
        }
    }
}

void MainWindow::InventoryClicked(size_t index)
{
    Verb current = July5::GetInstance().CurrentVerb();
    list<InventoryObject*> items = July5::GetInstance().GetItems();

    if(current == PICKUP || index >= items.size())
    {
        July5::GetInstance().SetVerb(NONE);
        return;
    }

    list<InventoryObject*>::iterator it;
    size_t i = 0;
    for(it = items.begin(); it != items.end() && i < index; ++it, ++i)
        ;
    July5::GetInstance().Interact((*it));
}

void MainWindow::UnsetActionButtonBorders()
{
    ui->openButton->setStyleSheet("");
    ui->useButton->setStyleSheet("");
    ui->lickButton->setStyleSheet("");
    ui->pushButton->setStyleSheet("");
    ui->closeButton->setStyleSheet("");
    ui->lookAtButton->setStyleSheet("");
    ui->pickUpButton->setStyleSheet("");
    ui->pullButton->setStyleSheet("");
    ui->talkToButton->setStyleSheet("");
}

void MainWindow::UnsetInventoryButtonBorders()
{
    ui->inventory0->setStyleSheet("");
    ui->inventory1->setStyleSheet("");
    ui->inventory2->setStyleSheet("");
    ui->inventory3->setStyleSheet("");
    ui->inventory4->setStyleSheet("");
    ui->inventory5->setStyleSheet("");
    ui->inventory6->setStyleSheet("");
    ui->inventory7->setStyleSheet("");
    ui->inventory8->setStyleSheet("");
    ui->inventory9->setStyleSheet("");
}

void MainWindow::on_openButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::OPEN);
    UnsetActionButtonBorders();
    ui->openButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_lickButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::LICK);
    UnsetActionButtonBorders();
    ui->lickButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_useButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::USE);
    UnsetActionButtonBorders();
    ui->useButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_pushButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PUSH);
    UnsetActionButtonBorders();
    ui->pushButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_closeButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::CLOSE);
    UnsetActionButtonBorders();
    ui->closeButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_lookAtButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::LOOKAT);
    UnsetActionButtonBorders();
    ui->lookAtButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_talkToButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::TALKTO);
    UnsetActionButtonBorders();
    ui->talkToButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_pickUpButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PICKUP);
    UnsetActionButtonBorders();
    ui->pickUpButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_pullButton_clicked()
{
    July5::GetInstance().SetVerb(Verb::PULL);
    UnsetActionButtonBorders();
    ui->pullButton->setStyleSheet("border: 2px solid red;");
}

void MainWindow::on_inventory0_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory0->setStyleSheet("border: 2px solid red;");
    InventoryClicked(0);
}

void MainWindow::on_inventory1_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory1->setStyleSheet("border: 2px solid red;");
    InventoryClicked(1);
}

void MainWindow::on_inventory2_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory2->setStyleSheet("border: 2px solid red;");
    InventoryClicked(2);
}

void MainWindow::on_inventory3_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory3->setStyleSheet("border: 2px solid red;");
    InventoryClicked(3);
}

void MainWindow::on_inventory4_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory4->setStyleSheet("border: 2px solid red;");
    InventoryClicked(4);
}

void MainWindow::on_inventory5_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory5->setStyleSheet("border: 2px solid red;");
    InventoryClicked(5);
}

void MainWindow::on_inventory6_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory6->setStyleSheet("border: 2px solid red;");
    InventoryClicked(6);
}

void MainWindow::on_inventory7_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory7->setStyleSheet("border: 2px solid red;");
    InventoryClicked(7);
}

void MainWindow::on_inventory8_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory8->setStyleSheet("border: 2px solid red;");
    InventoryClicked(8);
}

void MainWindow::on_inventory9_clicked()
{
    UnsetInventoryButtonBorders();
    ui->inventory9->setStyleSheet("border: 2px solid red;");
    InventoryClicked(9);
}
