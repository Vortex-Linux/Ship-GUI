#include "container_element.h"

ContainerElement::ContainerElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    containerNameLabel = this->findChild<QLabel*>("containerNameLabel");
    containerStatusLabel = this->findChild<QLabel*>("containerStatusLabel");
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

std::string ContainerElement::getContainerName() const {
    return containerNameLabel->text().toStdString();
}

void ContainerElement::deleteContainer() {
    QString containerName = getContainerName();
    delete_container(containerName);
    emit containerUpdated(containerName);
}

void ContainerElement::viewContainer() {
    view_container(getContainerName());
}

void ContainerElement::upgradeContainer() {
    QString containerName = getContainerName();
    upgrade_container(containerName);
    emit containerUpdated(containerName);
}

void ContainerElement::stopContainer() {
    QString containerName = getContainerName();
    stop_container(containerName);
    emit containerUpdated(containerName);
}

void ContainerElement::sendContainer() {
    QString containerName = getContainerName();
    send_container(containerName);
    emit containerUpdated(containerName);
}

void ContainerElement::setContainerName(const QString &name) {
    containerNameLabel->setText(name);  
}

void ContainerElement::setContainerStatus(const QString &status) {
    containerStatusLabel->setText(status);  
}

ContainerElement::~ContainerElement() {
    delete ui;
}


