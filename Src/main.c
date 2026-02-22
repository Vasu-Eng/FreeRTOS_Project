#include <FreeRTOS.h>
#include"task.h"
#include<stdio.h>
#include"stm32f410rx.h"
TaskHandle_t task1_handle;
TaskHandle_t task2_handle;

uint32_t SystemCoreClock = 16000000;



void task1_handler(void *parameter){

	while(1){
	   printf("%s\n",(char*)parameter);
//	   taskYIELD();
	}
	vTaskDelete(task1_handle);
}
void task2_handler(void *parameter){
	while(1){
		printf("%s\n",(char*)parameter);
//		taskYIELD();
	}
	vTaskDelete(task2_handle);
}


int main(void){
	 BaseType_t task1_status = xTaskCreate(task1_handler,"Task-1",200,"Hello from Task1",2,&task1_handle);
	 configASSERT(task1_status== pdPASS);
	 BaseType_t task2_status = xTaskCreate(task2_handler,"Task-2",200,"Hello from Task2",2,&task2_handle);
     configASSERT(task2_status== pdPASS);

     vTaskStartScheduler();
	while(1){

	}
	return 0;
}
