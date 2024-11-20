#include "vm_element.h"

VMElement::VMElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMElement), menu(new QMenu(this)) {
    ui->setupUi(this);
    VMNameLabel = this->findChild<QLabel*>("VMNameLabel");
    VMStatusLabel = this->findChild<QLabel*>("VMStatusLabel");
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

template <typename Func>
void VMElement::addActionToMenu(const QString &actionText, Func slot) {
    QAction *action = new QAction(actionText, this);
    connect(action, &QAction::triggered, this, slot);
    menu->addAction(action);
}

void VMElement::createMenu() {
    addActionToMenu("Start VM", &VMElement::startVM);
    addActionToMenu("Restart VM", &VMElement::restartVM);
    addActionToMenu("Delete VM", &VMElement::deleteVM);
    addActionToMenu("View VM", &VMElement::viewVM);
    addActionToMenu("Pause VM", &VMElement::pauseVM);
    addActionToMenu("Resume VM", &VMElement::resumeVM);
    addActionToMenu("Save VM", &VMElement::saveVM);
    addActionToMenu("Shutdown VM", &VMElement::shutdownVM);
    addActionToMenu("Send VM", &VMElement::sendVM);
}

void VMElement::startVM() {
    QString vmName = VMNameLabel->text();
    start_vm(vmName);
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

void VMElement::setVMStatus(const QString &status) {
    VMStatusLabel->setText(status);  
} 

VMElement::~VMElement() {
    delete ui;
}
