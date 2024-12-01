#include "ui_builder.h"

Nav* createNav(QWidget* parent) {
    Nav* nav = new Nav(parent);
    nav->setFixedSize(800, 100);
    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    return nav;
}

QScrollArea* createContainerWidget() {
    QWidget* containerMainWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(containerMainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QWidget* containerContentWidget = new QWidget();
    QVBoxLayout* contentLayout = new QVBoxLayout(containerContentWidget);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(10);

    std::vector<std::string> containerNames = list_container_names(); 
    std::vector<std::string> containerStatus = list_container_status(); 

    int maxScrollHeight = 600; 
    
    for (size_t i = 0; i < containerNames.size(); ++i) {
        ContainerElement* element = new ContainerElement();
        element->setContainerName(QString::fromStdString(containerNames[i]));
        element->setContainerStatus(QString::fromStdString(containerStatus[i]));
        loadWidgetStyleSheet(element, ":/styles/styles/container_element.qss");
        element->setFixedSize(750, 100);
        contentLayout->addWidget(element);

        QObject::connect(element, &ContainerElement::containerUpdated, 
            [=](const std::string &containerName) {
                QtConcurrent::run([=]() {
                    QString newStatus = QString::fromStdString(list_updated_container_status(containerName));
                    QMetaObject::invokeMethod(element, [=]() {
                        element->setContainerStatus(newStatus);
                    }, Qt::QueuedConnection);
                });
            }
        );
    }

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(containerContentWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedHeight(maxScrollHeight);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    createContainerButton* create_container_button = new createContainerButton();
    loadWidgetStyleSheet(create_container_button, ":/styles/styles/create_container_button.qss");
    create_container_button->setFixedSize(750, 100);

    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(create_container_button);
    mainLayout->addStretch(1);  

    containerMainWidget->setLayout(mainLayout);

    QScrollArea* finalScrollArea = new QScrollArea();
    finalScrollArea->setWidget(containerMainWidget);
    finalScrollArea->setWidgetResizable(true);
    finalScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    finalScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    return finalScrollArea;
}

QScrollArea* createVMWidget() {
    QWidget* VMMainWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(VMMainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QWidget* VMContentWidget = new QWidget();
    QVBoxLayout* contentLayout = new QVBoxLayout(VMContentWidget);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(10);

    std::vector<std::string> VMnames = list_vm_names(); 
    std::vector<std::string> VMstatus = list_vm_status(); 

    int maxScrollHeight = 600; 
    
    for (size_t i = 0; i < VMnames.size(); ++i) {
        VMElement* element = new VMElement();
        element->setVMName(QString::fromStdString(VMnames[i]));
        element->setVMStatus(QString::fromStdString(VMstatus[i])); 
        loadWidgetStyleSheet(element, ":/styles/styles/vm_element.qss");
        element->setFixedSize(750, 100);
        contentLayout->addWidget(element);

        QObject::connect(element, &VMElement::VMUpdated, 
            [=](const std::string &VMName) {
                QtConcurrent::run([=]() {
                  QString newStatus = QString::fromStdString(list_updated_vm_status(VMName));
                  QMetaObject::invokeMethod(element, [=]() {
                      element->setVMStatus(newStatus);
                  }, Qt::QueuedConnection);
                });
            }
        );
    }

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(VMContentWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedHeight(maxScrollHeight);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    createVMButton* create_vm_button = new createVMButton();
    loadWidgetStyleSheet(create_vm_button, ":/styles/styles/create_vm_button.qss");
    create_vm_button->setFixedSize(750, 100);

    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(create_vm_button);
    mainLayout->addStretch(1);  

    VMMainWidget->setLayout(mainLayout);

    QScrollArea* finalScrollArea = new QScrollArea();
    finalScrollArea->setWidget(VMMainWidget);
    finalScrollArea->setWidgetResizable(true);
    finalScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    finalScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    return finalScrollArea;
}

createContainerPage* createContainerPage() {
    createContainerPage* create_container_page = new createContainerPage();
    create_container_page->setFixedSize(800, 700);
    loadWidgetStyleSheet(nav, ":/styles/styles/createContainerPage.qss");
    return create_container_page;
}

createVMPage* createVMPage() {
    createVMPage* create_vm_page = new createVMPage();
    create_vm_page->setFixedSize(800, 700);
    loadWidgetStyleSheet(nav, ":/styles/styles/createVMPage.qss");
    return create_vm_page;

}


