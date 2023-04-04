//
// Created by RedNicStone on 03/04/23.
//

#ifndef OSMIO_ICD_STRUCTURES_H
#define OSMIO_ICD_STRUCTURES_H

#include <libosmio/handles.h>

enum OsArduinoAVRDeviceType {
    OS_ARDUINO_AVR_DEVICE_TYPE_I2C = 0,
};

struct OsDevice_T {
    OsArduinoAVRDeviceType arduinoAvrDeviceType;
};

#endif //OSMIO_ICD_STRUCTURES_H
