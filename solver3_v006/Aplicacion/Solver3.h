/*
 * Solver3.h
 *
 *  Created on: 2 de set. de 2017
 *      Author: diego
 */

#ifndef SOLVER3_H_
#define SOLVER3_H_

//#include "FW_Stepper.h"
#include "RegsLPC17xx.h"
#include "ProyecInit.h"
#include "PR_stepper.h"
#include "FW_Systick.h"
#include "FW_GPIO.h"
#include "FW_Timer.h"
#include "PR_Crono.h"
#include "PR_cube.h"
#include "FW_7seg.h"
#include "PR_Serial.h"
#include "PR_string.h"

#define MEDIA_VUELTA 		400
#define CUARTO_VUELTA 		200

//ESTADOS
#define INICIALIZAR		0
#define ESCANEAR		1
#define DATOS			2
#define RESOLVER		3
#define RELOCALIZAR		4
#define	SOLTAR			5
#define FINALIZAR		6
#define INTERUUPCION	255

extern uint8_t g_vector[128];

#endif /* SOLVER3_H_ */
