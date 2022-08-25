/*
 * PR_cube.h
 *
 *  Created on: Aug 24, 2017
 *      Author: fede
 */

#ifndef PR_CUBE_H_
#define PR_CUBE_H_

#include "Solver3.h"

#define CARA_R		(uint8_t) 82
#define CARA_L		(uint8_t) 76
#define CARA_B		(uint8_t) 66
#define CARA_F		(uint8_t) 70
#define CARA_U		(uint8_t) 85
#define CARA_D		(uint8_t) 68

#define MOV_LINEAL	200


void rotar(uint8_t cara);
uint8_t Cube(uint8_t buffer,uint16_t cant);
uint16_t solverVector(uint8_t *vector);
uint8_t relocate(uint8_t caracter);
void SoltarCubo(void);
uint8_t estadoMotores(void);
uint8_t carasMotores(uint8_t);


#endif /* PR_CUBE_H_ */
