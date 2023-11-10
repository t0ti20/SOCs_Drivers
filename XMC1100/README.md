# GPIO Driver Testing for Infineon XM1100

**Owner**: Khaled El-Sayed (@t0ti20)

**Location**: ./Application

**Source Files**: Application.c

![Screenshot 2023-09-07 184001](https://github.com/t0ti20/My_Implementation/assets/61616031/912d4e19-8c12-4657-ab14-1c7c43f184db)


## Overview

This project primarily tests the GPIO (General-Purpose Input/Output) driver functionalities for the Infineon XM1100 microcontroller. The GPIO driver offers essential utilities to manipulate the pins on the microcontroller for various purposes.

## Functionality

### 1. GPIO Pin Configuration

- A GPIO pin configuration structure (`GPIO_Pin_Config_t`) is defined, which contains configurations for a particular GPIO pin.
- An array, `Pins`, designates a set of pins intended for testing.

### 2. Initialization

- In the `main` function, the application initializes the pins specified in the `Pins` array using the configuration structure. This initialization prepares the pins for further operations.

### 3. Pin Manipulation in Infinite Loop

- The application enters an infinite loop where it continually manipulates the pin's state.
- For each pin in the `Pins` array:
  - The pin's state is toggled.
  - simple delay function.
  - The pin's state is toggled.
  - simple delay function.

## Key Points

- The application acts as a GPIO test routine for the Infineon XM1100.
- It utilizes a constant loop to keep toggling pin and port states, making it helpful in observing real-time changes on the microcontroller pins.
- The application emphasizes the non-blocking nature of GPIO operations.

