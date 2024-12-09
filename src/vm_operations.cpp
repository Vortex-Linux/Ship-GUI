#include "vm_operations.h"

std::vector<std::string> list_vm_names() {
    std::string list_vm_names_cmd = "ship --vm list | awk 'NR > 2 {print $2}'";
    return list_items(exec(list_vm_names_cmd));
}

std::vector<std::string> list_vm_status() {
    std::string list_vm_status_cmd = "ship --vm list | awk 'NR > 2 {print $3 \"\" $4}'";
    return list_items(exec(list_vm_status_cmd));
}

std::string list_updated_vm_status(std::string vm_name) {
    std::string list_vm_status_cmd = "ship --vm list | grep " + vm_name + " | awk '{print $3 \"\" $4}'";
    return (exec(list_vm_status_cmd));
}

void start_vm(std::string vm_name) {
    std::string start_vm_cmd = "ship --vm start " + vm_name;
    exec(start_vm_cmd);
}

void restart_vm(std::string vm_name) {
    std::string restart_vm_cmd = "echo y | ship --vm restart " + vm_name;
    exec(restart_vm_cmd);
}

void delete_vm(std::string vm_name) {
    std::string delete_vm_cmd = "echo y | ship --vm delete " + vm_name;
    exec(delete_vm_cmd);
}

void view_vm(std::string vm_name) {
    std::string view_vm_cmd = "echo y | ship --vm view " + vm_name;
    exec(view_vm_cmd);
}

void pause_vm(std::string vm_name) {
    std::string pause_vm_cmd = "ship --vm pause " + vm_name;
    exec(pause_vm_cmd);
}

void resume_vm(std::string vm_name) {
    std::string resume_vm_cmd = "ship --vm resume " + vm_name;
    exec(resume_vm_cmd);
}

void save_vm(std::string vm_name) {
    std::string save_vm_cmd = "ship --vm save " + vm_name;
    exec(save_vm_cmd);
}

void shutdown_vm(std::string vm_name) {
    std::string shutdown_vm_cmd = "echo y | ship --vm shutdown " + vm_name;
    exec(shutdown_vm_cmd);
}

void send_vm(std::string vm_name) {
    std::string send_vm_cmd = "ship --vm send " + vm_name;
    exec(send_vm_cmd);
}

void create_vm(std::string vm_type, std::string vm_name) {
    static const std::unordered_map<std::string, std::string> vm_type_to_image = {
        {"", "tails"},
        {"", "whonix"},
        {"", "debian"},
        {"", "ubuntu"},
        {"", "arch"},
        {"", "fedora"},
        {"", "alpine"},
        {"", "centos"},
        {"", "freebsd"},
        {"", "openbsd"},
        {"", "netbsd"},
        {"", "dragonflybsd"},
        {"", "windows"},
    };

    auto it = vm_type_to_image.find(vm_type);
    if (it != vm_type_to_image.end()) {
        const std::string& image = it->second;
        run_in_terminal("ship --vm create --image " + image + " --name " + vm_name);
    }
}
