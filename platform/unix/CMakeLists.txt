
get_filename_component(PLATFORM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(LIBOSMIO_PLATFORM_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIBOSMIO_PLATFORM_UTILITY src/utility)

file(GLOB_RECURSE LIBOSMIO_PLATFORM_HEADERS ${LIBOSMIO_PLATFORM_INCLUDE}/**.h)
file(GLOB_RECURSE LIBOSMIO_PLATFORM_SOURCES ${LIBOSMIO_PLATFORM_INCLUDE}/**.cpp)

add_library(osmio-icd-${PLATFORM_NAME}
        SHARED ${LIBOSMIO_PLATFORM_SOURCES})
add_library(libosmio-icd-${PLATFORM_NAME}
        ALIAS osmio-icd-${PLATFORM_NAME})

target_link_libraries(osmio-icd-${PLATFORM_NAME}
        PUBLIC osmio-headers
        PRIVATE osmio-loader)

option(${PLATFORM_NAME}_ICD_INSTALL_LOCATION
        "Where ${PLATFORM_NAME} icd library object is stored"
        "$ENV{HOME}/lib")

option(${PLATFORM_NAME}_ICD_CONFIG_LOCATION
        "Where ${PLATFORM_NAME} icd config file is stored"
        "$ENV{HOME}/.local/share/osmio/icd.d/${PLATFORM_NAME}.json")

set(ICD_INSTALL_LOCATION ${${PLATFORM_NAME}_ICD_INSTALL_LOCATION})
set(ICD_API_VERSION "1.0.0")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.json.in ${CMAKE_CURRENT_BINARY_DIR}/config.json)

install(TARGETS osmio-icd-${PLATFORM_NAME}
        LIBRARY DESTINATION ${${PLATFORM_NAME}_ICD_INSTALL_LOCATION})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config.json DESTINATION ${PLATFORM_NAME}_ICD_CONFIG_LOCATION)
