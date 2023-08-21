
#==================== libosmio-headers ====================#

#if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libosmio-headers/CMakeLists.txt")
#    message(FATAL_ERROR "The libosmio-headers submodule was not downloaded! Try running 'git submodule update --init --recursive --remote'.")
#endif()

#add_subdirectory(libosmio-headers)

#==================== libosmio-loader ====================#

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libosmio-loader/CMakeLists.txt")
    message(FATAL_ERROR "The libosmio-loader submodule was not downloaded! Try running 'git submodule update --init --recursive --remote'.")
endif()

add_subdirectory(libosmio-loader)

#==================== AVR ====================#

#[[if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/README.md")
    message(FATAL_ERROR "The avr-libc submodule was not downloaded! Try running 'git submodule update --init --recursive --remote'.")
endif()

add_library(avr-libc
        INTERFACE)

target_include_directories(avr-libc
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/include)]]
