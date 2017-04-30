#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addressbookcontroller.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AddressBookController *controller, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AddressBookController *m_controller;

};

#endif // MAINWINDOW_H
