#include "container_element.h"

ContainerElement::ContainerElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    containerNameLabel = this->findChild<QLabel*>("containerNameLabel");
    ContainerStatusLabel = this->findChild<QLabel*>("containerStatusLabel");
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

template <typename Func>
void ContainerElement::addActionToMenu(const QString &actionText, Func slot) {
    QAction *action = new QAction(actionText, this);
    connect(action, &QAction::triggered, this, slot);
    menu->addAction(action);
}

void ContainerElement::createMenu() {
    addActionToMenu("Delete Container", &ContainerElement::deleteContainer);
    addActionToMenu("View VM", &ContainerElement::viewContainer);
    addActionToMenu("Upgrade VM", &ContainerElement::upgradeContainer);
    addActionToMenu("Stop VM", &ContainerElement::stopContainer);
    addActionToMenu("Send VM", &ContainerElement::sendContainer);
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

void VMElement::setContainerStatus(const QString &status) {
    VMStatusLabel->setText(status);  
}

ContainerElement::~ContainerElement() {
    delete ui;
}


