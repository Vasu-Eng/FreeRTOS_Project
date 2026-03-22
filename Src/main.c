#include <FreeRTOS.h>
#include"task.h"
#include<stdio.h>
#include"BSP_UART.h"
#include"stm32f410rx.h"
#include "core_cm4.h"

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;

uint32_t SystemCoreClock =  BSP_SYS_CLK_HZ;
void Clock_84MHz_Init(void);

#define DWT_CTRL    *((volatile uint32_t*)0xE0001000)
#define CYCCNTENA   (1U<<0)

#define LED1 (1U<<5)  //PA5
#define LED2 (1U<<6)  //PA6
#define LED3 (1U<<7)  //PA7
#define GPIPAEN (1U<<0)




void ITM_Print(const char *str)
{
    while(*str)
        ITM_SendChar(*str++);
}


void task1_handler(void *parameter){
	   TickType_t  LastTickCount = xTaskGetTickCount();
	   TickType_t frequency = pdMS_TO_TICKS(1000);
	while(1){
//	   ITM_Print((char*)parameter);
//	   ITM_Print("/n");
	   GPIOA->ODR ^=  LED1;
	   vTaskDelayUntil(&LastTickCount,frequency);
//	   taskYIELD();
	}
	vTaskDelete(task1_handle);
}
void task2_handler(void *parameter){
	   TickType_t  LastTickCount = xTaskGetTickCount();
	   TickType_t frequency = pdMS_TO_TICKS(500);
	while(1){
//		   ITM_Print((char*)parameter);
//		   ITM_Print("/n");
		   GPIOA->ODR ^=  LED2;
		   vTaskDelayUntil(&LastTickCount,frequency);
//		   taskYIELD();
	}
	vTaskDelete(task2_handle);
}

void task3_handler(void *parameter){
	   TickType_t  LastTickCount = xTaskGetTickCount();
	   TickType_t frequency = pdMS_TO_TICKS(100);
	while(1){
//		   ITM_Print((char*)parameter);
//		   ITM_Print("/n");
		   GPIOA->ODR ^=  LED3;
		   vTaskDelayUntil(&LastTickCount,frequency);
//		   taskYIELD();
	}
	vTaskDelete(task3_handle);
}


int main(void){
	/* initialize clock with 84MHz */
	   Clock_84MHz_Init();
 	     /*** Enable Count register for STM32 ******/
 	   DWT_CTRL |= CYCCNTENA;

//		CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
//		DWT->CYCCNT = 0;
//		DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

	     SYSVIEW_UART_Config();
		 SEGGER_SYSVIEW_Conf();
//		 SEGGER_SYSVIEW_DisableEvents(SEGGER_SYSVIEW_EVTMASK_SYSTICK);
	 	 SEGGER_SYSVIEW_Start();

	 RCC->AHB1ENR |= GPIOAEN;
	 // LED1 output
	 GPIOA->MODER |= (1U<<10);
	 // LED2 output
	 GPIOA->MODER |= (1U<<12);
	 // LED3 output
	 GPIOA->MODER |= (1U<<14);


	 BaseType_t task1_status = xTaskCreate(task1_handler,"Task-1",200,"Hello from Task1",2,&task1_handle);
	 configASSERT(task1_status== pdPASS);
	 BaseType_t task2_status = xTaskCreate(task2_handler,"Task-2",200,"Hello from Task2",2,&task2_handle);
     configASSERT(task2_status== pdPASS);
	 BaseType_t task3_status = xTaskCreate(task3_handler,"Task-3",200,"Hello from Task3",2,&task3_handle);
     configASSERT(task3_status== pdPASS);
     vTaskStartScheduler();
	while(1){

	}
	return 0;
}


void Clock_84MHz_Init(void)
{
    /* 1. Enable HSI */
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    /* 2. Flash latency (84 MHz → 2WS) */
    FLASH->ACR =
        FLASH_ACR_LATENCY_2WS |
        FLASH_ACR_ICEN |
        FLASH_ACR_DCEN;

    /* 3. Configure PLL */
    RCC->PLLCFGR =
        (16U << RCC_PLLCFGR_PLLM_Pos) |   // PLLM = 16
        (336U << RCC_PLLCFGR_PLLN_Pos) |  // PLLN = 336
        (1U << RCC_PLLCFGR_PLLP_Pos) |    // PLLP = 4
        (7U << RCC_PLLCFGR_PLLQ_Pos) |    // PLLQ = 7
        RCC_PLLCFGR_PLLSRC_HSI;           // HSI source

    /* 4. Enable PLL */
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    /* 5. Prescalers */
    RCC->CFGR |=
        RCC_CFGR_HPRE_DIV1  |   // AHB = 84 MHz
        RCC_CFGR_PPRE1_DIV2 |   // APB1 = 42 MHz ✅
        RCC_CFGR_PPRE2_DIV1;    // APB2 = 84 MHz

    /* 6. Switch to PLL */
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
