# Embedded Linux Real-Time Control Platform 

## Overview

This project demonstrates the implementation of **FreeRTOS** concepts in an embedded system environment. The goal of the project is to understand real-time task scheduling, inter-task communication, synchronization mechanisms, and resource management using FreeRTOS.

The project includes examples of:

* Task Creation and Scheduling
* Queue Communication
* Binary Semaphores
* Counting Semaphores
* Event Groups
* Software Timers (if implemented)
* Task Priorities
* ISR to Task Communication (if implemented)

FreeRTOS is a lightweight real-time operating system widely used in embedded applications requiring deterministic task execution and efficient resource utilization.

---

## Features

### Task Management

* Multiple tasks running concurrently.
* Priority-based preemptive scheduling.
* Periodic task execution using FreeRTOS APIs.

### Queue Communication

* Safe data transfer between tasks using FreeRTOS queues.
* Producer-Consumer implementation.

### Semaphore Synchronization

* Binary Semaphore for task synchronization.
* Counting Semaphore for resource management and event counting.

### Event Groups

* Event-driven task synchronization.
* Multiple event flags handled using Event Groups.

### Real-Time Operation

* Deterministic task execution.
* Efficient CPU utilization.
* Non-blocking system design where possible.

---

## Project Structure

```text
FreeRTOS_Project/
│
├── Core/
│   ├── Inc/
│   └── Src/
│
├── Drivers/
│
├── Middlewares/
│   └── FreeRTOS/
│
├── Debug/
│
├── README.md
│
└── <other project files>
```

---

## RTOS Concepts Demonstrated

### Tasks

Tasks are independent units of execution managed by the FreeRTOS scheduler.

Example:

```c
xTaskCreate(Task1,
            "Task1",
            256,
            NULL,
            2,
            NULL);
```

---

### Queues

Queues provide thread-safe communication between tasks. FreeRTOS queues are commonly used as FIFO buffers for message passing.

Example:

```c
xQueueSend(queueHandle, &data, portMAX_DELAY);
xQueueReceive(queueHandle, &data, portMAX_DELAY);
```

---

### Binary Semaphore

Binary semaphores are typically used for synchronization between tasks and interrupts.

Example:

```c
xSemaphoreGive(binarySemaphore);
xSemaphoreTake(binarySemaphore, portMAX_DELAY);
```

---

### Counting Semaphore

Counting semaphores are useful when multiple resources are available or when counting events.

Example:

```c
xSemaphoreGive(countSemaphore);
xSemaphoreTake(countSemaphore, portMAX_DELAY);
```

---

### Event Groups

Event Groups allow multiple event flags to be managed within a single synchronization object.

Example:

```c
xEventGroupSetBits(eventGroup, EVENT_BIT_1);

xEventGroupWaitBits(
    eventGroup,
    EVENT_BIT_1,
    pdTRUE,
    pdFALSE,
    portMAX_DELAY
);
```

---

## Hardware Used

* Microcontroller: **[STM32F4xx / STM32F1xx / ESP32 / Replace Here]**
* Development Board: **STM32F410RB**
* Clock Frequency: **16-84 MHz**
* Debugger: **ST-Link / J-Link**

---

## Software Requirements

* STM32CubeIDE / Keil uVision / VS Code
* FreeRTOS
* GCC ARM Toolchain
* Git

---

## Build Instructions

### Clone Repository

```bash
git clone https://github.com/Vasu-Eng/FreeRTOS_Project.git
cd FreeRTOS_Project
```

### Open Project

Open the project using your preferred IDE.

### Build

Compile the project and generate the firmware binary.

### Flash

Flash the generated firmware to the target board using:

* STM32CubeProgrammer
* ST-Link Utility
* J-Link
* OpenOCD

---

## Learning Outcomes

This project helped in understanding:

* RTOS scheduling
* Context switching
* Inter-task communication
* Synchronization mechanisms
* Resource sharing
* Embedded software architecture
* Real-time system design

---

## Future Improvements

* UART Driver Integration
* FreeRTOS + Embedded Linux Communication
* MQTT Support
* CAN Communication
* OTA Firmware Update
* CI/CD Pipeline for Embedded Projects
* Unit Testing Framework

---

## References

* FreeRTOS Official Documentation
* FreeRTOS Kernel API Reference
* FreeRTOS Example Projects

---

## Author

**Vasu Kesharwani**

Embedded Systems Engineer

GitHub:
https://github.com/Vasu-Eng
