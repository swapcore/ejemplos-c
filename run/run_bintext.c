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
#include <stdint.h>
#include <ctype.h>
#include "../bintext/bintext.h"

int main(int argc, char ** argv)
{
	FILE *fp,*fpdst;
	char *ptr;
	int c,a;

	printf("Conversor de texto a binario\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

    if(argc<3) {
		printf(
			"Uso: bintext <origen> <destino>\n"
			"\n"
			"Parametros:\n\n"
			"   <origen>    Archivo de texto origen\n"
			"   <destino>   Archivo de texto destino\n"
		);

		return 0;
    }

	if(!(fp=fopen(argv[1],"rt"))) {
		printf("Imposible abrir el archivo '%s'\n",argv[1]);
		
		return 1;
	}

	if(!(fpdst=fopen(argv[2],"wt"))) {
		printf("Imposible abrir el archivo '%s'\n",argv[1]);
		fclose(fp);
		
		return 1;
	}

	while((c=fgetc(fp))!=EOF) {
		if(isprint(c)) {
			ptr=CharToBin(c);
			fprintf(fpdst,"Caracter '%c' (0x%02x): %s\n",
				c,c,ptr);
			free(ptr);
		}
	}

	fclose(fpdst);
	fclose(fp);

    return 0;
}