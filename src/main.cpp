#include <QApplication>
#include <QFile>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "../include/nav.h"  
#include "../include/container_element.h"  
#include "../include/vm_element.h"  
#include "../include/utils.h"  

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    QWidget mainWindow;
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    QStackedWidget *stackedWidget = new QStackedWidget();

    Nav *nav = new Nav();  
    ContainerElement *container_element = new ContainerElement();  
    VMElement *vm_element = new VMElement();  

    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    loadWidgetStyleSheet(container_element, ":/styles/styles/container_element.qss");
    loadWidgetStyleSheet(vm_element, ":/styles/styles/vm_element.qss");

    nav->setFixedSize(800, 100);  
    container_element->setFixedSize(800, 100);  
    vm_element->setFixedSize(800, 100);

    stackedWidget->addWidget(container_element); 
    stackedWidget->addWidget(vm_element);       

    layout->addWidget(nav);       
    layout->addWidget(stackedWidget);  
    mainWindow.setLayout(layout);

    mainWindow.setFixedSize(800, 800);

    QObject::connect(nav, &Nav::buttonClicked, [=](const QString &buttonName) {
        if (buttonName == "containers") {
            stackedWidget->setCurrentWidget(container_element);  
        } else if (buttonName == "virtual_machines") {
            stackedWidget->setCurrentWidget(vm_element);  
        }
    });

    mainWindow.show();

    return app.exec();
}
