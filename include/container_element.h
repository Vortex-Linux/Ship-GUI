#ifndef CONTAINER_ELEMENT_H
#define CONTAINER_ELEMENT_H

#include <QWidget>
#include <QMenu>
#include "ui_container_element.h"

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

