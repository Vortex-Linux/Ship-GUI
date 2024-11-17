#include "ui_builder.h"

Nav* createNav(QWidget* parent) {
    Nav* nav = new Nav(parent);
    nav->setFixedSize(800, 100);
    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    return nav;
}

QWidget* createContainerWidget(const std::vector<std::string>& containerNames) {
    QWidget* containerWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(containerWidget);

    for (const auto& name : containerNames) {
        ContainerElement* element = new ContainerElement();
        element->setContainerName(QString::fromStdString(name));
        loadWidgetStyleSheet(element, ":/styles/styles/container_element.qss");
        element->setFixedSize(800, 100);
        layout->addWidget(element);
    }

    return containerWidget;
}

VMElement* createVMWidget() {
    VMElement* vmElement = new VMElement();
    loadWidgetStyleSheet(vmElement, ":/styles/styles/vm_element.qss");
    vmElement->setFixedSize(800, 100);
    return vmElement;
}
