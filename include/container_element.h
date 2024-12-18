#ifndef CONTAINER_ELEMENT_H
#define CONTAINER_ELEMENT_H

#include "ui_container_element.h"
#include "headers.h"
#include "container_operations.h"

class ContainerElement : public QWidget {
    Q_OBJECT

public:
    explicit ContainerElement(QWidget *parent = nullptr);
    void setContainerName(const QString &name);
    void setContainerStatus(const QString &status);
    std::string getContainerName() const;
    ~ContainerElement();

private slots:
    void deleteContainer();
    void viewContainer();
    void upgradeContainer();
    void stopContainer();
    void sendContainer();

signals:
    void containerUpdated(const std::string &ContainerName); 

private:
    Ui::ContainerElement *ui;
    QLabel *containerNameLabel;
    QLabel *containerStatusLabel;

    template <typename Func>
    void addActionToMenu(const QString &actionText, Func slot);

    void createMenu(); 
    QMenu *menu;
};

#endif 

