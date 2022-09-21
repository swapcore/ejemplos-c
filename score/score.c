/*
	Resultados de calificaciones
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

#include "score.h"

// obtener información de calificaciones
SCOREINFO * GetScoreInfo(double *list, size_t elems)
{
	SCOREINFO * results;
	int listvalid=1;
	size_t a;
	
	// revisión de parametros
	if(!(list&&elems>2)) {
		return NULL;
	}
	
	/* Reservar memoria para guardar los resultados
	 * de la lista de calificaciones */
	if(!(results=malloc(sizeof(SCOREINFO)))) {
		return NULL;
	}
	memset(results,0,sizeof(SCOREINFO));
	
	/* Verificar si la calificación correponde al
	 * rango 0.00 a 10.00 */
	for(a=0; a<elems; a++) {
		if(!(list[a]>=MIN_CUALIFICATION&&
			list[a]<=MAX_CUALIFICATION))
		{
			listvalid=0;
			break;
		}
	}
	if(!listvalid) {
		// lista con valores invalidos
		free(results);
		return NULL;
	}
	
	/* Aplicar truco para encontra la calificación
	 * mas baja de la lista :) */
	results->lowrating = MAX_CUALIFICATION;
	
	/* leer cada calificación de la lista en busca de
	 * la información requerida */
	for(a=0; a<elems; a++) {
		/* (1) Contar las calificaciones aprobatorias
		 * y reprobatorias de la lista */
		if(list[a]>=MIN_APPROVING_CUALIFICATION) {
			results->approved++;
		}
		else {
			results->failed++;
		}
		
		// (2) Encontrar la calificación mas alta
		if(results->highrating < list[a]) {
			results->highrating = list[a];
		}
		
		// (3) Encontrar la calificación mas baja
		if(results->lowrating > list[a]) {
			results->lowrating = list[a];
		}
		
		/* Sumar las calificaciones de lo lista. El
		 * primer paso para obtener su promedio */
		results->average += list[a];
	}
	
	// (4) obtener promedio
	results->average /= (double)(elems);
	
	return results;
}
