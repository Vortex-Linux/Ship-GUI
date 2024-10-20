#include "../include/nav.h"

Nav::Nav(QWidget *parent)
    : QWidget(parent), ui(new Ui::Nav) {
    ui->setupUi(this);  
}

Nav::~Nav() {
    delete ui;  
}

