#ifndef CREATE_CONTAINER_PAGE_H
#define CREATE_CONTAINER_PAGE_H

#include "ui_create_container_page.h"
#include "headers.h"
#include "container_operations.h"

class createContainerPage : public QWidget {
    Q_OBJECT

public:
    explicit createContainerPage(QWidget *parent = nullptr);
    ~createContainerPage();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::createContainerPage *ui;  
};

#endif // CREATE_CONTAINER_PAGE_H

