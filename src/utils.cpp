#include <QApplication>
#include <QFile>
#include <QWidget>
#include <QPushButton>

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

