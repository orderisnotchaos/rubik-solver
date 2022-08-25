/*
 * PR_Crono.h
 *
 *  Created on: Nov 3, 2017
 *      Author: fede
 */

#ifndef PR_CRONO_H_
#define PR_CRONO_H_
#include "PR_7seg.h"
#include "RegsLPC17xx.h"

extern uint8_t g_mSeg[2];
extern uint8_t g_Seg[2];
volatile extern uint16_t g_mSeg_flag;
extern uint8_t g_Seg_flag;

void StarCrono(void);
void StopCrono(void);
void Cronometro(void);

#endif /* PR_CRONO_H_ */
