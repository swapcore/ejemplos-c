/*
	Información de resistor
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

#include "resistor.h"

// Obtener tolerancia del resistor
double GetTolerance(int color)
{
	switch(color) {
		case BLACK_BAND:  return 0.00;
		case BROWN_BAND:  return 1.00;
		case RED_BAND:    return 2.00;
		case ORANGE_BAND: return 3.00;
		case YELLOW_BAND: return 4.00;
		case GREEN_BAND:  return 0.50;
		case BLUE_BAND:   return 0.25;
		case VIOLET_BAND: return 0.10;
		case GREY_BAND:   return 0.05;
		case WHITE_BAND:  return 0.00;
		case GOLD_BAND:   return 5.00;
		case SILVER_BAND: return 10.00;
		case PINK_BAND:   return 0.00;
	}
}

// verificar resistor
int VerifyResistor(COLORBAND *bands, int numbands)
{
	int clr[13] = {
		BLACK_BAND, BROWN_BAND, RED_BAND,
		ORANGE_BAND, YELLOW_BAND, GREEN_BAND,
		BLUE_BAND, VIOLET_BAND, GREY_BAND,
		WHITE_BAND, GOLD_BAND, SILVER_BAND,
		PINK_BAND
	};
	int a, b;
	int isvalid;
	
	for(a=0; a<numbands; a++) {
		isvalid=0;
		for(b=0; b<13; b++) {
			if(bands[a]==clr[b]) isvalid=1;
		}
		if(!isvalid) {
			break;
		}
	}
	
	return isvalid;
}

// obtener informacion del resistor
RESISTORINFO * GetResistorInfo(COLORBAND *bands, int numbands)
{
	RESISTORINFO *r;
	size_t len=0;
	
	if(!bands) {
		// ¡No hay bandas de color!
		return NULL;
	}
	
	if(!(numbands==4||numbands==5)) {
		// cantidad invalida de bandas de color
		return NULL;
	}
	
	if(!VerifyResistor(bands,numbands)) {
		return NULL;
	}
	
	// reservar memoria para la información del resistor
	len += sizeof(RESISTORINFO);
	len += ((numbands-1)*sizeof(COLORBAND));
	if(!(r=malloc(len))) {
		return NULL;
	}
	memset(r,0,len);
	
	// obtener información del resistor
	switch(numbands) {
		// resistor normal
		case 4: {
			r->number     += (double)(bands[0])*10.00;
			r->number     += (double)(bands[1]);
			r->multiplier  = (double)(bands[2]);
			r->tolerance   = GetTolerance(bands[3]);
			break;
		}
		// resistor de presición
		case 5: {
			r->number     += (double)(bands[0])*100.00;
			r->number     += (double)(bands[1])*10.00;
			r->number     += (double)(bands[2]);
			r->multiplier  = (double)(bands[3]);
			r->tolerance   = GetTolerance(bands[4]);
			break;
		}
	}
	
	// obtener el valor del resistor
	r->value = r->number*pow(10,r->multiplier);
	
	// copiar bandas de color
	memcpy(r->bands,bands,numbands*sizeof(COLORBAND));
	
	return r;
}
