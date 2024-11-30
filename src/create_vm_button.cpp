#include "create_vm_button.h"

createVMButton::createVMButton(QWidget *parent) : QWidget(parent), ui(new Ui::createVMButton) {
    ui->setupUi(this);
}

createVMButton::~createVMButton() {
    delete ui;
}
