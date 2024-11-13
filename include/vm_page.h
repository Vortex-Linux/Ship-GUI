#ifndef VM_PAGE_H
#define VM_PAGE_H

#include <QWidget>
#include "ui_vm_page.h"

class VMPage : public QWidget {
    Q_OBJECT

public:
    explicit VMPage(QWidget *parent = nullptr);
    ~VMPage();

private:
    Ui::VMPage *ui;
};

#endif 

