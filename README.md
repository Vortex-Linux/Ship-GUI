# Ship-GUI

## Overview

Ship-GUI is a powerful, cross-distribution graphical interface for Ship, providing an intuitive way to manage virtual machines and containers across Linux environments. While primarily developed for Vortex Linux, the application is designed to work seamlessly on most Linux distributions.

## Features

- **Universal Virtual Machine Management**
  - Create, start, pause, resume, and delete virtual machines
  - Flexible VM resource configuration (CPU, memory)
  - Launch VM consoles and interfaces
  - Take and manage VM snapshots
  - Secure VM sharing capabilities

- **Comprehensive Container Management**
  - Create and manage containers from multiple distributions
  - Execute commands within containers
  - Package management (download, remove, search)
  - Container upgrading and stopping
  - Secure container sharing

- **Cross-Distribution Compatibility**
  - Works on virtually all major Linux distributions
  - Seamless environment management across different systems
  - Optimal performance on Vortex Linux

## Prerequisites

- Virtualization enabled in BIOS
- KVM kernel module enabled
- Please refer the [Ship README](https://github.com/Vortex-Linux/ship.git) for comprehensive list of dependencies

## Installation

### From Source
```bash
git clone https://github.com/Vortex-Linux/Ship-GUI.git
cd Ship-GUI
make  
build/Ship-GUI  
```

## Build Dependencies

Ensure you have the following dependencies installed:
- Qt5 development libraries
- Make
- GCC
- libvirt development libraries
- qemu development libraries

## Usage

Launch the application and explore the comprehensive interface for managing your virtual machines and containers across different Linux environments.
