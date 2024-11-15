#include "../include/container_page.h"
#include <QMenu>
#include <QAction>
#include <QDebug>

ContainerPage::ContainerPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerPage), menu(new QMenu(this)) {
    ui->setupUi(this);
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

void ContainerPage::createMenu() {
    QAction *startAction = new QAction("Start VM", this);
    QAction *stopAction = new QAction("Stop VM", this);

    connect(startAction, &QAction::triggered, this, &ContainerPage::startVM);
    connect(stopAction, &QAction::triggered, this, &ContainerPage::stopVM);

    menu->addAction(startAction);
    menu->addAction(stopAction);
}

void ContainerPage::startVM() {
    qDebug() << "vm has been started";
}

void ContainerPage::stopVM() {
    qDebug() << "vm has been stopped";
}


ContainerPage::~ContainerPage() {
    delete ui;
}


