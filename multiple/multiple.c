/*
	Multiplo de un numero
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

#include "multiple.h"

// obtener multiplos de un numero
int * ObtenerMultiplos(int num, int nbelems)
{
	int *lstnum, a;
	
	if(num<1) {
		/* "num" debe ser un numero entero positivo
		 * mayor que cero */
		return NULL;
	}
	
	if(nbelems<1) {
		return NULL;
	}
	
	// reservar espacio para la lista
	if(!(lstnum=calloc(nbelems,sizeof(int)))) {
		return NULL;	
	}
	
	// obtener multiplos
	for(a=1; a<=nbelems; a++) {
		lstnum[a-1]=a*num;
	}
	
	return lstnum;
}
