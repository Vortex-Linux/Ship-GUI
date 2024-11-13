#include "nav.h"
#include <QPushButton>

Nav::Nav(QWidget *parent) : QWidget(parent), ui(new Ui::Nav) {
    ui->setupUi(this);

    connect(ui->container_button, &QPushButton::clicked, [=]() {
        emit buttonClicked("containers");
    });

    connect(ui->vm_button, &QPushButton::clicked, [=]() {
        emit buttonClicked("virtual_machines");
    });
}

Nav::~Nav() {
    delete ui;
}

