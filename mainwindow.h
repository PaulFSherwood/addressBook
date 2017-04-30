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

public slots:

    void createEntry();

private:
    Ui::MainWindow *ui;
    AddressBookController *m_controller;

    void setupConnections();
};

#endif // MAINWINDOW_H
