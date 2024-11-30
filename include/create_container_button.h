#ifndef CREATE_CONTAINER_BUTTON_H
#define CREATE_CONTAINER_BUTTON_H

#include "ui_create_container_button.h"
#include "headers.h"

class createContainerButton : public QWidget {
    Q_OBJECT

public:
    explicit createContainerButton(QWidget *parent = nullptr);
    ~createContainerButton();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::createContainerButton *ui;  
};

#endif // CREATE_CONTAINER_BUTTON_H


