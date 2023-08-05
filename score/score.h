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

#ifndef _SCORE_H_
#define _SCORE_H_

#include <stdlib.h>
#include <memory.h>

#define MIN_CUALIFICATION   0.00
#define MAX_CUALIFICATION   10.00

#define MIN_APPROVING_CUALIFICATION   6.00

typedef struct TagScoreInfo {
	size_t approved;     // aprobados
	size_t failed;       // reprobados
	double average;      // promedio
	double highrating;   // calificacion mas alta
	double lowrating;    // calificaion mas baja
}SCOREINFO;

SCOREINFO * GetScoreInfo(double *list, size_t elems);

#endif
