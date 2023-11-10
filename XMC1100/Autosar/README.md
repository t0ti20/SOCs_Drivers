# AUTOSAR Det & Dio Modules Implementation

![Screenshot 2023-09-29 091823](https://github.com/t0ti20/My_Implementation/assets/61616031/c9a010b8-fed2-4d8e-9d37-dbcd8927ee51)

Welcome to the repository that contains the implementation of the AUTOSAR Det (Default Error Tracer) module, Dio (Digital Input Output) module, and a test application for the Infineon XM1100.

## Table of Contents

1. [Overview](#overview)
2. [Det Module](#det-module)
3. [Dio Module](#dio-module)
4. [Test Application](#test-application)
5. [Getting Started](#getting-started)
6. [License & Author Information](#license--author-information)

## Overview

The presented software components, Det and Dio, are developed in compliance with the AUTOSAR R22-11 standard. The test application serves as a standalone demonstration of how to utilize the Dio driver with the Infineon XM1100.

## [Det Module](https://github.com/t0ti20/My_Implementation/blob/master/MicroControllers/XMC1100/Autosar/System_Services/Det.c)

**Description:**  
The Det module is responsible for reporting all detected development and runtime errors in the Basic Software.

**Usage:**  
- Include `Det.h` in your source code.
- Use the `Det_ReportError` function to report any detected errors, passing in the relevant Module ID, Instance ID, API ID, and Error ID.

## [Dio Module](https://github.com/t0ti20/My_Implementation/blob/master/MicroControllers/XMC1100/Autosar/Basic_Software/IO_Drivers/Dio.c)

**Description:**  
The Dio module provides APIs for the configuration and control of the Digital Input/Output channels and ports.

**Key Features:**  
- Compliant with the AUTOSAR R22-11 standard.
- Offers functions to read, write, flip, and masked-write to channels and ports.
- Supports different port widths.
- Extensive configuration macros and development error indications.

**Usage:**  
- Include `Dio.h` in your source code.
- Utilize the available API functions like `Dio_ReadChannel`, `Dio_WriteChannel`, `Dio_FlipChannel`, etc. to control and configure the I/O channels and ports.

## Test Application

**Description:**  
The provided application [(`Application.c`)](https://github.com/t0ti20/My_Implementation/blob/master/MicroControllers/XMC1100/Autosar/Application.c) serves as a standalone test to demonstrate the configuration and control of various GPIO pins for the Infineon XM1100. Note: This application is not developed following the AUTOSAR standards but is intended for testing purposes.

**Key Features:**  
- Initializes and configures GPIO channels.
- Demonstrates reading from and writing to DIO channels.

## License & Author Information

- **Author**: Khaled El-Sayed [@t0ti20](https://github.com/t0ti20)
