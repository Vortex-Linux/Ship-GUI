#include "vm_operations.h"

std::vector<std::string> list_vm_names() {
    std::string list_vm_name_cmd = "ship --vm list | awk 'NR > 2 {print $2}'";
    return list_items(exec(list_vm_name_cmd));
}

std::vector<std::string> list_vm_status() {
    std::string list_vm_status_cmd = "ship --vm list | awk 'NR > 2 {print $3, $4}'";
    return list_items(exec(list_vm_status_cmd));
}

void start_vm(std::string vm_name) {
    std::string start_vm_cmd = "ship --vm start " + vm_name;
    exec(start_vm_cmd);
}

