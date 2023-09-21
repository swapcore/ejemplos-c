/*
	Calculo de factorial
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

#include "factorial.h"

// obtener factorial de un numero
uint32_t GetFactorial(uint32_t value)
{
	/* Esta función no obtendra factoriales mayores a 12! ya que
	 * el numero resultante sería demasiado grande para ser
	 * almacenado en una variable entera de 32 bits y ocacionaría
	 * un desbordamiento de enteros. */
	uint32_t factorial=1;
	uint32_t a;
	
	if(!(value>=0&&value<=MAX_FACTORIAL)) {
		// valor fuera del rango
		return 0;
	}
	
	if(value==0) {
		// retornar 0!
		return 1;
	}

	// obtener factorial
	factorial=1;
	for(a=1; a<=value; a++) {
		factorial *= a;
	}

	return factorial;
}
