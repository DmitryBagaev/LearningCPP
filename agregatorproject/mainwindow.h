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
    Ui::MainWindow *ui;
    QString password;
    QString username;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void getConnectionWithButtons();
    void getUsernameAndPassword();

signals:
    void haveData(QString, QString);
};

#endif
