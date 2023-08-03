/*
	Conversor de números romanos (Ejemplo de uso)
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

#include "../romanconv/romanconv.h"

int main(int argc, char ** argv)
{
	int v;
	char *str;

   	printf("Conversor de numeros romanos\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

	if(argc<2) {
		printf("Uso: romanconv <valor>\n");
		return 0;
	}

	v=atoi(argv[1]);

	if((str=GetRomanNumber(v))) {
		printf("Correspondencia: %i -> %s\n",v,str);
	}
	else if((v=RomanNumberToNumber(argv[1]))) {
		printf("Correspondencia: %s -> %i\n",argv[1],v);
	}
	else {
		printf("Valor invalido\n");
	}

    return 0;
}