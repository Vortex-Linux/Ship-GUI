#include "container_operations.h"

std::vector<std::string> list_container_names() {
    std::string list_container_names_cmd = "ship --ctr list | awk 'NR > 1 {print $3}'";
    return list_items(exec(list_container_names_cmd));
}

std::vector<std::string> list_container_status() {
    std::string list_vm_status_cmd = "ship --ctr list | awk 'NR > 1 {print $5}'";
    return list_items(exec(list_vm_status_cmd));
}

std::string list_updated_container_status(std::string container_name) {
    std::string list_container_status_cmd = "ship --ctr list | grep " + container_name + " | awk '{print $5}'";
    return (exec(list_container_status_cmd));
}


void delete_container(std::string container_name) {
    std::string delete_container_cmd = "ship --ctr delete " + container_name;
    exec(delete_container_cmd);
}

void view_container(std::string container_name) {
    std::string view_container_cmd = "ship --ctr view " + container_name;
    run_in_terminal(view_container_cmd);
}

void upgrade_container(std::string container_name) {
    std::string upgrade_container_cmd = "ship --ctr upgrade " + container_name;
    exec(upgrade_container_cmd);
}

void stop_container(std::string container_name) {
    std::string stop_container_cmd = "ship --ctr stop " + container_name;
    exec(stop_container_cmd);
}

void send_container(std::string container_name) {
    std::string send_container_cmd = "ship --ctr send " + container_name;
    exec(send_container_cmd);
}

void create_container(std::string container_name) {
    std::string send_container_cmd = "ship --ctr send " + container_name;
    exec(send_container_cmd);
}

