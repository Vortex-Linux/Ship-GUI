#include "nav.h"

createVMPage::createVMPage(QWidget *parent) : QWidget(parent), ui(new Ui::createVMPage) {
    ui->setupUi(this);
}

createVMPage::~createVMPage() {
    delete ui;
}
