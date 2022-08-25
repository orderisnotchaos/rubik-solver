/*
 * PR_stepper.c
 *
 *  Created on: Aug 22, 2017
 *      Author: fede
 */

#include "PR_stepper.h"

volatile uint16_t g_motor1[4]={0};			//motor de movimiento lineal
volatile uint16_t g_motor2[4]={0};
volatile uint16_t g_motor3[4]={0};
volatile uint16_t g_motor4[4]={0};
volatile uint16_t g_motor5[4]={0};
volatile uint16_t g_motor6[4]={0};			//motor de movimiento lineal

void PR_motor(uint16_t motor, uint16_t sentido, uint16_t pasos)
{

	switch(motor)
	{
		case 1:
			if(g_motor1[3]==0)
			{
			g_motor1[1]=pasos;
			g_motor1[2]=sentido;
			g_motor1[3]=1;						//estado del motor   1 para no disponible ; 0 para disponible
			}
			break;

		case 2:
			if(g_motor2[3]==0)
			{
			g_motor2[1]=pasos;
			g_motor2[2]=sentido;
			g_motor2[3]=1;
			}
			break;

		case 3:
			if(g_motor3[3]==0)
			{
			g_motor3[1]=pasos;
			g_motor3[2]=sentido;
			g_motor3[3]=1;
			}
			break;

		case 4:
			if(g_motor4[3]==0)
			{
			g_motor4[1]=pasos;
			g_motor4[2]=sentido;
			g_motor4[3]=1;
			}
			break;

		case 5:
			if(g_motor5[3]==0)
			{
			g_motor5[1]=pasos;
			g_motor5[2]=sentido;
			g_motor5[3]=1;
			}
			break;

		case 6:
			if(g_motor6[3]==0)
			{
			g_motor6[1]=pasos;
			g_motor6[2]=sentido;
			g_motor6[3]=1;
			}
			break;
	}
}
