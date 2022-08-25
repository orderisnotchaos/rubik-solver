/*
 * ProyecInit.h
 *
 *  Created on: Jun 29, 2017
 *      Author: fede
 */
#include "Solver3.h"

void Inicializacion(void);
void PLL_Init(void);
void Pin_Init(void);
void Display_Init(void);

#define		STEPPER1_DIR	PORT0,9
#define		STEPPER2_DIR	PORT0,7
#define		STEPPER3_DIR	PORT0,0
#define		STEPPER4_DIR	PORT0,18
#define		STEPPER5_DIR	PORT0,15
#define		STEPPER6_DIR	PORT0,23

#define		STEPPER1_STEP	PORT0,8
#define		STEPPER2_STEP	PORT0,6
#define		STEPPER3_STEP	PORT0,1
#define		STEPPER4_STEP	PORT0,17
#define		STEPPER5_STEP	PORT0,16
#define		STEPPER6_STEP	PORT0,24

#define 	STEPPER1_ENBL	PORT2,6
#define 	STEPPER2_ENBL	PORT2,7
#define 	STEPPER3_ENBL	PORT2,8
#define 	STEPPER4_ENBL	PORT2,10
#define 	STEPPER5_ENBL	PORT2,11
#define 	STEPPER6_ENBL	PORT2,12

#define 	RESET_ESP		PORT0,21

#define		digito0	    	PORT4,29			//!< Display 7 Segmentos
#define		digito1			PORT3,25
#define		digito2			PORT1,27
#define		digito3			PORT1,24

#define		segmento_a		PORT1,21
#define		segmento_b		PORT1,18
#define		segmento_c		PORT0,19
#define		segmento_d		PORT3,26
#define		segmento_e		PORT1,28
#define		segmento_f		PORT1,25
#define		segmento_g		PORT1,22
#define		segmento_dp		PORT1,19

#define 	DIR_CW			1
#define 	DIR_CCW			0

#define 	ON 				1
#define 	OFF 			0


