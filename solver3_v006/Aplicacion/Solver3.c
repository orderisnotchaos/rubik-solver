/*
===============================================================================
 Name        : Solver3.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "cr_section_macros.h"
#include "Solver3.h"

uint8_t g_vector[128];


int main(void)
{

	Inicializacion();

	//generador=	{'R','u','u','b','b','d','d','R','B','f','L','D','L','r','u','L','U','R','F','d','u','F','\0'};
	//solver=		{'f','d','b','l','F','R','l','F','D','f','U','r','F','R','B','D','R','B','L','b','\0'};
	//solver1=		{'U','R','d','L','F','u','R','B','U','U','b','R','B','u','l','F','U','L','u','d','B','\0'};
	//generador1=	{'b','D','U','l','u','f','L','U','b','r','B','u','u','b','r','U','f','l','D','r','u','\0'};

	uint8_t i=0,estado=INICIALIZAR;
    while(1)
    {
    	switch(estado)
    	{
    	case INICIALIZAR:
    		//prender rele de alimentacion de motores
    		//estado=FINALIZAR;
    		estado=DATOS;
    		//estado=RESOLVER;
    		break;
    	case ESCANEAR:
    		break;
    	case DATOS:
    		estado=comunication();
    		break;
    	case RESOLVER:
    		StarCrono();
    		if(estadoMotores()  == 0)								//si los motores estan libres
    		{
    			if(g_vector[i] == '\0')
    			{
    				estado=SOLTAR;
    				break;
    			}
    			else
    			{
    				if(g_vector[i]==g_vector[i+1])
    				{													//si tiene que dar media vuelta
    					if(Cube(g_vector[i],MEDIA_VUELTA)==1)
    						 i+=2;										//para saltear el movimiento repetido
    				}
    				else
    				{
    					 if(Cube(g_vector[i],CUARTO_VUELTA)==1)				//si tiene que dar un cuarto de vuelta
    					 	 estado=RELOCALIZAR;
    				}											//al dar un cuarto de vuelta debe relocalizar el brazo
    			}
    		}
    		//estado=DATOS;
    		break;
    	case RELOCALIZAR:
    		if(estadoMotores() == 0)								//si motores libres
    		{
    			if(relocate(g_vector[i]))
    			{
    				estado=RESOLVER;								//si relocalizo ,vuelvo al estado RESOLVER
    				i++;											//paso al siguiente movimiento
    			}
    		}
    		break;
    	case SOLTAR:
    		if(estadoMotores() == 0)								//si motores libres
    		{
    			//SoltarCubo();
    			StopCrono();
    			estado=FINALIZAR;
    		}
    		break;
    	case FINALIZAR:
    		//apago rele de alimentacion
    		break;
    	}

    }

    return 0 ;
}
