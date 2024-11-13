#include "../include/container_page.h"

ContainerPage::ContainerPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ContainerPage) {
    ui->setupUi(this);
}

ContainerPage::~ContainerPage() {
    delete ui;
}
