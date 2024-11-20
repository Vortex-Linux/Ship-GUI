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
    QAction *deleteAction = new QAction("Delete Container", this);
    QAction *viewAction = new QAction("View Container", this);
    QAction *upgradeAction = new QAction("Upgrade Container", this);
    QAction *stopAction = new QAction("Stop Container", this);
    QAction *sendAction = new QAction("Send Container", this);

    connect(deleteAction, &QAction::triggered, this, &ContainerElement::deleteContainer);
    connect(viewAction, &QAction::triggered, this, &ContainerElement::viewContainer);
    connect(upgradeAction, &QAction::triggered, this, &ContainerElement::upgradeContainer);
    connect(stopAction, &QAction::triggered, this, &ContainerElement::stopContainer);
    connect(sendAction, &QAction::triggered, this, &ContainerElement::sendContainer);

    menu->addAction(deleteAction);
    menu->addAction(viewAction);
    menu->addAction(upgradeAction);
    menu->addAction(stopAction);
    menu->addAction(sendAction);
}

void ContainerElement::deleteContainer() {
    qDebug() << "Container has been deleted";
}

void ContainerElement::viewContainer() {
    qDebug() << "Container is being viewed";
}

void ContainerElement::upgradeContainer() {
    qDebug() << "Container has been upgraded";
}

void ContainerElement::stopContainer() {
    qDebug() << "Container has been stopped";
}

void ContainerElement::sendContainer() {
    qDebug() << "Container has been sent";
}

void ContainerElement::setContainerName(const QString &name) {
    containerNameLabel->setText(name);  
}

ContainerElement::~ContainerElement() {
    delete ui;
}


