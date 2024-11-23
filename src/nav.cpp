#include "nav.h"

Nav::Nav(QWidget *parent) : QWidget(parent), ui(new Ui::Nav) {
    ui->setupUi(this);

    ui->container_button->setProperty("active", true);
    ui->vm_button->setProperty("active", false);

    ui->container_button->style()->polish(ui->container_button);
    ui->vm_button->style()->polish(ui->vm_button);

    connect(ui->container_button, &QPushButton::clicked, [=]() {
        ui->container_button->setProperty("active", true);
        ui->vm_button->setProperty("active", false);
        ui->container_button->style()->polish(ui->container_button);
        ui->vm_button->style()->polish(ui->vm_button);
        emit buttonClicked("containers");
    });

    connect(ui->vm_button, &QPushButton::clicked, [=]() {
        ui->container_button->setProperty("active", false);
        ui->vm_button->setProperty("active", true);
        ui->container_button->style()->polish(ui->container_button);
        ui->vm_button->style()->polish(ui->vm_button);
        emit buttonClicked("virtual_machines");
    });
}

Nav::~Nav() {
    delete ui;
}

