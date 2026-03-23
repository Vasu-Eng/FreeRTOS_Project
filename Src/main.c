#include <FreeRTOS.h>
#include"task.h"
#include<stdio.h>
#include"BSP_UART.h"
#include"stm32f410rx.h"
#include "core_cm4.h"

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;
TaskHandle_t task4_handle;
TaskHandle_t next_task_handle = NULL;

uint32_t SystemCoreClock =  BSP_SYS_CLK_HZ;
void Clock_84MHz_Init(void);

#define DWT_CTRL    *((volatile uint32_t*)0xE0001000)
#define CYCCNTENA   (1U<<0)
#define LED1        (1U<<5)  //PA5
#define LED2        (1U<<6)  //PA6
#define LED3        (1U<<7)  //PA7
#define BUTTON_PIN  (1U<<13) //PC13
#define GPIOAEN     (1U<<0)
#define GPIOCEN     (1U<<2)
#define SYSCFGEN    (1U<<14)


volatile int button_status = -1;

void ITM_Print( char *str)
{
    while(*str)
        ITM_SendChar(*str++);
}

void ITM_PrintInt(int val)
{
    char buf[20];
    sprintf(buf, "%d\r\n", val);
    ITM_Print(buf);
}

int button_read(){
	if(GPIOC->IDR & BUTTON_PIN){
		return 1;
	}
	else return 0;
}

void EXTI15_10_IRQHandler(){
    if(EXTI->PR & (1U<<13)){
    	 EXTI->PR |= (1U<<13);
    	 // if this is trigger that  means button was triggered
    	 xTaskNotifyFromISR(next_task_handle,0,eNoAction,NULL);
//    	 button_status  = button_read();
//		 ITM_Print( "button_status : ");
//		 ITM_PrintInt( button_status);
//		 ITM_Print("\n");
    }
}

void EXTI_configuration_for_pc13_button_pin (){

    // Button pin input configuration
	 GPIOC->MODER &= ~(3U << 26); // set as an input
    // using Pullup register
	 GPIOC->PUPDR |= (1U<<26);
     SYSCFG->EXTICR[3] |= (2U<<4); // Connecting EXTI13 line
     // unmask the interrupt MR13  line
    EXTI->IMR |= (1U<<13);
	//falling edge selection register
	EXTI->FTSR |= (1U<<13);
	// set priority in NVIC
	NVIC_SetPriority(EXTI15_10_IRQn,6);
	// enable handler in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}


void task1_handler(void *parameter){
	BaseType_t status;
	while(1){
//	   ITM_Print((char*)parameter);
//	   ITM_Print("/n");
	   GPIOA->ODR ^=  LED1;
	   status = xTaskNotifyWait(0,0,0,pdMS_TO_TICKS(1000));
	   if(status == pdPASS){
		   portENTER_CRITICAL();
		   next_task_handle = task2_handle;
		   portEXIT_CRITICAL();
		   ITM_Print( " task 1 is deleting \n");
//		   vTaskDelete(NULL);
		   vTaskSuspend(NULL);
	   }
	}
}
void task2_handler(void *parameter){
	BaseType_t status;
	while(1){
//		   ITM_Print((char*)parameter);
//		   ITM_Print("/n");
		   GPIOA->ODR ^=  LED2;
		   status = xTaskNotifyWait(0,0,0,pdMS_TO_TICKS(100));
		   if(status == pdPASS){
			   portENTER_CRITICAL();
			   next_task_handle = task3_handle;
			   portEXIT_CRITICAL();
			   ITM_Print( " task 2 is deleting \n");
//			   vTaskDelete(NULL);
			   vTaskSuspend(NULL);
		   }
		}
	}

void task3_handler(void *parameter){
	BaseType_t status;
	while(1){
//		   ITM_Print((char*)parameter);
//		   ITM_Print("/n");
		   GPIOA->ODR ^=  LED3;
		   status = xTaskNotifyWait(0,0,0,pdMS_TO_TICKS(500));
		   if(status == pdPASS){
			   ITM_Print( " task 3 is deleting \n");
//			   vTaskDelete(NULL);
			   portENTER_CRITICAL();
			   next_task_handle = task4_handle;
			   portEXIT_CRITICAL();
			   vTaskSuspend(NULL);
		   }
		}
}


void task4_handler(void *parameter){
	BaseType_t status;
	while(1){
		   status = xTaskNotifyWait(0,0,0,pdMS_TO_TICKS(500));
		   if(status == pdPASS){
			   ITM_Print( " resuming all tasks \n");
//			   vTaskDelete(NULL);
			   vTaskResume(task1_handle);
			   vTaskResume(task2_handle);
			   vTaskResume(task3_handle);
			   next_task_handle = task1_handle;

		   }
		}
}




int main(void){
     /* initialize clock with 84MHz */
     Clock_84MHz_Init();
	 /*** Enable Count register for STM32 ******/
	 DWT_CTRL |= CYCCNTENA;
     //SYSVIEW_UART_Config();
	 SEGGER_SYSVIEW_Conf();
	 SEGGER_SYSVIEW_Start();
     // clock enable
	 RCC->AHB1ENR |= GPIOAEN;
	 RCC->AHB1ENR |= GPIOCEN;
	 RCC->APB2ENR |= SYSCFGEN;
	 // LED1 output
	 GPIOA->MODER |= (1U<<10);
	 // LED2 output
	 GPIOA->MODER |= (1U<<12);
	 // LED3 output
	 GPIOA->MODER |= (1U<<14);

	 EXTI_configuration_for_pc13_button_pin ();


	 BaseType_t task1_status = xTaskCreate(task1_handler,"Task-1",200,"Hello from Task1",3,&task1_handle);
	 configASSERT(task1_status== pdPASS);
	 BaseType_t task2_status = xTaskCreate(task2_handler,"Task-2",200,"Hello from Task2",2,&task2_handle);
     configASSERT(task2_status== pdPASS);
	 BaseType_t task3_status = xTaskCreate(task3_handler,"Task-3",200,"Hello from Task3",1,&task3_handle);
     configASSERT(task3_status== pdPASS);
	 BaseType_t task4_status = xTaskCreate(task4_handler,"Task-4",200,"Hello from Task4",0,&task4_handle);
     configASSERT(task4_status== pdPASS);
	 next_task_handle = task1_handle;
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
