#include "mainwin.h"
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);
}

MainWin::~MainWin()
{
    delete ui;
}
