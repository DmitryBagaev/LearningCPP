#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString password;
    QString username;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void getConnectionWithButtons();
    void getUsernameAndPassword();

    //private:
    Ui::MainWindow *ui;

signals:
    void haveData(MainWindow*);
};

#endif
