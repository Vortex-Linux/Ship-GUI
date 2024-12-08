#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    QWidget mainWindow;
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    Nav* nav = createNav();
    layout->addWidget(nav); 

    QScrollArea* containerWidget = createContainerWidget();
    QScrollArea* VMWidget = createVMWidget();

    createContainerPage* createContainerPage = create_container_page();
    createVMPage* createVMPage = create_vm_page();

    QStackedWidget* stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(containerWidget);
    stackedWidget->addWidget(VMWidget);
    stackedWidget->addWidget(createContainerPage);
    stackedWidget->addWidget(createVMPage);

    stackedWidget->setCurrentWidget(containerWidget);

    layout->addWidget(stackedWidget); 

    QObject::connect(nav, &Nav::buttonClicked, [=](const QString &buttonName) {
        if (buttonName == "containers") {
            stackedWidget->setCurrentWidget(containerWidget);
        } else if (buttonName == "virtual_machines") {
            stackedWidget->setCurrentWidget(VMWidget);
        }
    });

    QObject::connect(createContainerPage, &createContainerPage::buttonClicked, [=](const QString &buttonName) {
        if (buttonName == "back") {
            stackedWidget->setCurrentWidget(containerWidget);
        } 
    });


    createContainerButton* create_container_button = containerWidget->findChild<createContainerButton*>();
    createVMButton* create_vm_button = VMWidget->findChild<createVMButton*>();

    if (create_container_button) {
        QObject::connect(create_container_button, &createContainerButton::buttonClicked, [=](const QString& buttonName) {
            stackedWidget->setCurrentWidget(createContainerPage);
        });
    }

    if (create_vm_button) {
        QObject::connect(create_vm_button, &createVMButton::buttonClicked, [=](const QString& buttonName) {
            stackedWidget->setCurrentWidget(createVMPage);
        });
    }

    mainWindow.setLayout(layout);
    mainWindow.setFixedSize(800, 800);
    mainWindow.show();

    return app.exec();
}

