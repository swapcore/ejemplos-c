/*
	Serie de fibonacci
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

#include "fibonacci.h"

// obtener serie de fibonacci
FIBONACCISTRUCT * GetFibonacci(int elems)
{
	FIBONACCISTRUCT * fibonacci;
	size_t len;
	int a;
	
	// verificación de parametros
	if(elems<2||elems>LIMIT_FIBONACCI_NUMBERS) {
		return NULL;
	}
	
	// reservar memoria para la serie de fibonacci
	len = sizeof(FIBONACCISTRUCT)+((elems-2)*sizeof(uint32_t));
	if(!(fibonacci=malloc(len))) {
		return NULL;
	}
	
	fibonacci->nbelems = elems;
	
	// declarar valores iniciales de la serie de fibonacci
	fibonacci->elements[0] = 0;
	fibonacci->elements[1] = 1;
	
	if(elems==2) {
		return fibonacci;
	}
	
	/* Crear serie de fibonacci con los
	 * elementos solicitados */
	for(a=2; a<elems; a++) {
		/* Agregar elemento resultante de la suma de
		 * los dos elementos anteriores en la serie
		 * de fibonacci */
		fibonacci->elements[a] =
			fibonacci->elements[a-1] +
			fibonacci->elements[a-2];
	}
	
	// agregar el ultimo valor de la serie de fibonacci
	fibonacci->lastvalue = fibonacci->elements[elems-1];
	
	return fibonacci;
}
