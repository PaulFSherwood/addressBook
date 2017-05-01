#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(AddressBookController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    Q_ASSERT(controller != nullptr);
    ui->setupUi(this);

    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createEntry()
{
    auto entry = m_controller->createEntry();
    if(entry){
        ui->listWidget->addItem(entry->name());
        auto listItem = ui->listWidget->item(ui->listWidget->count() - 1);
        m_entryMap.insert(listItem, entry);
    }
}

void MainWindow::deleteEntry()
{
    // find currently selected entry
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value(listItem);
        if (entry){
            if (m_controller->deleteEntry(entry)) {
                m_entryMap.remove(listItem);
                delete listItem;
            }
        }
    }
}

void MainWindow::editEntry()
{
    // get the entry
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value(listItem);
        if (entry) {
            // switch to other page
            ui->stackedWidget->setCurrentWidget(ui->detailsPage);
            // disable entries
            ui->menuEntries->setEnabled(false);
            ui->nameEdit->setText(entry->name());
            ui->birthdayEdit->setDate(entry->birthday());
            ui->addressEdit->setPlainText(entry->address());
            ui->phoneNumbersEdit->setPlainText(entry->phoneNumbers().join("\n"));
        }
    }
}

void MainWindow::setupConnections()
{
    // connect using older QT methods
    connect(ui->actionAdd, SIGNAL(triggered(bool)),
            this, SLOT(createEntry()) );
    // better way to connect C++11 style
    connect(ui->actionRemove, &QAction::triggered,
            this, &MainWindow::deleteEntry);
    connect(ui->actionEdit, &QAction::triggered,
            this, &MainWindow::editEntry);
}
