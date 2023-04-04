//
// Created by RedNicStone on 01/04/23.
//

#include "libosmio.h"

__attribute__((constructor))
void registerICD() {
    OsICD icd{};
    icd.name = (char*) "Arduino AVR";

    osRegisterICD(&icd);
}


