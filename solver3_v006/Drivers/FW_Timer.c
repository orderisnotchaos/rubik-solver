/*
 * FW_Timer.c
 *
 *  Created on: 15/08/2013
 *      Author: Pablo
 */

#include "FW_Timer.h"
#include "FW_GPIO.h"
#include "FW_Stepper.h"


void TIMER0_Init(uint32_t us_time_mach_0, uint32_t us_time_mach_1)
{
	PCONP |= 1 << 1; 				// Habilitar Timer 0

	PCLKSEL0 &= ~(0x03 << 2);		// PCLK = CCLK/4

	T0MR0 = 25*us_time_mach_0;		// Configuro el tiempo del match 0

	//T0MR1 = 25*us_time_mach_1;		// Configuro el tiempo del match 1

	T0MCR = 3;					// Match 0 y 1 resetea e interrumpe

	T0PR = 0;						// Prescaler en 0

	T0CTCR = 0;						// Funcionamiento como timer

	T0TCR = 0x02;					// Apago y reseteo el timer
	T0TCR = 0x01;					// Enciendo el timer

	ISER0 |= 1<<1; 					// Habilito interrupcion del Timer0 en el vector de interrupciones.
}

void TIMER0_IRQHandler(void)
{
	static uint8_t	i=0,j=0;
	FW_dirMotor();
    if(T0IR & 0x01)					// Si interrumpio match 0
    {
    	T0IR |= 0x01; 				// Borro flag del Match 0
    	i++;
    	j++;
    	if(i==2){
    		FW_motor();
    		i=0;
    	}
    	if(j==5){
    		FW_motorLineal();
    		j=0;
    	}
    }

}

