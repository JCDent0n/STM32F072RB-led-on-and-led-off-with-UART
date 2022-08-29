 #ifndef __UART_H
 #define __UART_H
 #include "stm32f0xx.h"
 
 extern unsigned char flag_receive_complete;
 extern unsigned short len;
 extern char buff[8];
 extern char ledon[8];
 extern char ledoff[8];
 void uart_init (void);
 void tx_init (void);
 void rx_init (void);
 void USART3_4_IRQHandler (void);
 void led_on (void);
 void led_off (void);


#endif
