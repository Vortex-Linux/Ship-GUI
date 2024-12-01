#ifndef CREATE_VM_PAGE_H
#define CREATE_VM_PAGE_H

#include "ui_create_vm_page.h"
#include "headers.h"

class createVMPage : public QWidget {
    Q_OBJECT

public:
    explicit createVMPage(QWidget *parent = nullptr);
    ~createVMButton();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::createVMPage *ui;  
};

#endif // CREATE_VM_PAGE_H


