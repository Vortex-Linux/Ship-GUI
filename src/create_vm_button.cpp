#include "create_vm_button.h"

createVMButton::createVMButton(QWidget *parent) : QWidget(parent), ui(new Ui::createVMButton) {
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        emit buttonClicked("create_vm"); 
    });

}

createVMButton::~createVMButton() {
    delete ui;
}
