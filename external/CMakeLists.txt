
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(OFF)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive --remote
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive --remote failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#==================== libosmio-headers ====================#

#if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libosmio-headers/CMakeLists.txt")
#    message(FATAL_ERROR "The libosmio-headers submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
#endif()

#add_subdirectory(libosmio-headers)

#==================== libosmio-loader ====================#

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libosmio-loader/CMakeLists.txt")
    message(FATAL_ERROR "The libosmio-headers submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(libosmio-loader)

#==================== AVR ====================#

#[[if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/README.md")
    message(FATAL_ERROR "The avr submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_library(avr-libc
        INTERFACE)

target_include_directories(avr-libc
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/include)]]
