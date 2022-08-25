/**
 	\file FW_serie.c
 	\brief Drivers de comunicacion serie
 	\details
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "FW_UART.h"
#include "FW_GPIO.h"
#include "PR_Serial.h"
/*
#define U0FDR ( (__RW uint32_t *) 0x4000C028UL )
#define DIVADDVAL			U0FDR[0]
#define MULVAL				U0FDR[4]
*/
void UART_Init(void)
{
	//1.- Registro PCONP - bit 3 en 1 prende la UART0:
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea 25MHz:
	PCLKSEL0 |= (0x02<<6);
	//3.- Registro U0LCR - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x03;
	U0LCR = 0x083;
	//4.- Registros U0DLL y U0DLM - calculo el divisor para el baud rate:
	U0DLM = 0;
	U0DLL = 27;
	//5.- Registros PINSEL - habilitan las funciones especiales de los pines:
	SetPINSEL(0,2,PINSEL_FUNC1);
	SetPINSEL(0,3,PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x03;
	ISER0 |= (1<<5);
}

uint8_t UART_ReceiveByte(void)
{
	return U0RBR;
}

void UART_SendByte(uint8_t byte)
{
	U0THR = byte;
}

void UART0_IRQHandler(void)
{
	uint8_t iir;
	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;
		if ( iir & 0x02 ) //THRE
		{
			Serial_TxIntHandler();
		}
		if ( iir & 0x04 ) //Data ready
		{
			Serial_RxIntHandler();
		}
	}
	while(!(iir & 0x01)); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}
