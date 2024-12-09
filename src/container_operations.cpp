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

void create_container(std::string container_type, std::string container_name) {
    static const std::unordered_map<std::string, std::string> container_type_to_image = {
        {"AlmaLinux", "quay.io/toolbx-images/almalinux-toolbox:latest"},
        {"AlpineLinux", "quay.io/toolbx-images/alpine-toolbox:latest"},
        {"AmazonLinux", "quay.io/toolbx-images/amazonlinux-toolbox:latest"},
        {"ArchLinux", "quay.io/toolbx/arch-toolbox:latest"},
        {"BazziteArch", "ghcr.io/ublue-os/bazzite-arch:latest"},
        {"CentOS", "quay.io/toolbx-images/centos-toolbox:latest"},
        {"Debian", "quay.io/toolbx-images/debian-toolbox:latest"},
        {"Fedora", "registry.fedoraproject.org/fedora-toolbox:40"},
        {"OpenSuse", "registry.opensuse.org/opensuse/distrobox:latest"},
        {"RedHat", "registry.access.redhat.com/ubi9/toolbox"},
        {"RockyLinux", "quay.io/toolbx-images/rockylinux-toolbox:latest"},
        {"Ubuntu", "quay.io/toolbx/ubuntu-toolbox:latest"},
        {"Chainguard Wolfi", "quay.io/toolbx-images/wolfi-toolbox:latest"},
        {"ClearLinux", "docker.io/library/clearlinux:latest"},
        {"CrystalLinux", "registry.gitlab.com/crystal-linux/misc/docker:latest"},
        {"Deepin", "docker.io/linuxdeepin/apricot"},
        {"Gentoo", "docker.io/gentoo/stage3:latest"},
        {"KDE Neon", "invent-registry.kde.org/neon/docker-images/plasma:latest"},
        {"KaliLinux", "docker.io/kalilinux/kali-rolling:latest"},
        {"Mint", "docker.io/linuxmintd/mint21.1-amd64"},
        {"NeuroDebian", "docker.io/library/neurodebian:nd100"},
        {"OracleLinux", "container-registry.oracle.com/os/oraclelinux:9"},
        {"Slackware", "docker.io/vbatts/slackware:current"},
        {"SteamOS", "ghcr.io/linuxserver/steamos:latest"},
        {"VanillaOS", "ghcr.io/vanilla-os/vso:main"},
        {"VoidLinux", "ghcr.io/void-linux/void-glibc-full:latest"},
    };

    auto it = container_type_to_image.find(container_type);
    if (it != container_type_to_image.end()) {
        const std::string& image = it->second;
        run_in_terminal("ship --ctr create --image " + image + " --name " + container_name);
    }
}
