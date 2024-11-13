#include "../include/vm_page.h"

VMPage::VMPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMPage) {
    ui->setupUi(this);
}

VMPage::~VMPage() {
    delete ui;
}
