/*
 * BSP_UART.C
 *
 *  Created on: Mar 7, 2026
 *      Author: kesha
 */

#include"BSP_UART.h"


static BSP_UART_RX_CB _rx_cb =0;
static BSP_UART_TX_CB _tx_cb =0;


uint16_t calculate_usartdiv( USART_TypeDef *USARTx, uint32_t fclk, uint32_t baud, uint16_t oversampling_val){
	uint16_t USART_MAT = 0 ;
    uint16_t USART_FAR = 0 ;
    uint16_t SET_USART_BRR = 0;
    double mantissa = ((double)fclk / ( oversampling_val * (double)baud));

    double fraction = (mantissa - (long)mantissa) * oversampling_val;

    USART_MAT = mantissa;
    if((fraction -(long)fraction) >= 0.5)fraction++;
    if( fraction >= oversampling_val){
    	fraction = 0;
    	mantissa++;
    }
    USART_FAR = fraction;
    SET_USART_BRR  = (USART_MAT << 4U);
    SET_USART_BRR |= (USART_FAR << 0);
    return SET_USART_BRR;
}



void BSP_UART_SetReadCallback(unsigned int Unit, BSP_UART_RX_CB cb){
	(void)Unit;
    _rx_cb = cb;
}

void BSP_UART_SetWriteCallback(unsigned int Unit, BSP_UART_TX_CB cb){
	(void)Unit;
    _tx_cb = cb;
}


void BSP_UART_Write1(unsigned int Unit, uint8_t data){
	(void)Unit;
	while (!(USART2->SR & SR_TXE));
    /* directly writing data */
    USART2->DR = data;
    /* enabling tx complete interrupt */
    USART2->CR1 |= CR1_TCIE;
}


void BSP_UART_Init(unsigned int Unit,unsigned int Baudrate,unsigned int Databits,unsigned int Parity,unsigned int Stopbits){

    (void)Unit;
    (void)Databits;
    (void)Stopbits;

	/********* configure GPIO  **********/
	/*enable clock access to GPIOA  module*/
	RCC->AHB1ENR |= GPIOAEN;
	/*configure PA2 as Alternative function mode */
	GPIOA->MODER |= (2U<<4);
    /* configure PA3 as Alternative function mode*/
	GPIOA->MODER |= (2U<<6);
	/* Set PA2 alternate function type to USART2_TX */
	GPIOA->AFR[0] |= (7U<<8);
    /* select the specific mode of Af for USART2*/
    GPIOA->AFR[0] |= (7U<<12);

/*
     VERY IMPORTANT
    GPIOA->PUPDR &= ~((3U<<4) | (3U<<6));
    GPIOA->PUPDR |=  (1U<<6);   // Pull-up on RX

    GPIOA->OSPEEDR |= (3U<<4) | (3U<<6);  // High speed
*/

	/***********Configure USART module ************/

	/*enable clock access to usart2 module */
	RCC->APB1ENR |= USART2EN; // enable clock access
	/*configure baudrate*/
    USART2->BRR  = calculate_usartdiv(USART2,BSP_SYS_CLK_HZ/APB1_PRESCALER,Baudrate,16);

    if (Parity == BSP_UART_PARITY_EVEN) {
        USART2->CR1 |= CR1_PCE;
    }
    else if (Parity == BSP_UART_PARITY_ODD) {
        USART2->CR1 |= CR1_PCE | CR1_PS;
    }
    /* Enable RX interrupt */
    USART2->CR1 |= CR1_RXNEIE;

	/*enable transmitter and Receiver*/
    USART2->CR1  |= ( CR1_TE  | CR1_RE);

    /*enable uart module */
    USART2->CR1 |= CR1_UE;

    /* Enable NVIC interrupt */
    NVIC_EnableIRQ(USART2_IRQn);
}

void USART2_IRQHandler(void)
{   /***** Rx interrupt ******/
    if (USART2->SR & SR_RXNE)
    {
        uint8_t data = USART2->DR;

        if (_rx_cb) {
            _rx_cb(2, data);
        }
    }

    /******** TX COMPLETE ********/
    if (USART2->SR & SR_TC)
    {
        /* Clear TC properly */
        USART2->SR &= ~SR_TC;

        /* Disable TC interrupt */
        USART2->CR1 &= ~CR1_TCIE;

        /* Notify SEGGER */
        if (_tx_cb)
        {
            _tx_cb(2);
        }
    }
}




