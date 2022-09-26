/*
	Dibujar rombo
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


#include "rhombus.h"

// Dibujar rombo en una matriz de pixeles
RHOMBUSSTRUCT * CreateRhombus(int height)
{
	RHOMBUSSTRUCT *rhombus;
	uint8_t *offset;
	int h,drwpixels;
	
	if(height<3) {
		/* el rombo no puede crearse con una 
		 * altura menor a 3 pixeles */
		return 0;
	}
	
	// ajustando altura del rombo
	h = (height | 1);
	
	// reservar memoria para guardar el rombo creado
	if(!(rhombus=malloc(sizeof(RHOMBUSSTRUCT)))) {
		return NULL;
	}
	if(!(rhombus->bmpixels=malloc(h*h))) {
		free(rhombus);
		return NULL;
	}
	memset(rhombus->bmpixels,0,h*h);
	
	// definiendo información del rombo
	rhombus->width  = h;
	rhombus->height = h;
	
	/* Preparar datos que serviran para dibujar la
	 * primera mitad del rombo */
 	offset     = rhombus->bmpixels;
	offset    += (h/2);
	drwpixels  = 1;
	
	// dibujar la primera mitad del rombo
	while(drwpixels<=h) {
		memset(offset,1,drwpixels);
		offset    += (h-1);
		drwpixels += 2;
	}
	
	/* Preparar datos que serviran para dibujar la
	 * segunda mitad del rombo */
	offset    += 2;
	drwpixels  = (h-2);
	
	// dibujar la segunda mitad del rombo
	while(drwpixels>=1) {
		memset(offset,1,drwpixels);
		offset    += (h+1);
		drwpixels -= 2;
	}

	return rhombus;
}
