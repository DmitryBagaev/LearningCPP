#include "twitter.h"
#include "file.h"
#include "twitcurl.h"
#include "json.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


QT_USE_NAMESPACE

void callme()
{
    qDebug() << "11";
}

int main(int argc, char *argv[])
{
    QApplication appl(argc, argv);

    MainWindow window;
   // window.getConnectionWithButtons();
    window.show();

    Twitter agregator;

    QObject::connect(window.ui->pushButton_3, &QPushButton::clicked, &window, &MainWindow::getUsernameAndPassword);
    QObject::connect(&window, &MainWindow::haveData, &agregator, &Twitter::setPersonalData);
    QObject::connect(&agregator, &Twitter::userDataIsSet, &agregator, &Twitter::authorise);

    return appl.exec();
}
