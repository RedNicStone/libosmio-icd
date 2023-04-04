
get_filename_component(PLATFORM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(LIBOSMIO_PLATFORM_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIBOSMIO_PLATFORM_UTILITY src/utility)

file(GLOB_RECURSE LIBOSMIO_PLATFORM_HEADERS ${LIBOSMIO_PLATFORM_INCLUDE}/**.h)
file(GLOB_RECURSE LIBOSMIO_PLATFORM_SOURCES ${LIBOSMIO_PLATFORM_INCLUDE}/**.cpp)

add_subdirectory(external)

add_library(osmio-icd-${PLATFORM_NAME}
        STATIC ${LIBOSMIO_PLATFORM_SOURCES})
add_library(libosmio-icd-${PLATFORM_NAME}
        ALIAS osmio-icd-${PLATFORM_NAME})

target_link_libraries(osmio-icd-${PLATFORM_NAME}
        PUBLIC  osmio-headers)

target_link_options(osmio-icd-${PLATFORM_NAME}
        PRIVATE "-u registerICD")
