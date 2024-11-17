#include "vm_operations.h"

std::vector<std::string> list_vms() {
    std::string list_vm_cmd = "ship --vm list | awk 'NR > 2 {print $2}'";
    return list_items(exec(list_vm_cmd));
}

