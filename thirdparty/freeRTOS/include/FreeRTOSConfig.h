#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include"stm32f410rx.h" /* CMSIS header */

/*-----------------------------------------------------------
 * Application specific definitions.
 *----------------------------------------------------------*/

/* Cortex-M4F specific definitions */
#define configCPU_CLOCK_HZ              ( SystemCoreClock )
#define configTICK_RATE_HZ              ( ( TickType_t ) 500 )   /* 2 ms tick */
#define configUSE_PREEMPTION            0
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configMAX_PRIORITIES            7
#define configMINIMAL_STACK_SIZE        ( ( uint16_t ) 128 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) ( 12 * 1024 ) )
#define configMAX_TASK_NAME_LEN         16
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1
#define configUSE_TIME_SLICING          1

/* Hook function related definitions */
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCHECK_FOR_STACK_OVERFLOW  0
#define configUSE_MALLOC_FAILED_HOOK    0

/* Run time and task stats gathering */
#define configGENERATE_RUN_TIME_STATS   0
#define configUSE_TRACE_FACILITY        1
#define configUSE_STATS_FORMATTING_FUNCTIONS 1

/* Co-routine definitions */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES 2

/* Software timer definitions */
#define configUSE_TIMERS                0
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH        10
#define configTIMER_TASK_STACK_DEPTH    256

/*-----------------------------------------------------------
 * Memory allocation related definitions.
 *----------------------------------------------------------*/

#define configSUPPORT_STATIC_ALLOCATION 0
#define configSUPPORT_DYNAMIC_ALLOCATION 1

/*-----------------------------------------------------------
 * Interrupt nesting behavior configuration.
 *----------------------------------------------------------*/

#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS         __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS         4   /* STM32F4 uses 4 bits */
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/*-----------------------------------------------------------
 * API function inclusion.
 *----------------------------------------------------------*/

#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskCleanUpResources   0
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelay              1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_xTaskGetSchedulerState  1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define INCLUDE_xTaskGetTickCount       1
/****** SEGGER Settings **********/
#define INCLUDE_xTaskGetIdleTaskHandle  1
#define INCLUDE_pxTaskGetStackStart     1

/*-----------------------------------------------------------
 * Cortex-M specific FreeRTOS port definitions.
 *----------------------------------------------------------*/

#define configUSE_MPU                   0
#define configENABLE_FPU                1
#define configENABLE_TRUSTZONE          0

/*-----------------------------------------------------------
 * Assert definition
 *----------------------------------------------------------*/

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#define         SVC_Handler      vPortSVCHandler
#define	       PendSV_Handler   xPortPendSVHandler
#define		   SysTick_Handler  xPortSysTickHandler

#include "SEGGER_SYSVIEW_FreeRTOS.h"

#endif /* FREERTOS_CONFIG_H */
