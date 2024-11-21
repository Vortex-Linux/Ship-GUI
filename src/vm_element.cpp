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
    std::string vmNameStd = vmName.toStdString();  
    start_vm(vmNameStd);
}

void VMElement::restartVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    restart_vm(vmNameStd);
}

void VMElement::deleteVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    delete_vm(vmNameStd);
}

void VMElement::viewVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    view_vm(vmNameStd);
}

void VMElement::pauseVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    pause_vm(vmNameStd);
}

void VMElement::resumeVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    resume_vm(vmNameStd);
}

void VMElement::saveVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    save_vm(vmNameStd);
}

void VMElement::shutdownVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    shutdown_vm(vmNameStd);
}

void VMElement::sendVM() {
    QString vmName = VMNameLabel->text();
    std::string vmNameStd = vmName.toStdString();  
    send_vm(vmNameStd);
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
