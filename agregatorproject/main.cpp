#include "twitter.h"
#include "twitcurl.h"
#include "ui_mainwindow.h"

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication appl(argc, argv);

    MainWindow window;
    window.show();

    Twitter agregator;

    QObject::connect(window.ui->pushButton_3, &QPushButton::clicked, &window, &MainWindow::getUsernameAndPassword);
    QObject::connect(&window, &MainWindow::haveData, &agregator, &Twitter::setPersonalData);

    return appl.exec();
}
