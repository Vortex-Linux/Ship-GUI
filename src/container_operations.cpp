#include "container_operations.h"

std::vector<std::string> list_container_names() {
    std::string list_container_names_cmd = "ship --ctr list | awk 'NR > 1 {print $3}'";
    return list_items(exec(list_container_names_cmd));
}

std::vector<std::string> list_container_status() {
    std::string list_vm_status_cmd = "ship --ctr list | awk 'NR > 1 {print $5}'";
    return list_items(exec(list_vm_status_cmd));
}

void delete_container(std::string container_name) {
    std::string start_container_cmd = "ship --ctr delete " + container_name;
    exec(start_container_cmd);
}




