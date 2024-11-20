#include "container_operations.h"

std::vector<std::string> list_containers() {
    std::string list_container_cmd = "ship --ctr list | awk 'NR > 1 {print $3}'";
    return list_items(exec(list_container_cmd));
}
