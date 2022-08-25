/*
 * PR_7seg.c
 *
 *  Created on: Oct 27, 2017
 *      Author: fede
 */
#include "PR_7seg.h"


void Display_Number(uint16_t valor,uint8_t aux)
{
	switch(aux)
	{
	case MILI:
		g_mSeg[0]=(valor%100)/10;
		g_mSeg[1]=valor/100;
		break;
	case SEGUNDOS:
		g_Seg[0]=valor%10;
		g_Seg[1]=valor/10;
		break;
	}
}
