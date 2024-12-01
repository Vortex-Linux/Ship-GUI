#include "nav.h"

createContainerPage::createContainerPage(QWidget *parent) : QWidget(parent), ui(new Ui::createContainerPage) {
    ui->setupUi(this);
}

createContainerPage::~createContainerPage() {
    delete ui;
}


