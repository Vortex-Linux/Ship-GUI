#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include "headers.h"
#include "utils.h"

std::vector<std::string> list_container_names();
std::vector<std::string> list_container_status();
void deleteContainer(std::string container_name);
void viewContainer(std::string container_name);
void upgradeContainer(std::string container_name);
void stopContainer(std::string container_name);
void sendContainer(std::string container_name);

#endif 

