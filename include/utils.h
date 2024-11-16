#ifndef UTILS_H
#define UTILS_H

#include <QApplication>
#include <QWidget>
#include <QFile>
#include <QPushButton>
#include <iostream>
#include <ostream>

void loadAppStyleSheet(QApplication &app, const QString &fileName);
void loadWidgetStyleSheet(QWidget *widget, const QString &fileName);
void system_exec(const std::string& cmd);
std::string exec(const std::string& cmd);

#endif 

