#include "create_container_button.h"

createContainerButton::createContainerButton(QWidget *parent) : QWidget(parent), ui(new Ui::createContainerButton) {
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        emit buttonClicked("create_container"); 
    });
}

createContainerButton::~createContainerButton() {
    delete ui;
}
