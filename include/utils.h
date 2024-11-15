#ifndef UTILS_H
#define UTILS_H

#include <QApplication>
#include <QWidget>

void loadAppStyleSheet(QApplication &app, const QString &fileName);
void loadWidgetStyleSheet(QWidget *widget, const QString &fileName);

#endif 

