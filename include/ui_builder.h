#ifndef UI_BUILDER_H
#define UI_BUILDER_H

#include "nav.h"  
#include "container_element.h"  
#include "vm_element.h"  
#include "container_operations.h"
#include "vm_operations.h"

Nav* createNav(QWidget* parent = nullptr);
QWidget* createContainerWidget(const std::vector<std::string>& containerNames);
QWidget* createVMWidget(const std::vector<std::string>& VMNames);

#endif 

