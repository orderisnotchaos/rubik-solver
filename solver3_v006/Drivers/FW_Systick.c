/**
 	\file FW_Timertick.c
 	\brief Drivers del systick
 	\details Barrido de displays y teclados, entradas, lcd y timers
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "Solver3.h"

void Systick_Init(uint32_t useg)
{
	uint32_t value;

	value = useg * 100 - 1;

	STRELOAD = value;
	STCURR = 0;
	STCTRL = 0x00000007;
}

void SysTick_Handler(void)

{
	Cronometro();
	barridoDisplay();

}

