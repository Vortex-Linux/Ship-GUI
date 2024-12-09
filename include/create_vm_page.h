#ifndef CREATE_VM_PAGE_H
#define CREATE_VM_PAGE_H

#include "ui_create_vm_page.h"
#include "headers.h"
#include <vm_operations.h>

class createVMPage : public QWidget {
    Q_OBJECT

public:
    explicit createVMPage(QWidget *parent = nullptr);
    ~createVMPage();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::createVMPage *ui;  
};

#endif // CREATE_VM_PAGE_H


