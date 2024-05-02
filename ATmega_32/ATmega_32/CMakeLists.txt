#/*******************************************************************
# *  FILE DESCRIPTION
#-----------------------
# *  Author: Khaled El-Sayed @t0ti20
# *  File: ./Main.cpp
# *  Date: March 28, 2024
# *  Description: Genaric CMake File For ATMega_32 
# *  (C) 2023 "@t0ti20". All rights reserved.
#*******************************************************************/
#Building Message
message(STATUS "================== Building Application ==================")

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.0)

#Set Project Name   
set(Application_Name Test)

#Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

#Set Programming Type
set(Programming_Type usbasp)

# Set the AVR chip Configuration
set(MCU atmega32)
set(F_CPU 8000000)
set(BAUDRATE 9600)

#Adding CPU_Select
add_definitions(-DF_CPU=${F_CPU})

#Compiler Nameing
set(AVR_CPP avr-g++)
set(AVR_GCC avr-gcc)
set(AVR_STRIP avr-strip)
set(AVR_OBJCOPY avr-objcopy)
set(AVR_OBJDUMP avr-objdump)
set(AVR_SIZE avr-size)
set(AVR_DUDE avrdude)

# Set the system name to "Generic"
set(CMAKE_SYSTEM_NAME Generic)

# Set the C++ compiler to the AVR C++ compiler
set(CMAKE_CXX_COMPILER ${AVR_CPP} CACHE STRING "C++ Compiler" FORCE)

# Set the C compiler to the AVR GCC compiler
set(CMAKE_C_COMPILER ${AVR_GCC} CACHE STRING "C Compiler" FORCE)

# Set the assembly (ASM) compiler to the AVR GCC compiler
set(CMAKE_ASM_COMPILER ${AVR_GCC} CACHE STRING "ASM Compiler" FORCE)

#Set Project Name
project (${Application_Name} C CXX ASM)

#Locate Source Files
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Source/*.c" "Source/*.cpp" "Library/*.cpp" "Library/*.c")

#Building Message
message(STATUS "Files To Be Compiled : ${SOURCES}")

# Compiler flags
set(CSTANDARD "-std=gnu99")
set(CDEBUG "-g -ggdb")
set(CWARN "-Wall -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax -Wno-unused-include-directive")
set(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
set(COPT "-Os -lm -lprintf_flt")
set(CMCU "-mmcu=${MCU}")
set(CDEFS "-DF_CPU=${F_CPU} -DBAUDRATE=${BAUDRATE}")
set(CFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING}")
set(CXXFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CTUNING} -Wno-unused-include-directive")
set(CMAKE_C_FLAGS "${CFLAGS}")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
set(CMAKE_ASM_FLAGS "${CFLAGS}")

#Add Executable
add_executable(${PROJECT_NAME} ${SOURCES})

#Set output name for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

#Strip target: Strip symbols from the ELF binary
add_custom_target(strip ALL ${AVR_STRIP} "${PROJECT_NAME}.elf" DEPENDS ${PROJECT_NAME})

#Hex target: Convert ELF binary to Intel HEX format
add_custom_target(hex ALL ${AVR_OBJCOPY} -R .eeprom -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex" DEPENDS strip)

#Eeprom target: Create HEX file for EEPROM memory
add_custom_target(eeprom ${AVR_OBJCOPY} -j .eeprom --change-section-lma .eeprom=0 -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.eeprom" DEPENDS strip)

#Flash target: Flash the microcontroller with the generated HEX file
add_custom_target(flash ${AVR_DUDE} -c ${Programming_Type} -p ${MCU} -U flash:w:${PROJECT_NAME}.hex DEPENDS hex)

# Collect all header files recursively from the Include directory
file(GLOB_RECURSE INCLUDE_FILES "${CMAKE_SOURCE_DIR}/*.hpp" "${CMAKE_SOURCE_DIR}/*.h")

# Add each header file to the project
foreach(INCLUDE_FILE ${INCLUDE_FILES})
    get_filename_component(INCLUDE_DIR ${INCLUDE_FILE} DIRECTORY)
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" RELATIVE_INCLUDE_DIR ${INCLUDE_DIR})
    string(REPLACE "/" "\\" RELATIVE_INCLUDE_DIR_WINDOWS ${RELATIVE_INCLUDE_DIR})
    target_sources(${PROJECT_NAME} PRIVATE ${INCLUDE_FILE})
    target_include_directories(${PROJECT_NAME} PRIVATE ${RELATIVE_INCLUDE_DIR})
endforeach()