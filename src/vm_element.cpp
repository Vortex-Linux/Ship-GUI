#include "vm_element.h"

VMElement::VMElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    VMNameLabel = this->findChild<QLabel*>("VMNameLabel");
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

void VMElement::addActionToMenu(const QString &actionText, const QObject *receiver, const char *slot) {
    QAction *action = new QAction(actionText, this);
    connect(action, &QAction::triggered, receiver, slot);
    menu->addAction(action);
}

void VMElement::createMenu() {
    addActionToMenu("Start VM", this, SLOT(startVM()));
    addActionToMenu("Stop VM", this, SLOT(stopVM()));
}

void VMElement::startVM() {
    qDebug() << "vm has been started";
}

void VMElement::restartVM() {
    qDebug() << "vm has been restarted";
}

void VMElement::deleteVM() {
    qDebug() << "vm has been deleted";
}

void VMElement::viewVM() {
    qDebug() << "vm has been viewed";
}

void VMElement::pauseVM() {
    qDebug() << "vm has been paused";
}

void VMElement::resumeVM() {
    qDebug() << "vm has been resumed";
}

void VMElement::saveVM() {
    qDebug() << "vm has been saved";
}

void VMElement::shutdownVM() {
    qDebug() << "vm has been shutdown";
}

void VMElement::sendVM() {
    qDebug() << "vm has been sent";
}

void VMElement::setVMName(const QString &name) {
    VMNameLabel->setText(name);  
}

VMElement::~VMElement() {
    delete ui;
}
