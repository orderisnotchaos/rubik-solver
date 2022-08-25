/*
 * 7_Seg.c
 *
 *  Created on: 8 de ago. de 2017
 *      Author: diego
 */

#include "FW_7seg.h"

uint8_t Tabla[11]={0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x67, 0x80};

void barridoDisplay(void)
{
	static uint8_t digito =0;
	uint8_t aux;

	SetPIN(digito0,0);
	SetPIN(digito1,0);
	SetPIN(digito2,0);
	SetPIN(digito3,0);

	if(digito <2)
	    aux=Tabla[g_mSeg[digito]];
	if(digito == 2 || digito == 3)
		aux=Tabla[g_Seg[digito-2]];

	SetPIN(segmento_a, (aux >> 0) & 0x01);
	SetPIN(segmento_b, (aux >> 1) & 0x01);
	SetPIN(segmento_c, (aux >> 2) & 0x01);
	SetPIN(segmento_d, (aux >> 3) & 0x01);
	SetPIN(segmento_e, (aux >> 4) & 0x01);
	SetPIN(segmento_f, (aux >> 5) & 0x01);
	SetPIN(segmento_g, (aux >> 6) & 0x01);
	SetPIN(segmento_dp, 0);
	if(digito == 2 || digito == 4)
	{
		aux = aux | 0x01;
		SetPIN(segmento_dp, 1);
	}

	switch (digito)
	{
		case 0:
			SetPIN(digito0,1);
			break;
		case 1:
			SetPIN(digito1,1);
			break;
		case 2:
			SetPIN(digito2,1);
			break;
		case 3:
			SetPIN(digito3,1);
			break;
	}

	digito++;
	digito = digito%4;
}
