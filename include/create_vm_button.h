#ifndef CREATE_VM_BUTTON_H
#define CREATE_VM_BUTTON_H

#include "ui_create_vm_button.h"
#include "headers.h"

class createVMButton : public QWidget {
    Q_OBJECT

public:
    explicit createVMButton(QWidget *parent = nullptr);
    ~createVMButton();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::createVMButton *ui;  
};

#endif // CREATE_VM_BUTTON_H


