
if (OSMIO_ICD_TARGET_PLATFORM STREQUAL "ALL")
    file(GLOB PLATFORM_LIST LIST_DIRECTORIES TRUE ${CMAKE_CURRENT_SOURCE_DIR}/*)

    foreach (PLATFORM_DIR ${PLATFORM_LIST})
        if (IS_DIRECTORY ${PLATFORM_DIR})
            add_subdirectory(${PLATFORM_DIR})
        endif ()
    endforeach ()
elseif (OSMIO_ICD_TARGET_PLATFORM STREQUAL "UNIX")
    add_subdirectory(unix)
endif ()
