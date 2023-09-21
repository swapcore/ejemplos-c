/*
	Resultados de calificaciones (Ejemplo de uso)
	Copyright (c) 2022 Oscar Elías
	
	This file is part of Ejemplos C.
	
	Ejemplos C is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published
	by the Free Software Foundation, either version 3 of the License,
	or (at your option) any later version.
	
	Ejemplos C is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of 
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with Ejemplos C. If not, see 
	<https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../score/score.h"

int main(int argc, char ** argv)
{
    SCOREINFO *eval;
    double *values;
	int a;

	printf("Resultados de calificaciones\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

	if(argc<2) {
		printf("Uso: score <valor_1> <valor_2> ...\n");
		return 0;
	}

    if(!(values=calloc(argc-1,sizeof(double)))) {
        return 0;
    }

	// obtener valores del usuario
	for(a=0; a<argc-1; a++) {
		values[a] = atof(argv[a+1]);
	}

	if(!(eval=GetScoreInfo(values,argc-1))) {
		printf("ERROR: Imposible obtener resultados\n");
		return 0;
	}

	printf(
		"Informacion de calificaciones\n"
		"========================================\n"
		"   Aprobados: %i\n"
		"   Reprobados: %i\n"
		"   Promedio general: %.2f\n"
		"   Calificacion mas alta: %.2f\n"
		"   Calificacion mas baja: %.2f\n",
		eval->approved,
		eval->failed,
		eval->average,
		eval->highrating,
		eval->lowrating);
	
	free(eval);
	free(values);

	return 0;
}