#ifndef VM_OPERATIONS_H
#define VM_OPERATIONS_H

#include "headers.h"
#include "utils.h"

std::vector<std::string> list_vm_names();
std::vector<std::string> list_vm_status();
void start_vm(std::string vm_name);
void restartVM(std::string vm_name);
void deleteVM(std::string vm_name);
void viewVM(std::string vm_name);
void pauseVM(std::string vm_name);
void resumeVM(std::string vm_name);
void saveVM(std::string vm_name);
void shutdownVM(std::string vm_name);
void sendVM(std::string vm_name);

#endif 

