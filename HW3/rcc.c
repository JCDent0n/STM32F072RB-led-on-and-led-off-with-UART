#include "rcc.h"

void rcc_init (void){
 
	RCC->CR |=RCC_CR_HSION;
	while(!(RCC->CR & RCC_CR_HSIRDY))
  {
	__ASM("NOP");
	}

	RCC->CFGR &= ~RCC_CFGR_PLLSRC;

	RCC->CFGR |=RCC_CFGR_PLLSRC_HSI_PREDIV;

	RCC->CFGR2 |=RCC_CFGR2_PREDIV_DIV1;

	RCC->CFGR &= ~RCC_CFGR_PLLMUL;
	
	RCC->CFGR |=RCC_CFGR_PLLMUL6;

	
	
	RCC->CR |=RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY))
	{
	__ASM("NOP");
	
	}	
	
	RCC->CFGR |=RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL))
	{
		__ASM("NOP");
	}

	RCC->CFGR |=RCC_CFGR_HPRE_DIV2;
	RCC->CFGR |=RCC_CFGR_PPRE_DIV2;

}



