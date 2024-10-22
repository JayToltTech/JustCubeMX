cmake_minimum_required(VERSION 3.30)
cmake_policy(SET CMP0156 NEW)
cmake_policy(SET CMP0159 NEW)
cmake_policy(SET CMP0102 NEW)
cmake_policy(SET CMP0126 NEW)
cmake_policy(SET CMP0066 NEW)

if(NOT CMAKE_TOOLCHAIN_FILE)
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/wb5mxx.cmake)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(JustCubeMX
  VERSION 0.0.1
  LANGUAGES C ASM)

# Double call this file so it can substitute in both the project name as well as the version
configure_file(${PROJECT_SOURCE_DIR}/cmake/version.h.in ${PROJECT_SOURCE_DIR}/cmake/version.h.in.out)
configure_file(${PROJECT_SOURCE_DIR}/cmake/version.h.in.out ${PROJECT_SOURCE_DIR}/version.h)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message("Build type: " ${CMAKE_BUILD_TYPE})

add_executable(${PROJECT_NAME})

# Add stack smashing protection
add_compile_options("-fstack-protector-all")

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/faults.c
    ${CMAKE_CURRENT_LIST_DIR}/error_handler.c
    ${CMAKE_CURRENT_LIST_DIR}/stack_protection.c
)

if (NOT TARGET stm32cubemx)
  find_package(stm32cubemx REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR}/libraries/cubemx_wb5m)
endif()
target_link_libraries(${PROJECT_NAME} stm32cubemx)