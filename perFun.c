#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "estruc.h"

void *
perFun (void * arg)
{

	perso_ts *perso = (perso_ts *)arg;
	
	
	/*printf("\n");
	
	printf("Thread persona %d creado\n", perso->id);
	printf("Persona en piso: %d\n" , perso->p_act);
	printf("Persona ira a: %d\n" , perso->p_des);
	printf("Persona estado: %d\n" , perso->estado);
	printf("Persona tiempo en piso: %d\n" , perso->remTime);
	
	printf("\n");
	*/
	
	//-----------------
	while(TRUE){
	
	//generando nuevo piso rand.
	int r = rand()%5 + 1;
	//generando nuevo tiempo rand.
	int s = rand()%10 + 1;
	
	//mientras no se acabe el tiempo bajar tiempo		
	usleep(100000);
		//printf("--bajando T de: %d\n" , perso->remTime);
	perso->remTime = perso->remTime - 1;
		//printf("--A: %d\n" , perso->remTime);
		
		//si tiempo acaba moverse y elegir otro piso
	if(perso->remTime == 0){
		
		
		perso->estado = MOVIENDOSE;
		
		//printf("T EN 0: \n");
		//printf("Per %d en: %d\n" ,perso->id, perso->p_act);
		while(r == perso->p_act){
			r = rand()%5 + 1;
		}
		
		perso->p_des = r;
		//printf("Per %d red a: %d\n" ,perso->id, perso->p_act);
		
		//volver a pensar
		perso->estado = PENSANDO;
		
		perso->remTime = s;
		//printf("--Tiempo ahora: %d\n" , (perso->remTime) ) ;
		
	
		}
	//------------------
	}
	

	return NULL;
}