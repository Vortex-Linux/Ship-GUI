#ifndef CONTAINER_ELEMENT_H
#define CONTAINER_ELEMENT_H

#include "ui_container_element.h"
#include "headers.h"

class ContainerElement : public QWidget {
    Q_OBJECT

public:
    explicit ContainerElement(QWidget *parent = nullptr);
    void setContainerName(const QString &name);
    ~ContainerElement();

private slots:
    void deleteContainer();
    void viewContainer();
    void upgradeContainer();
    void stopContainer();
    void sendContainer();

private:
    Ui::ContainerElement *ui;
    QLabel *containerNameLabel;

    template <typename Func>
    void addActionToMenu(const QString &actionText, Func slot);

    void createMenu(); 
    QMenu *menu;
};

#endif 

