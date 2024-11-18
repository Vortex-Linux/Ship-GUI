#include "vm_element.h"

VMElement::VMElement(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMElement) {
    ui->setupUi(this);
    VMNameLabel = this->findChild<QLabel*>("VMNameLabel");
    createMenu(); 

    connect(ui->optionsButton, &QToolButton::clicked, this, [this]() {
        menu->exec(ui->optionsButton->mapToGlobal(QPoint(0, ui->optionsButton->height())));
    });
}

void VMElement::createMenu() {
    QAction *startAction = new QAction("Start VM", this);
    QAction *stopAction = new QAction("Stop VM", this);

    connect(startAction, &QAction::triggered, this, &VMElement::startVM);
    connect(stopAction, &QAction::triggered, this, &VMElement::stopVM);

    menu->addAction(startAction);
    menu->addAction(stopAction);
}

void VMElement::startVM() {
    qDebug() << "vm has been started";
}

void VMElement::stopVM() {
    qDebug() << "vm has been stopped";
}

void VMElement::setVMName(const QString &name) {
    VMNameLabel->setText(name);  
}

VMElement::~VMElement() {
    delete ui;
}
