
cmake_minimum_required(VERSION 3.7...3.26)

if (NOT DEFINED OSMIO_ICD_TARGET_PLATFORM)
    set(OSMIO_LOADER_ICD_PLATFORM "NONE")
    if (UNIX)
        set(OSMIO_ICD_TARGET_PLATFORM "UNIX")
    endif ()
endif ()

set(OSMIO_LOADER_TARGET_PLATFORM ${OSMIO_ICD_TARGET_PLATFORM})

add_subdirectory(external)

project(osmio-icd
        VERSION 0.1
        DESCRIPTION "A number of implementations of libosmio ICDs"
        LANGUAGES CXX)

add_subdirectory(platform)
