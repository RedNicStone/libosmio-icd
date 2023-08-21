//
// Created by RedNicStone on 22/08/23.
//

#include <libosmio-loader/entrypoint.h>

extern "C" void os_icdGetGlobalDispatchTable(Os_icdGlobalDispatchTable** ppDispatchTable) {
    ppDispatchTable = nullptr;
}
