cmake_minimum_required(VERSION 3.17)
project(hdrToggle)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
set(NVAPI_DL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/R450-developer.zip")
set(NVAPI_PROJECT_NAME ext_nvapi)
set(NVAPI_PROJECT_PATH ${CMAKE_CURRENT_BINARY_DIR}/nvapi)
set(NVAPI_PATH ${NVAPI_PROJECT_PATH}/src/${NVAPI_PROJECT_NAME})
ExternalProject_Add(${NVAPI_PROJECT_NAME}
    URL ${NVAPI_DL_PATH}
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/nvapi
    CONFIGURE_COMMAND ""
    INSTALL_COMMAND ""
    BUILD_COMMAND ""
)

add_library(nvapi STATIC IMPORTED)
target_compile_definitions(nvapi
    INTERFACE _WIN32
)

if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "win32")
    set(nvlib x86/nvapi.lib)
else()
    set(nvlib amd64/nvapi64.lib)
endif()

set_property(TARGET nvapi PROPERTY IMPORTED_LOCATION ${NVAPI_PATH}/${nvlib})
add_dependencies(nvapi ext_nvapi)

include_directories(
    ${NVAPI_PATH}
)

file(GLOB SRC_FILES
    *.cpp
)


add_executable(hdrToggle main.cpp api/include/color_mode.h api/include/sdk_status.h api/include/toggle.h api/nvapi_deps.h api/sdk_status.cpp api/toggle.cpp api/sdk_status.h api/toggle.h icon/AppIcon.rc)

# Needs to be after executable
# See: https://stackoverflow.com/a/56276299/12347616
target_link_libraries(${PROJECT_NAME} nvapi)