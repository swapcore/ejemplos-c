/*
	Dibujar rombo (Ejemplo de uso)
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
#include "../rhombus/rhombus.h"

#define INVERT4BYTES(v) (v>>24)|((v&0xFF0000)>>8)|((v&0xFF00)<<8)|(v<<24)

// dibujar rombo en consola
void PrintRhombusInConsole(int height)
{
	RHOMBUSSTRUCT *r;
	int x,y;
	
	// crear rombo
	if(!(r=CreateRhombus(height))) {
		printf("ERROR: no se pudo crear el rombo\n");
		return;
	}
	
	// dibujar rombo
	for(y=0; y<r->height; y++) {
		for(x=0; x<r->width; x++) {
			if(r->bmpixels[y*r->width+x]) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	ReleaseRhombus(r);
}

// dibujar rombo en archivo de texto
void PrintRhombusInTextFile(const char *filename, int height)
{
	RHOMBUSSTRUCT *r;
	FILE *fp;
	int x,y;
	
	if((fp=fopen(filename,"rt"))) {
		// el archivo existe
		printf("Ya existe el archivo '%s'\n",filename);
		fclose(fp);
		return;
	}

	if(!(fp=fopen(filename,"wt"))) {
		printf("ERROR: no se puede abrir %s\n",filename);
		return;
	}
	
	// crear rombo
	if(!(r=CreateRhombus(height))) {
		printf("ERROR: no se pudo crear el rombo\n");
		fclose(fp);
		return;
	}
	
	// dibujar rombo
	for(y=0; y<r->height; y++) {
		for(x=0; x<r->width; x++) {
			if(r->bmpixels[y*r->width+x]) {
				fprintf(fp,"*");
			}
			else {
				fprintf(fp," ");
			}
		}
		fprintf(fp,"\n");
	}
	
	printf("Se ha guardado el rombo en %s\n",filename);
	
	ReleaseRhombus(r);
	fclose(fp);
}

// Guardar rombo en archivo binario
void SaveRhombusInBinaryFile(const char *filename, int height)
{
	RHOMBUSSTRUCT *r;
	uint16_t c=1;
	uint8_t *d = (uint8_t*)&c;
	FILE *fp;
	int w,h;
	
	if((fp=fopen(filename,"rb"))) {
		// el archivo existe
		printf("Ya existe el archivo '%s'\n",filename);
		fclose(fp);
		return;
	}
	
	if(!(fp=fopen(filename,"wb"))) {
		return;
	}
	
	// crear el rombo
	if(!(r=CreateRhombus(height))) {
		fclose(fp);
		return;
	}
	
	if(d[0]==1) {
		// invertir bytes
		w = INVERT4BYTES(r->width);
		h = INVERT4BYTES(r->height);
	}
	
	// guarar datos del rombo
	fwrite(&w,4,1,fp);
	fwrite(&h,4,1,fp);
	fwrite(r->bmpixels,1,r->height*r->width,fp);
	
	printf("Se ha guardado el rombo en %s\n",filename);
	
	ReleaseRhombus(r);
	fclose(fp);
}

void PrintHelp()
{
	printf(
		"Uso:\n\n"
		"rhombus <altura> [<archivo> [-bin_output|-txt_output]]\n"
		"\n"
		"Parametros:\n\n"
		"   altura        Altura del rombo.\n"
		"   archivo       Nombre de archivo.\n"
		"   -bin_output   Guardar el rombo en un archivo binario.\n"
		"                 Cuando se gurada de esta manera los datos\n"
		"                 del rombo corresponden al ancho, altura y\n"
		"                 una matriz de pixeles de 8 bits de\n"
		"                 profundidad con una paleta de 2 colores.\n"
		"                 Tanto el ancho como la altura se guardan\n"
		"                 uno despues del otro en registros de 4\n"
		"                 bytes. Esto se encuentra en el inicio del\n"
		"                 archivo y antes de la matriz de pixeles.\n"
		"   -txt_output   Guardar el rombo en un archivo de texto.\n"
		);
}

int main(int argc, char **argv)
{
	int height;
	
	printf("Dibujar rombo\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");
	
	if(!(argc==2||argc==4)) {
		PrintHelp();
		return 0;
	}
	
	// obtener altura del rombo
	height = atoi(argv[1]);
	
	if(argc==2) {
		PrintRhombusInConsole(height);
		return 0;
	}
	
	if(!strcmp(argv[3],"-bin_output")) {
		SaveRhombusInBinaryFile(argv[2],height);
	}
	else if(!strcmp(argv[3],"-txt_output")) {
		PrintRhombusInTextFile(argv[2],height);
	}
	else {
		PrintHelp();
		return 0;
	}
	
	return 0;
}
