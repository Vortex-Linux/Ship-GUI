#include "ui_builder.h"

Nav* createNav(QWidget* parent) {
    Nav* nav = new Nav(parent);
    nav->setFixedSize(800, 100);
    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    return nav;
}

QScrollArea* createContainerWidget() {
    std::vector<std::string> containerNames = list_container_names(); 
    std::vector<std::string> containerStatus = list_container_status(); 

    QWidget* containerWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(containerWidget);

    for (size_t i = 0; i < containerNames.size(); ++i) {
        ContainerElement* element = new ContainerElement();
        element->setContainerName(QString::fromStdString(containerNames[i]));
        element->setContainerStatus(QString::fromStdString(containerStatus[i]));
        loadWidgetStyleSheet(element, ":/styles/styles/container_element.qss");
        element->setFixedSize(750, 100);
        layout->addWidget(element);

        QObject::connect(element, &ContainerElement::containerUpdated, 
            [=](const std::string &containerName) mutable {
                if (containerName == element->getContainerName()) {
                    element->setContainerStatus(QString::fromStdString(list_updated_container_status(containerName)));
                }
            }
        );
    }

    layout->insertStretch(-1, 1);

    containerWidget->setLayout(layout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true); 
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    return scrollArea;
}

QScrollArea* createVMWidget() {
    std::vector<std::string> VMnames = list_vm_names(); 
    std::vector<std::string> VMstatus = list_vm_status(); 

    QWidget* VMWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(VMWidget);

    for (size_t i = 0; i < VMnames.size(); ++i) {
        VMElement* element = new VMElement();
        element->setVMName(QString::fromStdString(VMnames[i]));
        element->setVMStatus(QString::fromStdString(VMstatus[i])); 
        loadWidgetStyleSheet(element, ":/styles/styles/vm_element.qss");
        element->setFixedSize(750, 100);
        layout->addWidget(element);

        QObject::connect(element, &VMElement::VMUpdated, 
            [=](const std::string &VMName) mutable {
                if (VMName == element->getVMName()) {
                    element->setVMStatus(QString::fromStdString(list_updated_vm_status(VMName)));
                }
            }
        );
    }

    layout->insertStretch(-1, 1);

    VMWidget->setLayout(layout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(VMWidget);
    scrollArea->setWidgetResizable(true); 
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    return scrollArea;
}
