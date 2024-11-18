#include "ui_builder.h"

Nav* createNav(QWidget* parent) {
    Nav* nav = new Nav(parent);
    nav->setFixedSize(800, 100);
    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    return nav;
}

QScrollArea* createContainerWidget(const std::vector<std::string>& containerNames) {
    QWidget* containerWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(containerWidget);

    for (const auto& name : containerNames) {
        ContainerElement* element = new ContainerElement();
        element->setContainerName(QString::fromStdString(name));
        loadWidgetStyleSheet(element, ":/styles/styles/container_element.qss");
        element->setFixedSize(800, 100);
        layout->addWidget(element);
    }

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    containerWidget->setLayout(layout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true); 
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); 
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    return scrollArea;
}

QScrollArea* createVMWidget(const std::vector<std::string>& VMNames) {
    QWidget* VMWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(VMWidget);

    for (const auto& name : VMNames) {
        VMElement* element = new VMElement();
        element->setVMName(QString::fromStdString(name));
        loadWidgetStyleSheet(element, ":/styles/styles/vm_element.qss");
        element->setFixedSize(800, 100);
        layout->addWidget(element);
    }

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    VMWidget->setLayout(layout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(VMWidget);
    scrollArea->setWidgetResizable(true); 
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); 
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    return scrollArea;
}

