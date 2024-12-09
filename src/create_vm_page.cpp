#include "create_vm_page.h"

createVMPage::createVMPage(QWidget *parent) : QWidget(parent), ui(new Ui::createVMPage) {
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, [=]() {
        emit buttonClicked("back");
    });

        QList<QPushButton*> VMButtons = {
        ui->createAlmaButton,
    };

    for (QPushButton* button : VMButtons) {
        connect(button, &QPushButton::clicked, [=]() {
            bool ok;
            QString VMName = QInputDialog::getText(this, 
                tr("Create VM"), 
                tr("Enter VM name for %1:").arg(button->text()),
                QLineEdit::Normal, 
                button->text(), 
                &ok);
            
            if (ok && !VMName.isEmpty()) {
                create_vm(button->text().toStdString(), VMName.toStdString());
            }
        });
    }
}

createVMPage::~createVMPage() {
    delete ui;
}
