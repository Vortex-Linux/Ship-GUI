#ifndef CONTAINER_ELEMENT_H
#define CONTAINER_ELEMENT_H

#include "ui_container_element.h"
#include "headers.h"

class ContainerElement : public QWidget {
    Q_OBJECT

public:
    explicit ContainerElement(QWidget *parent = nullptr);
    ~ContainerElement();

private slots:
    void startVM(); 
    void stopVM();  

private:
    Ui::ContainerElement *ui;
    void createMenu(); 
    QMenu *menu;
};

#endif 

