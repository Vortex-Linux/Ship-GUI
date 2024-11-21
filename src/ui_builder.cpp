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

    for (const auto& name : containerNames) {
        loadWidgetStyleSheet(element, ":/styles/styles/container_element.qss");
        element->setFixedSize(750, 100);
        layout->addWidget(element);
    }

    for (size_t i = 0; i < containernNames.size(); ++i) {
        ContainerElement* element = new ContainerElement();
        element->setContainerName(QString::fromStdString(containerNames[i]));
        element->setContainerStatus(QString::fromStdString(containerStatus[i]));
        loadwidgetstylesheet(element, ":/styles/styles/vm_element.qss");
        element->setfixedsize(750, 100);
        layout->addwidget(element);
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
        vmelement* element = new vmelement();
        element->setvmname(qstring::fromstdstring(vmnames[i]));
        element->setvmstatus(qstring::fromstdstring(vmstatus[i])); 
        loadwidgetstylesheet(element, ":/styles/styles/vm_element.qss");
        element->setfixedsize(750, 100);
        layout->addwidget(element);
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

