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

std::string VMElement::getVMName() const {
    return VMNameLabel->text().toStdString();
}

void VMElement::startVM() {
    std::string VMName = getVMName();
    start_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::restartVM() {
    std::string VMName = getVMName();
    start_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::deleteVM() {
    std::string VMName = getVMName();
    restart_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::viewVM() {
    std::string VMName = getVMName();
    view_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::pauseVM() {
    std::string VMName = getVMName();
    pause_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::resumeVM() {
    std::string VMName = getVMName();
    resume_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::saveVM() {
    std::string VMName = getVMName();
    save_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::shutdownVM() {
    std::string VMName = getVMName();
    shutdown_vm(VMName);
    emit VMUpdated(VMName);
}

void VMElement::sendVM() {
    std::string VMName = getVMName();
    send_vm(VMName);
    emit VMUpdated(VMName);
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
