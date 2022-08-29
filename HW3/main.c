#include "rcc.h"
#include "uart.h"
char ledon[8]="led on\r";
char ledoff[8]="led off\r";

int stringCompare(char str1[], char str2[]);

unsigned char flag_receive_complete;

 void led_on (void){
	GPIOA->BSRR |=GPIO_BSRR_BS_5;
} 

void led_off (void){
 GPIOA->BSRR |=GPIO_BSRR_BR_5;
}
int main(void){
	rcc_init();
	RCC->AHBENR |=RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |=RCC_AHBENR_GPIOCEN;
	GPIOA->MODER |=GPIO_MODER_MODER5_0;
	GPIOC->MODER |=GPIO_MODER_MODER4_1 | GPIO_MODER_MODER5_1;
	GPIOC->AFR[0] |=0x00110000;
	uart_init();
	

	while(1){
		if(flag_receive_complete == 1){
    
   if (stringCompare(ledon, buff)){ 
     led_on();
		 for( len = 0; len < sizeof (buff); len++){
         buff[len] = 0;
			}
	     len=0;		
		}
	 if (stringCompare(ledoff, buff)){ 
     led_off();
		 for( len = 0; len < sizeof (buff); len++){
         buff[len] = 0;
			}
	     len=0;		
		}

	flag_receive_complete = 0;
	}
}
}
 int stringCompare(char str1[], char str2[]){ 
  int i = 0, flag = 0; 
  while(str1[i] != '\r' && str2[i] != '\r'){ 
   if(str1[i] != str2[i]){ 
   flag = 1; 
   break; 
   } 
   i++; 
   } 
   if(flag == 0 && str1[i] == '\r' && str2[i] == '\r') 
	 return 1; 
    else 
    return 0; 
    } 
