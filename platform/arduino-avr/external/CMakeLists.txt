
#==================== ArduinoCore-avr ====================#

add_library(arduino-core-avr
        INTERFACE)

target_include_directories(arduino-core-avr
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoCore-avr/cores/arduino)

file(GLOB LIBRARY_LIST LIST_DIRECTORIES TRUE ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoCore-avr/libraries/*)

foreach (LIBRARY_DIR ${LIBRARY_LIST})
    if (IS_DIRECTORY ${LIBRARY_DIR})
        target_include_directories(arduino-core-avr
                INTERFACE
                ${LIBRARY_DIR}/src)
    endif ()
endforeach ()
