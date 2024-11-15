#include <QApplication>
#include <QFile>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "../include/nav.h"  
#include "../include/container_page.h"  
#include "../include/vm_page.h"  
#include "../include/utils.h"  

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    QWidget mainWindow;
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    QStackedWidget *stackedWidget = new QStackedWidget();

    Nav *nav = new Nav();  
    ContainerPage *container_page = new ContainerPage();  
    VMPage *vm_page = new VMPage();  

    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    loadWidgetStyleSheet(container_page, ":/styles/styles/container_page.qss");
    loadWidgetStyleSheet(vm_page, ":/styles/styles/vm_page.qss");

    nav->setFixedSize(800, 100);  
    container_page->setFixedSize(800, 100);  
    vm_page->setFixedSize(800, 100);

    stackedWidget->addWidget(container_page); 
    stackedWidget->addWidget(vm_page);       

    layout->addWidget(nav);       
    layout->addWidget(stackedWidget);  
    mainWindow.setLayout(layout);

    mainWindow.setFixedSize(800, 800);

    QObject::connect(nav, &Nav::buttonClicked, [=](const QString &buttonName) {
        if (buttonName == "containers") {
            stackedWidget->setCurrentWidget(container_page);  
        } else if (buttonName == "virtual_machines") {
            stackedWidget->setCurrentWidget(vm_page);  
        }
    });

    mainWindow.show();

    return app.exec();
}
