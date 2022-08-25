/*
 * FW_Stepper.c
 *
 *  Created on: Aug 11, 2017
 *      Author: fede
 */

#include "Solver3.h"


void FW_dirMotor(void){

	if(g_motor1[1])
			SetPIN(STEPPER1_DIR,g_motor1[2]);
	if(g_motor2[1])
			SetPIN(STEPPER2_DIR,g_motor2[2]);
	if(g_motor3[1])
			SetPIN(STEPPER3_DIR,g_motor3[2]);
	if(g_motor4[1])
			SetPIN(STEPPER4_DIR,g_motor4[2]);
	if(g_motor5[1])
			SetPIN(STEPPER5_DIR,g_motor5[2]);
	if(g_motor6[1])
			SetPIN(STEPPER6_DIR,g_motor6[2]);
}

void FW_motor(void)
{

	if(g_motor2[1]!=0 && g_motor2[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 6) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<6);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<6);					//lo cambio a estado HIGH
			g_motor2[1]--;						//descuento un paso
			if(g_motor2[1]==0)
				g_motor2[3]=0;
		}
	}
	if(g_motor3[1]!=0 && g_motor3[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 1) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<1);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<1);					//lo cambio a estado HIGH
			g_motor3[1]--;						//descuento un paso
			if(g_motor3[1]==0)
				g_motor3[3]=0;
		}
	}
	if(g_motor4[1]!=0 && g_motor4[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 17) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<17);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<17);					//lo cambio a estado HIGH
			g_motor4[1]--;						//descuento un paso
			if(g_motor4[1]==0)
				g_motor4[3]=0;
		}
	}
	if(g_motor5[1]!=0 && g_motor5[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 16) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<16);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<16);					//lo cambio a estado HIGH
			g_motor5[1]--;						//descuento un paso
			if(g_motor5[1]==0)
				g_motor5[3]=0;
		}
	}
}

void FW_motorLineal(void){

	if(g_motor1[1]!=0 && g_motor1[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 8) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<8);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<8);					//lo cambio a estado HIGH
			g_motor1[1]--;						//descuento un paso
			if(g_motor1[1]==0)
				g_motor1[3]=0;
		}
	}
	if(g_motor6[1]!=0 && g_motor6[3])							//solamente entra si hay pasos y si el motor esta en no disponible
	{
		if((GPIOs[5] >> 24) & 0x01)	 			//si el pin step esta en estado HIGH
			(GPIOs[7] |= 1<<24);					//lo pongo en estado LOW
		else
		{
			(GPIOs[6] |= 1<<24);					//lo cambio a estado HIGH
			g_motor6[1]--;						//descuento un paso
			if(g_motor6[1]==0)
				g_motor6[3]=0;
		}
	}
}
