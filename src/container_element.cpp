#include "../include/container_element.h"

ContainerElement::ContainerElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

void ContainerElement::createMenu() {
    QAction *startAction = new QAction("Start VM", this);
    QAction *stopAction = new QAction("Stop VM", this);

    connect(startAction, &QAction::triggered, this, &ContainerElement::startVM);
    connect(stopAction, &QAction::triggered, this, &ContainerElement::stopVM);

    menu->addAction(startAction);
    menu->addAction(stopAction);
}

void ContainerElement::startVM() {
    qDebug() << "vm has been started";
}

void ContainerElement::stopVM() {
    qDebug() << "vm has been stopped";
}


ContainerElement::~ContainerElement() {
    delete ui;
}


