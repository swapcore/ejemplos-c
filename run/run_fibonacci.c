/*
	Serie de fibonacci (Ejemplo de uso)
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
#include "../fibonacci/fibonacci.h"

int main(int argc, char ** argv)
{
	FIBONACCISTRUCT *f;
	int a;

	printf("Serie de fibonacci\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

	if(argc<2) {
		printf("Uso: fibonacci <longitud>\n");
		return 0;
	}

	if(!(f=GetFibonacci(atoi(argv[1])))) {
		printf("ERROR: no se puedo crear la serie de fibonacci");
		return 0;
	}

	printf("SERIE DE FIBONACCI\n\n");
	for(a=0; a<f->nbelems; a++) {
		printf("[%i] -> %i\n",a+1,f->elements[a]);
	}

	printf("\n%i elementos\nUltimo valor: %i\n",
		f->nbelems,f->lastvalue);
	
	free(f);

	return 0;
}