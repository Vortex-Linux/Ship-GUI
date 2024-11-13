#include <QApplication>
#include <QFile>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "../include/nav.h"  
#include "../include/container_page.h"  
#include "../include/vm_page.h"  

void loadAppStyleSheet(QApplication &app, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    } else {
        qWarning("Could not open stylesheet file: %s", qPrintable(file.errorString()));
    }
}

void loadWidgetStyleSheet(QWidget *widget, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        widget->setStyleSheet(styleSheet);
    } else {
        qWarning("Could not open stylesheet file: %s", qPrintable(file.errorString()));
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    QWidget mainWindow;

    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);

    Nav *nav = new Nav(); 
    ContainerPage *container_page = new ContainerPage();
    VMPage *vm_page = new VMPage();

    loadWidgetStyleSheet(nav, ":/styles/styles/nav.qss");
    loadWidgetStyleSheet(container_page, ":/styles/styles/container_page.qss");
    loadWidgetStyleSheet(vm_page, ":/styles/styles/vm_page.qss");

    nav->setFixedSize(800, 100);  
    container_page->setFixedSize(800, 100);  
    vm_page->setFixedSize(800, 100);  

    layout->addWidget(nav);  
    layout->addWidget(container_page);  
    layout->addWidget(vm_page);  

    mainWindow.setLayout(layout);

    mainWindow.show();

    return app.exec();
}
