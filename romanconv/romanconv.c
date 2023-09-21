/*
	Convertidor simple de numeros romanos
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

#include "romanconv.h"

// Obtener valor de simbolo de numeracion romana
int GetLetterValue(char c)
{
	switch(c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	
	return 0;
}

// convertir a numero romano
char * GetRomanNumber(int value)
{
	char * romannum;
	char * temp;
	size_t len;
	int remaining;
	int units;
	int a;
	
	// revisión de paramatros
	if(!(value>=1&&value<4000)) {
		// numero invalido
		return NULL;
	}
	
	/* Asumir que el numero resultante tendra
	 * como maximo 16 caracteres */
	len = (16+1)*sizeof(char);
	if(!(romannum=malloc(len))) {
		return NULL;
	}
	memset(romannum,0,len);
	
	/* A partir de aqui se obtendra el numero
	 * romano correspondiente al numero definido
	 * en "value" mediante la lectura de sus cifras */
	 
	remaining = value;
	
	// convertir millares
	if((units=remaining/1000)>0) {
		remaining %= 1000;
		for(a=0; a<units; a++) strcat(romannum,"M");
	}
	
	// convertir centenas
	if((units=remaining/100)>0) {
		remaining %= 100;
		if(units==4)
			strcat(romannum,"CD");
		else if(units==9)
			strcat(romannum,"CM");
		else {
			if(units>=5&&units<=8)
				strcat(romannum,"D");
			for(a=0; a<(units%5); a++)
				strcat(romannum,"C");
		}
	}

	// convertir decenas
	if((units=remaining/10)>0) {
		remaining %= 10;
		if(units==4)
			strcat(romannum,"XL");
		else if(units==9)
			strcat(romannum,"XC");
		else {
			if(units>=5&&units<=8)
				strcat(romannum,"L");
			for(a=0; a<(units%5); a++)
				strcat(romannum,"X");
		}
	}

	// convertir unidades
	if(remaining>0) {
		if(remaining==4)
			strcat(romannum,"IV");
		else if(remaining==9)
			strcat(romannum,"IX");
		else {
			if(remaining>=5&&remaining<=8)
				strcat(romannum,"V");
			for(a=0; a<(remaining%5); a++) {
				strcat(romannum,"I");
			}
		}
	}
	
	// truncar cadena
	len = (strlen(romannum)+1)*sizeof(char);
	if(!(temp=realloc(romannum,len))) {
		return NULL;
	}
	romannum = (char*)temp;
	
	return romannum;
}

// convertir numero romana a numero
int RomanNumberToNumber(const char * str)
{
	int number=0, a;
	size_t len;
	
	if(!str) {
		return 0;
	}
	
	if(!(len=strlen(str))) {
		// el buffer no contiene texto
		return 0;
	}
	
	if(len<strspn(str,"IVXLCDM")) {
		/* El buffer contiene caracteres que no
		 * corresponden a alguna cifra en el 
		 * sistema de numeración romana */
		return 0;
	}
	
	// obtener numero correspondinete al numero romano
	for(a=0; a<len; a++) {
		int currentvalue = GetLetterValue(str[a+0]);
		int nextvalue    = GetLetterValue(str[a+1]);
		
		if(currentvalue<nextvalue) {
			/* Sumar la direrencia del valor del simbolo
			 * actual y el valor del siguiente simbolo */
			number += (nextvalue-currentvalue);
			a += 1;
		}
		else {
			// sumar los valores de los simbolos 
			number += currentvalue;
		}
	}
	
	return number;
}
