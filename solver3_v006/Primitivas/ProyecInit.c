/*
 * ProyecInit.c
 *
 *  Created on: Jun 29, 2017
 *      Author: fede
 */
#include "Solver3.h"

/********************************************************************************
	\fn  void Inicializacion(void)
	\brief: Inicializacion de pines
	\details: Configura el oscilador interno e inicializa los pines de ebtradas/salidas
	\author:
 	\param 	void
	\return void
*/
void Inicializacion(void)
{
	//Inicalizo el oscilador interno del micro en 100MHz
	PLL_Init();
	//Configuro los puertos de entrada/salida de proposito general (GPIOs), como entrada o salida
	Pin_Init();
	UART_Init();

	Display_Init();

	Systick_Init(1000);		//velocidad motores de las caras   max 200

	TIMER0_Init(100,500);		//velocidad motores ejes x e y		max 500
}

/********************************************************************************
	\fn  void PLL_Init(void)
	\brief: Inicializacion del PLL
	\details: Habilita el oscilador externo como fuente de clock y configura el PLL0
			para generar un clock interno de 100MHz.
	\author:
 	\param 	void
	\return void
*/
void PLL_Init(void)
{
	SCS = 0x00000020;

	if (SCS & (1 << 5))               /* If Main Oscillator is enabled      */
		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	CCLKCFG = 0x00000003;      /* Setup Clock Divider                */

	PCLKSEL0 = 0x00000000;     /* Peripheral Clock Selection         */
	PCLKSEL1 = 0x00000000;

	CLKSRCSEL = 0x00000001;    /* Select Clock Source for PLL0       */

	PLL0CFG = 0x00050063;      /* configure PLL0                     */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	PLL0CON = 0x01;             /* PLL0 Enable                        */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	while (!(PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

	PLL0CON = 0x03;             /* PLL0 Enable & Connect              */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	while (!(PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */

	PLL1CFG = 0x00000023;
	PLL1FEED = 0xAA;
	PLL1FEED = 0x55;

	PLL1CON = 0x01;             /* PLL1 Enable                        */
	PLL1FEED = 0xAA;
	PLL1FEED = 0x55;

	while (!(PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

	PLL1CON = 0x03;             /* PLL1 Enable & Connect              */
	PLL1FEED = 0xAA;
	PLL1FEED = 0x55;

	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */

	PCONP = 0x042887DE;        /* Power Control for Peripherals      */

	CLKOUTCFG = 0x00000000;    /* Clock Output Configuration         */

	FLASHCFG  = (FLASHCFG & ~0x0000F000) | 0x00004000;
}

/********************************************************************************
	\fn  void Pin_Init(void)
	\brief: Inicializa los pines del microcontrolador conectados a entradas/salidas
	\author:
 	\param 	void
	\return void
*/
void Pin_Init(void){

SetPINSEL(STEPPER1_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER1_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER1_ENBL,PINSEL_GPIO);

SetPINSEL(STEPPER2_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER2_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER2_ENBL,PINSEL_GPIO);

SetPINSEL(STEPPER3_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER3_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER3_ENBL,PINSEL_GPIO);

SetPINSEL(STEPPER4_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER4_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER4_ENBL,PINSEL_GPIO);

SetPINSEL(STEPPER5_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER5_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER5_ENBL,PINSEL_GPIO);

SetPINSEL(STEPPER6_DIR,PINSEL_GPIO);
SetPINSEL(STEPPER6_STEP,PINSEL_GPIO);
SetPINSEL(STEPPER6_ENBL,PINSEL_GPIO);

SetPINSEL(RESET_ESP,PINSEL_GPIO);

SetDIR(STEPPER1_DIR,GPIO_OUTPUT);
SetDIR(STEPPER1_STEP,GPIO_OUTPUT);
SetDIR(STEPPER1_ENBL,GPIO_OUTPUT);

SetDIR(STEPPER2_DIR,GPIO_OUTPUT);
SetDIR(STEPPER2_STEP,GPIO_OUTPUT);
SetDIR(STEPPER2_ENBL,GPIO_OUTPUT);

SetDIR(STEPPER3_DIR,GPIO_OUTPUT);
SetDIR(STEPPER3_STEP,GPIO_OUTPUT);
SetDIR(STEPPER3_ENBL,GPIO_OUTPUT);

SetDIR(STEPPER4_DIR,GPIO_OUTPUT);
SetDIR(STEPPER4_STEP,GPIO_OUTPUT);
SetDIR(STEPPER4_ENBL,GPIO_OUTPUT);

SetDIR(STEPPER5_DIR,GPIO_OUTPUT);
SetDIR(STEPPER5_STEP,GPIO_OUTPUT);
SetDIR(STEPPER5_ENBL,GPIO_OUTPUT);

SetDIR(STEPPER6_DIR,GPIO_OUTPUT);
SetDIR(STEPPER6_STEP,GPIO_OUTPUT);
SetDIR(STEPPER6_ENBL,GPIO_OUTPUT);

SetDIR(RESET_ESP,GPIO_OUTPUT);

SetPIN(STEPPER1_DIR,0);
SetPIN(STEPPER2_DIR,0);
SetPIN(STEPPER3_DIR,0);
SetPIN(STEPPER4_DIR,0);
SetPIN(STEPPER5_DIR,0);
SetPIN(STEPPER6_DIR,0);

SetPIN(STEPPER1_STEP,0);
SetPIN(STEPPER2_STEP,0);
SetPIN(STEPPER3_STEP,0);
SetPIN(STEPPER4_STEP,0);
SetPIN(STEPPER5_STEP,0);
SetPIN(STEPPER6_STEP,0);

SetPIN(STEPPER1_ENBL,1);
SetPIN(STEPPER2_ENBL,1);
SetPIN(STEPPER3_ENBL,1);
SetPIN(STEPPER4_ENBL,1);
SetPIN(STEPPER5_ENBL,1);
SetPIN(STEPPER6_ENBL,1);

SetPIN(RESET_ESP,OFF);
}

void Display_Init(void){

	SetPINSEL(digito0, PINSEL_GPIO);
	SetPINSEL(digito1, PINSEL_GPIO);
	SetPINSEL(digito2, PINSEL_GPIO);
	SetPINSEL(digito3, PINSEL_GPIO);

	SetPINSEL(segmento_a, PINSEL_GPIO);
	SetPINSEL(segmento_b, PINSEL_GPIO);
	SetPINSEL(segmento_c, PINSEL_GPIO);
	SetPINSEL(segmento_d, PINSEL_GPIO);
	SetPINSEL(segmento_e, PINSEL_GPIO);
	SetPINSEL(segmento_f, PINSEL_GPIO);

	SetDIR(digito0, GPIO_OUTPUT);
	SetDIR(digito1, GPIO_OUTPUT);
	SetDIR(digito2, GPIO_OUTPUT);
	SetDIR(digito3, GPIO_OUTPUT);

	SetDIR(segmento_a, GPIO_OUTPUT);
	SetDIR(segmento_b, GPIO_OUTPUT);
	SetDIR(segmento_c, GPIO_OUTPUT);
	SetDIR(segmento_d, GPIO_OUTPUT);
	SetDIR(segmento_e, GPIO_OUTPUT);
	SetDIR(segmento_f, GPIO_OUTPUT);
	SetDIR(segmento_g, GPIO_OUTPUT);
}
