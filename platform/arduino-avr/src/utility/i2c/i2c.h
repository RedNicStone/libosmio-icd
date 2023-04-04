//
// Created by RedNicStone on 01/04/23.
//


#pragma once

#ifndef OSMIO_ICD_I2C_H
#define OSMIO_ICD_I2C_H

#include "libosmio.h"

#include <cstdint>
#include <vector>

#include "Wire.h"

OsProtocolInfo getI2CInfo();
std::vector<OsPhysicalInterfaceInfo> getI2CInterfaceInfos();

#endif //OSMIO_ICD_I2C_H
