/*
 * PR_cube.c
 *
 *  Created on: Aug 24, 2017
 *      Author: fede
 */

#include "PR_cube.h"

//asignacion de caras a los motores
uint8_t stepper2=CARA_R;
uint8_t stepper3=CARA_F;
uint8_t stepper4=CARA_L;
uint8_t stepper5=CARA_B;

//motor 1 agarra motores 2 y 4
//motor 6 agarra motores 3 y 5


void rotar(uint8_t cara)
{
	static int8_t estado=0;

		switch(estado){
			case 0:													//separo motores 2 y 4
				PR_motor(1,DIR_CW,MOV_LINEAL);
				break;
			case 1:													//giro el cubo
				PR_motor(3,DIR_CW,CUARTO_VUELTA);
				PR_motor(5,DIR_CCW,CUARTO_VUELTA);
				break;
			case 2:													// vuelvo a juntar motores 2 y 4
				PR_motor(1,DIR_CCW,MOV_LINEAL);
				break;
			case 3:													//separo motores 3 y 5
				PR_motor(6,DIR_CW,MOV_LINEAL);
				break;
			case 4:													//acomodo los motores 3 y 5
				PR_motor(3,DIR_CCW,CUARTO_VUELTA);
				PR_motor(5,DIR_CW,CUARTO_VUELTA);
				break;
			case 5:													//junto los motores 3 y 5
				PR_motor(6,DIR_CCW,MOV_LINEAL);
				break;
			case 6:
				if(stepper2==CARA_R)
				{
					stepper2=CARA_U;
					stepper4=CARA_D;
				}
				else if(stepper2==CARA_U)
				{
					stepper2=CARA_L;
					stepper4=CARA_R;
				 }
				else if(stepper2==CARA_L)
				{
					stepper2=CARA_D;
					stepper4=CARA_U;
				}
				else if(stepper2==CARA_D)
				{
					stepper2=CARA_R;
					stepper4=CARA_L;
				}
				estado=-1;
				break;
		}
	estado++;
}

uint8_t Cube(uint8_t buffer,uint16_t cant)//recibe el caracter de movimiento y la cantidad de pasos
{
	uint8_t flagaux=0;
	switch(buffer)
	{
	case 'R':
		if(stepper2!=CARA_R && stepper4!=CARA_R)
			rotar(CARA_R);
		if(stepper2==CARA_R){
			PR_motor(2,DIR_CW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_R){
			PR_motor(4,DIR_CW,cant);
			flagaux=1;
		}
		break;
	case 'r':
		if(stepper2!=CARA_R && stepper4!=CARA_R)
			rotar(CARA_R);
		if(stepper2==CARA_R){
			PR_motor(2,DIR_CCW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_R){
			PR_motor(4,DIR_CCW,cant);
			flagaux=1;
		}
		break;
	case 'U':
		if(stepper2!=CARA_U && stepper4!=CARA_U)
			rotar(CARA_U);
		if(stepper2==CARA_U){
			PR_motor(2,DIR_CW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_U){
			PR_motor(4,DIR_CW,cant);
			flagaux=1;
		}
		break;
	case 'u':
		if(stepper2!=CARA_U && stepper4!=CARA_U)
			rotar(CARA_U);
		if(stepper2==CARA_U){
			PR_motor(2,DIR_CCW,cant);
			flagaux=1;
		}
		else
			if(stepper4==CARA_U){
			PR_motor(4,DIR_CCW,cant);
			flagaux=1;
		}
		break;
	case 'F':
		PR_motor(3,DIR_CW,cant);
		flagaux=1;
		break;
	case 'f':
		PR_motor(3,DIR_CCW,cant);
		flagaux=1;
		break;
	case 'L':
		if(stepper2!=CARA_L && stepper4!=CARA_L)
			rotar(CARA_L);
		if(stepper2==CARA_L){
			PR_motor(2,DIR_CW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_L){
			PR_motor(4,DIR_CW,cant);
			flagaux=1;
		}
		break;
	case 'l':
		if(stepper2!=CARA_L && stepper4!=CARA_L)
			rotar(CARA_L);
		if(stepper2==CARA_L){
			PR_motor(2,DIR_CCW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_L){
			PR_motor(4,DIR_CCW,cant);
			flagaux=1;
		}
		break;
	case 'D':
		if(stepper2!=CARA_D && stepper4!=CARA_D)
			rotar(CARA_D);
		if(stepper2==CARA_D){
			PR_motor(2,DIR_CW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_D){
			PR_motor(4,DIR_CW,cant);
			flagaux=1;
		}
		break;
	case 'd':
		if(stepper2!=CARA_D && stepper4!=CARA_D)
			rotar(CARA_D);
		if(stepper2==CARA_D){
			PR_motor(2,DIR_CCW,cant);
			flagaux=1;
		}
		else if(stepper4==CARA_D){
			PR_motor(4,DIR_CCW,cant);
			flagaux=1;
		}
		break;
	case 'B':
		PR_motor(5,DIR_CW,cant);
		flagaux=1;
		break;
	case 'b':
		PR_motor(5,DIR_CCW,cant);
		flagaux=1;
		break;
	case 'X'://separa
		PR_motor(1,DIR_CW,cant);
		break;
	case 'x'://junta
		PR_motor(1,DIR_CCW,cant);
		break;
	case 'Y'://separa
		PR_motor(6,DIR_CW,cant);
		break;
	case 'y'://junta
		PR_motor(6,DIR_CCW,cant);
		break;
	}
	return flagaux;
}

uint16_t solverVector(uint8_t *vector)
{
	static uint8_t i=0;
	uint16_t aux=CUARTO_VUELTA;
	if(vector[i+1]!='\0'){
		if(vector[i]==vector[i+1])	//se fija si el siguiente movimiento es igual
		{
			aux=MEDIA_VUELTA;
			i++;					//saltea la posicion del repetido
		}
		i++;						//pasa a la siguiente posicion
	}
	return aux;						//retorna la cantidad de pasos
}

uint8_t relocate(uint8_t caracter)
{
	static int estado=0;
	uint8_t flag=0;
	switch (estado)
	{
		case 0:													//separo brazos
			if((stepper2 == caracter) || (stepper2 == caracter-32) || (stepper4 == caracter) || (stepper4 == caracter-32))
				Cube('X',MOV_LINEAL);
			else if((stepper3 == caracter) || (stepper3 == caracter-32) || (stepper5 == caracter) || (stepper5 == caracter-32))
				Cube('Y',MOV_LINEAL);
			break;
		case 1:													//gira al reves
			if(caracter >= 65 && caracter <= 90)				//si el caracter esta entre las mayusculas
				Cube((caracter+32),CUARTO_VUELTA);
			else if(caracter >= 97 && caracter <= 122)			//si el caracter esta entre las minusculas
				Cube((caracter-32),CUARTO_VUELTA);
			break;
		case 2:													//junta brazos
			if((stepper2 == caracter) || (stepper2 == caracter-32) || (stepper4 == caracter) || (stepper4 == caracter-32))
				Cube('x',MOV_LINEAL);
			else if((stepper3 == caracter) || (stepper3 == caracter-32) || (stepper5 == caracter) || (stepper5 == caracter-32))
				Cube('y',MOV_LINEAL);
			flag=1;
			estado=-1;											//menos uno para que setee en cero al final de la funcion y poder reutilizarla
			break;
	}
	estado++;													//cambia de estado
	return flag;													//retorna 1 si relocalizo y 0 si no lo hizo
}

void SoltarCubo(void)
{
	Cube('X',300);									//separa brazos del eje x
	Cube('Y',300);									//separa brazos del eje y
}

uint8_t estadoMotores(void){

	uint8_t aux;

	if(g_motor1[3]==0 && g_motor2[3]==0 && g_motor3[3]==0 && g_motor4[3]==0 && g_motor5[3]==0 && g_motor6[3]==0)
		aux=0;
	else
		aux=1;

	return aux;
}

uint8_t carasMotores(uint8_t cara){
	uint8_t aux;
	if(stepper2==cara || stepper2==cara-32 || stepper3==cara || stepper3==cara || stepper4==cara-32 || stepper4==cara || stepper5==cara || stepper5==cara-32)
		aux=1;
	else
		aux=0;
	return aux;
}
