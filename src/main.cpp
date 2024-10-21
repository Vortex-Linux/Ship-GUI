#include <QApplication>
#include <QFile>
#include "../include/nav.h"  

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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    loadAppStyleSheet(app, ":/styles/styles/styles.qss");

    Nav nav; 

    loadWidgetStyleSheet(&nav, ":/styles/styles/nav.qss");
    nav.show();  

    return app.exec();
}

