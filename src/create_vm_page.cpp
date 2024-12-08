#include "create_vm_page.h"

createVMPage::createVMPage(QWidget *parent) : QWidget(parent), ui(new Ui::createVMPage) {
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, [=]() {
        emit buttonClicked("back");
    });
}

createVMPage::~createVMPage() {
    delete ui;
}
