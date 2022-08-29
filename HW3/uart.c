#include "uart.h"
#include "rcc.h"
unsigned short len=0;
char buff[8];
void uart_init (void){
	RCC->APB1ENR |=RCC_APB1ENR_USART3EN;
	USART3->CR1 |=USART_CR1_RE;
	USART3->CR1 |=USART_CR1_RXNEIE;
	USART3->BRR = 1250UL ;
	
  NVIC_EnableIRQ(USART3_4_IRQn);
	NVIC_SetPriority(USART3_4_IRQn,0);
	
	USART3->CR1 |=USART_CR1_UE;
}
void USART3_4_IRQHandler (void){	
    buff[len]= (char)USART3->RDR;

    	
	
  if((char)USART3->RDR == 0x0D){
    flag_receive_complete = 1;
		len =0;
	}
	else{
	flag_receive_complete=0;
		len=(len+1)%8;
	}
	 
  }









