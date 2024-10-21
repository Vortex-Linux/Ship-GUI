#include <QApplication>
#include <QFile>
#include "../include/nav.h"  

void loadStyleSheet(QApplication &app, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
        file.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    loadStyleSheet(app, ":/styles/styles/styles.qss"); 

    Nav nav;  
    nav.show();  

    return app.exec();
}

