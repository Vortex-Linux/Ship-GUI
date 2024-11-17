#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    QWidget mainWindow;
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    QStackedWidget *stackedWidget = new QStackedWidget();

    Nav *nav = new Nav();
    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");

    nav->setFixedSize(800, 100);   

    QWidget *containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget); 

    std::vector<std::string> container_names = list_containers();

    for (const auto& name : container_names) {
        ContainerElement* container_element = new ContainerElement();
        container_element->setContainerName(QString::fromStdString(name));

        loadWidgetStyleSheet(container_element, ":/styles/styles/container_element.qss");

        containerLayout->addWidget(container_element);
        
        container_element->setFixedSize(800, 100);  
    }

    VMElement *vm_element = new VMElement();  
    loadWidgetStyleSheet(vm_element, ":/styles/styles/vm_element.qss");

    vm_element->setFixedSize(800, 100);  

    stackedWidget->addWidget(containerWidget);

    stackedWidget->addWidget(vm_element); 

    layout->addWidget(nav);  
    layout->addWidget(stackedWidget);  

    mainWindow.setLayout(layout);

    mainWindow.setFixedSize(800, 800);  

    QObject::connect(nav, &Nav::buttonClicked, [=](const QString &buttonName) {
        if (buttonName == "containers") {
            stackedWidget->setCurrentWidget(containerWidget);  
        } else if (buttonName == "virtual_machines") {
            stackedWidget->setCurrentWidget(vm_element);  
        }
    });

    mainWindow.show();

    return app.exec();
}

