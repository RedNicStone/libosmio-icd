
set_target_properties(osmio-headers PROPERTIES
        LIBOSMIO_HIDE_LOADER_FUNCTIONS ON)

file(GLOB PLATFORM_LIST LIST_DIRECTORIES TRUE ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach (PLATFORM_DIR ${PLATFORM_LIST})
    if (IS_DIRECTORY ${PLATFORM_DIR})
        add_subdirectory(${PLATFORM_DIR})
    endif ()
endforeach ()
