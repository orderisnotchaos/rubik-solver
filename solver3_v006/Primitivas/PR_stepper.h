/*
 * PR_stepper.h
 *
 *  Created on: Aug 22, 2017
 *      Author: fede
 */

//#include "Solver3.h"
#include "RegsLPC17xx.h"

volatile extern uint16_t g_motor1[4];
volatile extern uint16_t g_motor2[4];
volatile extern uint16_t g_motor3[4];
volatile extern uint16_t g_motor4[4];
volatile extern uint16_t g_motor5[4];
volatile extern uint16_t g_motor6[4];

void PR_motor(uint16_t motor, uint16_t sentido, uint16_t pasos);
