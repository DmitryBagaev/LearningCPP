#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getConnectionWithButtons()
{
    QObject::connect( ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::getUsernameAndPassword);
}

void MainWindow::getUsernameAndPassword()
{
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    emit haveData(this);
}

