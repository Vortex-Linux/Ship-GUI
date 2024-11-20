#ifndef VM_OPERATIONS_H
#define VM_OPERATIONS_H

#include "headers.h"
#include "utils.h"

std::vector<std::string> list_vm_names();
std::vector<std::string> list_vm_status();
void start_vm(std::string vm_name);

#endif 

