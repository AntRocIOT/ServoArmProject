# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(picomain.c C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1



# Add the standard include files to the build


add_executable(picomain.c src/main.c src/servo.c src/values.c)

pico_set_program_name(picomain.c "picomain.c")
pico_set_program_version(picomain.c "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(picomain.c 0)
pico_enable_stdio_usb(picomain.c 1)


# Add the standard library to the build

target_link_libraries(picomain.c pico_stdlib hardware_gpio hardware_timer hardware_pwm hardware_clocks)

#add_library(ServoConf src/servo.c headers/servo.h)
#add_library(ValuesConf src/values.c headers/values.h)

target_include_directories(picomain.c PRIVATE ${CMAKE_CURRENT_LIST_DIR})
#target_include_directories(ServoConf PRIVATE "${CMAKE_CURRENT_LIST_DIR}/headers")
#target_include_directories(ValuesConf PRIVATE "${CMAKE_CURRENT_LIST_DIR}/headers")



pico_add_extra_outputs(picomain.c)

