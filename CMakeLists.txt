cmake_minimum_required(VERSION 3.14)
project(07_device_identity VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    03_device_connectivity
    GIT_REPOSITORY https://github.com/compilerNayan/03_device_connectivity.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(03_device_connectivity)

add_library(07_device_identity INTERFACE)

set_target_properties(07_device_identity PROPERTIES
    VERSION ${PROJECT_VERSION}
)

target_include_directories(07_device_identity INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

if(TARGET 03_device_connectivity::03_device_connectivity)
    target_link_libraries(07_device_identity INTERFACE 03_device_connectivity::03_device_connectivity)
elseif(TARGET 03_device_connectivity)
    target_link_libraries(07_device_identity INTERFACE 03_device_connectivity)
else()
    FetchContent_GetProperties(03_device_connectivity)
    if(03_device_connectivity_SOURCE_DIR)
        target_include_directories(07_device_identity INTERFACE
            $<BUILD_INTERFACE:${03_device_connectivity_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${03_device_connectivity_SOURCE_DIR}>
        )
    endif()
endif()

include(GNUInstallDirs)

install(TARGETS 07_device_identity
    EXPORT 07_device_identityTargets
)

install(EXPORT 07_device_identityTargets
    FILE 07_device_identityTargets.cmake
    NAMESPACE 07_device_identity::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/07_device_identity
)
