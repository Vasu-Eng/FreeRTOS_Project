/*
 * BSP_UART.h
 *
 *  Created on: Mar 7, 2026
 *      Author: kesha
 */

#ifndef SEGGER_UART_RECORDER_BSP_UART_H_
#define SEGGER_UART_RECORDER_BSP_UART_H_

#include<string.h>
#include<stdint.h>
#include"stm32f410rx.h"

/************ register address *************/

#define GPIOAEN    (1U<<0)
#define USART2EN   (1U<<17)
#define CR1_TE     (1U<<3)
#define CR1_UE     (1U<<13)
#define SR_TXE     (1U<<7)
#define CR1_RE     (1U<<2)
#define SR_RXNE    (1U<<5)
#define SR_TC      (1U<<6)
#define CR1_PCE    (1U<<10)
#define CR1_PS     (1U<<9)
#define CR1_RXNEIE (1U<<5)
#define CR1_TXEIE  (1U<<7)


#define BSP_UART_PARITY_NONE 0
#define BSP_UART_PARITY_EVEN 1
#define BSP_UART_PARITY_ODD  2


typedef void (*BSP_UART_RX_CB)(unsigned int Unit, unsigned char c);
typedef int (*BSP_UART_TX_CB)(unsigned int Unit);


// public APIs (used in SEGGER SYSVIEW )
 void BSP_UART_Init(unsigned int Unit,
                    unsigned int Baudrate,
                    unsigned int Databits,
                    unsigned int Parity,
                    unsigned int Stopbits);

 void BSP_UART_Write1(unsigned int Unit, uint8_t data);

 void BSP_UART_SetReadCallback(unsigned int Unit, BSP_UART_RX_CB cb);

 void BSP_UART_SetWriteCallback(unsigned int Unit, BSP_UART_TX_CB cb);


#endif /* SEGGER_UART_RECORDER_BSP_UART_H_ */
