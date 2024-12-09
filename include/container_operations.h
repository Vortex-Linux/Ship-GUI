#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include "headers.h"
#include "utils.h"

std::vector<std::string> list_container_names();
std::vector<std::string> list_container_status();
std::string list_updated_container_status(std::string container_name);
void delete_container(std::string container_name);
void view_container(std::string container_name);
void upgrade_container(std::string container_name);
void stop_container(std::string container_name);
void send_container(std::string container_name);
void create_container(std::string container_name);

#endif 

