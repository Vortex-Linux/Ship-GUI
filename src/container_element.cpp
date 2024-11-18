#include "container_element.h"

ContainerElement::ContainerElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    containerNameLabel = this->findChild<QLabel*>("containerNameLabel");
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

void ContainerElement::createMenu() {
    QAction *startAction = new QAction("Start Container", this);
    QAction *stopAction = new QAction("Stop Container", this);

    connect(startAction, &QAction::triggered, this, &ContainerElement::startContainer);
    connect(stopAction, &QAction::triggered, this, &ContainerElement::stopContainer);

    menu->addAction(startAction);
    menu->addAction(stopAction);
}

void ContainerElement::startContainer() {
    qDebug() << "Container has been started";
}

void ContainerElement::stopContainer() {
    qDebug() << "Container has been stopped";
}

void ContainerElement::setContainerName(const QString &name) {
    containerNameLabel->setText(name);  
}

ContainerElement::~ContainerElement() {
    delete ui;
}


