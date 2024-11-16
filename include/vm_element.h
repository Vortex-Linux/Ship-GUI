#ifndef VM_ELEMENT_H
#define VM_ELEMENT_H

#include "ui_vm_element.h"
#include "headers.h"

class VMElement : public QWidget {
    Q_OBJECT

public:
    explicit VMElement(QWidget *parent = nullptr);
    ~VMElement();

private:
    Ui::VMElement *ui;
};

#endif 

