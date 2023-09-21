/*
	Texto en rectangulo
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

#include "textrect.h"

// insertar texto dentro de un rectanglo
TEXTRECTSTRUCT * TextInRect(const char *str, int ch)
{
	TEXTRECTSTRUCT *r;
	int len;
	
	if(!str) {
		return NULL;
	}
	
	if(!(len=strlen(str))) {
		// el buffer no contiene texto (caractéres)
		return NULL;
	}
	
	if(!(r=malloc(sizeof(TEXTRECTSTRUCT)))) {
		// error de asignación de memoria
		return NULL;
	}
	
	/* Obtener el ancho y alto del rectangulo
	 * que contendrá el texto */
	r->width    = len+4;
	r->height   = 5;
	r->rectsize = ((len+4)*5)+1;
	
	// reservar memoria para el rectangulo
	if(!(r->textrect=calloc(1,r->rectsize))) {
		free(r);
		return NULL;
	}
	
	/* Dibujar rectangulo e insertar texto
	 * dentro de el */
	memset(r->textrect,ch,r->rectsize-1);
	memcpy(r->textrect+((r->width*2)+2),str,len);
	
	return r;
}

// liberar texto dentro de un rectanglo
void ReleaseTextInRect(TEXTRECTSTRUCT * r)
{
	if(!r) return;
	free(r->textrect);
	free(r);
}
