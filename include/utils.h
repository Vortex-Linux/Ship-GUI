#ifndef UTILS_H
#define UTILS_H

#include "headers.h"

void loadAppStyleSheet(QApplication &app, const QString &fileName);
void loadWidgetStyleSheet(QWidget *widget, const QString &fileName);
void system_exec(const std::string& cmd);
std::string exec(const std::string& cmd);
std::vector<std::string> list_items(const std::string& input_text);

#endif 

