#ifndef _vm_OPERATIONS_H
#define _vm_OPERATIONS_H

#include "headers.h"
#include "utils.h"

std::vector<std::string> list_vm_names();
std::vector<std::string> list_vm_status();
std::string list_updated_vm_status(std::string vm_name);
void start_vm(std::string vm_name);
void restart_vm(std::string vm_name);
void delete_vm(std::string vm_name);
void view_vm(std::string vm_name);
void pause_vm(std::string vm_name);
void resume_vm(std::string vm_name);
void save_vm(std::string vm_name);
void shutdown_vm(std::string vm_name);
void send_vm(std::string vm_name);

#endif 

