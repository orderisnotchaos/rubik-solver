#include "PR_Crono.h"

uint8_t g_mSeg[2] = {0, 0};
uint8_t g_Seg[2] = {0, 0};
volatile uint16_t g_mSeg_flag=0;
uint8_t g_Seg_flag=0;
uint8_t g_crono_flag=0;

void StarCrono(void){
	g_crono_flag=1;
}

void Cronometro(void){

	Display_Number(g_mSeg_flag, MILI);
	Display_Number(g_Seg_flag, SEGUNDOS);
	if(g_crono_flag){
		if(g_mSeg_flag == 1000)
		{
			g_Seg_flag ++;
			g_mSeg_flag = 0;
		}
		if(g_Seg_flag  == 60)
		{
			g_Seg_flag  = 0;
		}
		g_mSeg_flag++;
	}
}

void StopCrono(void){

	g_crono_flag=0;

}

void ResetCrono(void){
	g_mSeg_flag=0;
	g_Seg_flag=0;
	g_mSeg[0]=0;
	g_mSeg[1]=0;
	g_Seg[0]=0;
	g_Seg[1]=0;

}
