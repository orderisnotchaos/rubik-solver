/*
 * PR_string.c
 *
 *  Created on: Nov 2, 2017
 *      Author: fede
 */

#include "PR_string.h"

uint8_t comunication(void){

	uint8_t vectorData[100],len;
	static uint8_t aux=1,estado1=1,flag=2;
	uint8_t this[128];

	switch(estado1)
	{
	case INITIAL:
		//activar pin de reset wifi
		//SetPIN(RESET_ESP, OFF);
		if(flag==1){
			SetPIN(RESET_ESP, ON);
			strcpy((char*)vectorData,"AT+RST\r\n");
			len=strlen((char*)vectorData);
			//Serial_Send(vectorData,len);
			flag=2;
		}
		//comprobar si llego el ready y WIFI CONNECTED
		if(strstr((char*)g_rxBuffer+180,"WIFI CONNECTED")){
			if(aux){
				strcpy((char*)vectorData,"AT+CIPMUX=0\r\n");
				len=strlen((char*)vectorData);
				Serial_Send(vectorData,len);
				aux=0;
			}
			if(strstr((char*)g_rxBuffer+200,"OK")){
				estado1=CONNECT;
				aux=1;
			}
		}
		break;
	case CONNECT:
		if(aux){
			strcpy((char*)vectorData,"AT+CIPSTART=\"TCP\",\"192.168.43.162\",1563\r\n ");
			len=strlen((char*)vectorData);
			Serial_Send(vectorData,len);
			//Serial_Send(vectorData,len);
			aux=0;
		}
		//comprobar si se conecto al servidor
		if(strstr((char*)g_rxBuffer,"CONNECT FAIL")){
			//Serial_Send(vectorData,len);
		}
		if(strstr((char*)g_rxBuffer,"ALREADY CONNECTED")){
			estado1=CHECK;
			aux=1;
		}
		break;
	case ANALYZE:
		if(strstr((char*)g_rxBuffer,"solver:") && strstr((char*)g_rxBuffer,"#")){
			strcpy((char*)this,strstr((char*)g_rxBuffer,"solver:")+7);
			strcpy(strstr((char*)this,"#"),"\0");
			strcpy((char*)g_vector,(char*)this);
			flag=3;
		}
		break;
	case CHECK:
		strcpy((char*)vectorData,"AT+CIPSEND=9\r\n ");
		len=strlen((char*)vectorData);
		Serial_Send(vectorData,len);
		strcpy((char*)vectorData,"CONECTADO\r\n ");
		len=strlen((char*)vectorData);
		Serial_Send(vectorData,len);
		estado1=ANALYZE;
		break;
	}
	return flag;
}
