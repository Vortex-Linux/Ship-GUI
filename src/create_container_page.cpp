#include "create_container_page.h"

createContainerPage::createContainerPage(QWidget *parent) : QWidget(parent), ui(new Ui::createContainerPage) {
    ui->setupUi(this); 
    connect(ui->backButton, &QPushButton::clicked, [=]() {
        emit buttonClicked("back");
    });

}

createContainerPage::~createContainerPage() {
    delete ui;
}


