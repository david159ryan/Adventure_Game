#include "cliframe.h"
#include "ui_cliframe.h"

CliFrame::CliFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CliFrame)
{
    ui->setupUi(this);
    game = new July5;
    QObject::connect(ui->input, SIGNAL(returnPressed()),
                     this, SLOT(processCommand()));
}

void CliFrame::processCommand(){
    QString text = QString(game->processCommand(
                ui->input->text().toStdString()).c_str());
    QListWidgetItem *item = new QListWidgetItem(text);
    ui->terminal->addItem(item);
    ui->terminal->scrollToBottom();
    ui->input->clear();
}

CliFrame::~CliFrame()
{
    delete ui;
}
