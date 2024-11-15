#include "../include/vm_element.h"

VMElement::VMElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMElement) {
    ui->setupUi(this);
}

VMElement::~VMElement() {
    delete ui;
}
