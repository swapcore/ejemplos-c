/*
	Texto en rectangulo (Ejemplo de uso)
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

#include "../textrect/textrect.h"

// guardar texto en rectangulo
void SaveTextInRext(const char *message, const char *filename)
{
	TEXTRECTSTRUCT *r;
	FILE *fp;
	int x,y;
	
	if(!message||!filename) {
		return;
	}
	
	if((fp=fopen(filename,"rt"))) {
		printf("Ya existe el archivo '%s'\n",filename);
		return;
	}
	
	if(!(fp=fopen(filename,"wt"))) {
		printf("Error al abrir el archivo '%s'\n",filename);
		return;
	}
	
	if(!(r=TextInRect(message,'/'))) {
		printf("Imposible crear el rectangulo\n");
		return;
	}
	
	for(y=0; y<r->height; y++) {
		for(x=0; x<r->width; x++) {
			fprintf(fp,"%c",r->textrect[y*r->width+x]);
		}
		
		fprintf(fp,"\n");
	}
	
	printf("Texto en rectangulo guardado en '%s'\n",filename);
	
	ReleaseTextInRect(r);
}

// Mostrar texto en rectangulo
void PrintTextInRext(const char *message)
{
	TEXTRECTSTRUCT *r;
	int x,y;
	
	if(!message) {
		return;
	}
	
	if(!(r=TextInRect(message,'/'))) {
		printf("Imposible crear el rectangulo\n");
		return;
	}
	
	for(y=0; y<r->height; y++) {
		for(x=0; x<r->width; x++) {
			printf("%c",r->textrect[y*r->width+x]);
		}
		
		printf("\n");
	}
	
	ReleaseTextInRect(r);
}

void PrintHelp()
{
	printf(
		"Uso:\n"
		"\n"
		"textrect <mensaje> [<archivo>]\n"
		"\n"
		"Parametros:\n"
		"\n"
		"   mensaje   Mensaje que se introducira en el rectangulo.\n"
		"   archivo   Nombre del archivo donde se guardara el texto\n"
		"             en rectangulo.\n"
		);
}

int main(int argc, char **argv)
{
	printf("Texto en rectangulo\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");
	
	if(!(argc==2||argc==3)) {
		PrintHelp();
		return 0;
	}
	
	if(argc==2) {
		PrintTextInRext(argv[1]);
		return 0;
	}
	
	SaveTextInRext(argv[1],argv[2]);
	
	return 0;
}
