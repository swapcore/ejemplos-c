/*
	Conversor de temperatura (Ejemplo de uso)
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

#include "../tempconv/tempconv.h"

int main(int argc, char ** argv)
{
	TEMPSCALE *scale;
	float value;

	printf("Conversor de temperatura\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

	if(argc<2) {
		printf("Uso: tempconv <valor_en_grados_celsius>\n");
		return 0;
	}

	value=(float)(atof(argv[1]));

	if(!(scale=GetTempScale(&value))) {
		return 0;
	}

	printf("%.2f *C -> %.2f *K -> %.2f *F\n",
		scale->sclcelsius,
		scale->sclkelvin,
		scale->sclfahrenheit);

	return 0;
}