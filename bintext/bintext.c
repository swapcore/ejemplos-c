/*
	Conversor de texto a binario
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

#include "bintext.h"

// obtenter representación binaria de un caracter
char * CharToBin(int ch)
{
	char *chbin;
	int a;
	
	/* Reservar memoria para la representación
	 * binaria del caracter */
	if(!(chbin=calloc(8+1,1))) {
		return NULL;
	}
	
	// obtenter representación del caracter
	for(a=0; a<8; a++) {
		itoa((ch>>(7-a))&1,chbin+a,10);
	}
	
	return chbin; 
}

// obtenter representación binaria de un texto
char * TextToBin(const char * text, size_t len)
{
	char *bintext, *chbin;
	char *offset;
	int a;
	
	if(!(text&&len)) {
		// parametros incorrectos
		return NULL;
	}
	
	if(!strlen(text)) {
		// el buffer no contiene texto
		return NULL;
	}
	
	/* Reservar memoria para la representación
	 * binaria del texto */
	if(!(bintext=calloc((len*8)+(len-1)+1,1))) {
		return NULL;
	}
	
	offset=bintext;
	
	// obtenter representación del texto
	for(a=0; a<len; a++) {
		// obtenter representación binaria del caracter
		if(!(chbin=CharToBin(text[a]))) {
			free(bintext);
			return NULL;
		}
		
		/* Insertar representacion binaria del caracter
		 * en el texto binario */
		memcpy(offset,chbin,8);
		offset += 8;
		
		// agregar espacio en blanco
		if(len>1&&a<len-1) {
			offset[0] = ' ';
			offset++;
		}
		
		free(chbin);
	}
	
	return bintext;
}
