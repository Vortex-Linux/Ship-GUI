#include "vm_element.h"

VMElement::VMElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMElement) {
    ui->setupUi(this);
}

void VMElement::setVMName(const QString &name) {
    VMNameLabel->setText(name);  
}

VMElement::~VMElement() {
    delete ui;
}
