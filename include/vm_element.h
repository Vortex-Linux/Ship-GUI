#ifndef VM_ELEMENT_H
#define VM_ELEMENT_H

#include "ui_vm_element.h"
#include "headers.h"

class VMElement : public QWidget {
    Q_OBJECT

public:
    explicit VMElement(QWidget *parent = nullptr);
    void setVMName(const QString &name);
    ~VMElement();

private slots:
    void startVM(); 
    void restartVM(); 
    void deleteVM(); 
    void viewVM(); 
    void pauseVM(); 
    void resumeVM(); 
    void saveVM(); 
    void shutdownVM(); 
    void sendVM(); 

private:
    Ui::VMElement *ui;
    QLabel *VMNameLabel;

    template <typename Func>
    void addActionToMenu(const QString &actionText, Func slot);

    void createMenu(); 
    QMenu *menu;
};

#endif 

