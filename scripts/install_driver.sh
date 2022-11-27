#!/bin/bash

: '
Driver installation script by Matt Kouba
This script works for Le Potato boards

Created by Matt Kouba, November 2022
Created for Senior Design

Based on qmi_install.sh created by SixFab
https://raw.githubusercontent.com/sixfab/Sixfab_QMI_Installer/main/qmi_install.sh
'

# Text Colors
YELLOW='\033[1;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
SET='\033[0m'

# Directories
INS_DIR=/opt/qmi_driver_install/
UDHCPC_DIR=/etc/udhcpc/

# Service names
service_reconnect=qmi_reconnect.service
service_ModemManager=ModemManager

# Installations
echo -e "${YELLOW}Installing kernel headers for Ubuntu${SET}"
apt install linux-headers-$(uname -r) -y

echo -e "${YELLOW}Installing udhcpc${SET}"
apt install udhcpc -y

echo -e "${YELLOW}Changing permissions on udhcpc script{$SET}"
pushd $UDHCPC_DIR
chmod +x default.script
popd

# Download resources
echo -e "${YELLOW}Create and change directory to $INS_DIR ${SET}"
mkdir -p $INS_DIR && pushd $INS_DIR

echo -e "${YELLOW}Downloading and installing EG25-G Serial Driver${SET}"
wget https://github.com/mckouba/EG25-G_Setup/releases/download/drivers/Serial_DRIVER_V1.zip -O serial.zip
unzip serial.zip -d $INS_DIR && rm serial.zip
pushd $INS_DIR/serial
make && make install
popd

echo -e "${YELLOW}Downloading and installing EG25-G Gobinet Driver${SET}"
wget https://github.com/mckouba/EG25-G_Setup/releases/download/drivers/Gobinet_DRIVER_V1.zip -O gobinet.zip
unzip gobinet.zip -d $INS_DIR && rm gobinet.zip
pushd $INS_DIR/gobinet
make && make install
popd

echo -e "${YELLOW}Downloading and installing EG25-G QMI_WWAN Driver${SET}"
wget https://github.com/mckouba/EG25-G_Setup/releases/download/drivers/QMI_WWAN_DRIVER_V1.zip -O qmi.zip
unzip qmi.zip -d $INS_DIR && rm qmi.zip
pushd $INS_DIR/qmi
make && make install
popd

echo -e "${YELLOW}Downloading Connection Manager${SET}"
wget https://github.com/mckouba/EG25-G_Setup/releases/download/drivers/quectel-CM_V1.zip -O quectel-CM.zip
unzip quectel-CM.zip -d $INS_DIR && rm quectel-CM.zip
pushd $INS_DIR/quectel-CM
make
