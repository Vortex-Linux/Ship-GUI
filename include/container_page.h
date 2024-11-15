#ifndef CONTAINER_PAGE_H
#define CONTAINER_PAGE_H

#include <QWidget>
#include <QMenu>
#include "ui_container_page.h"

class ContainerPage : public QWidget {
    Q_OBJECT

public:
    explicit ContainerPage(QWidget *parent = nullptr);
    ~ContainerPage();

private slots:
    void startVM(); 
    void stopVM();  

private:
    Ui::ContainerPage *ui;
    void createMenu(); 
    QMenu *menu;
};

#endif 

