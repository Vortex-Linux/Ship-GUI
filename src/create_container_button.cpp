#include "create_container_button.h"

createContainerButton::createContainerButton(QWidget *parent) : QWidget(parent), ui(new Ui::createContainerButton) {
    ui->setupUi(this);
}

createContainerButton::~createContainerButton() {
    delete ui;
}
