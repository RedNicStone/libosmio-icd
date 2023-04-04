//
// Created by RedNicStone on 01/04/23.
//

#include "i2c.h"

OsProtocolInfo getI2CInfoMaster(bool master) {
    OsAddressType masterFormat{};
    masterFormat.format = OS_ADDRESS_FORMAT_NONE;
    masterFormat.maximumLength = 0;

    OsAddressType slaveFormat{};
    slaveFormat.format = OS_ADDRESS_FORMAT_FIXED_LENGTH;
    slaveFormat.maximumLength = 9;

    OsProtocolInfo info{};
    if (master) {
        info.name       = (char*) "Arduino AVR I2C Master";
        info.joinType   = masterFormat;
        info.targetType = slaveFormat;
    } else {
        info.name       = (char*) "Arduino AVR I2C Slave";
        info.joinType   = slaveFormat;
        info.targetType = masterFormat;
    }

    return info;
}

std::vector<OsPhysicalInterfaceInfo> getI2CInterfaceInfos() {
    OsPhysicalInterfaceInfo interfaceInfo{};
    interfaceInfo.
}
