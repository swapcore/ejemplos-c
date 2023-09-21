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

// obtener multiplicador
double GetMultiplier(int color)
{
	switch(color) {
		case BLACK_BAND:  return pow(10,0.00);
		case BROWN_BAND:  return pow(10,1.00);
		case RED_BAND:    return pow(10,2.00);
		case ORANGE_BAND: return pow(10,3.00);
		case YELLOW_BAND: return pow(10,4.00);
		case GREEN_BAND:  return pow(10,5.00);
		case BLUE_BAND:   return pow(10,6.00);
		case VIOLET_BAND: return pow(10,7.00);
		case GREY_BAND:   return pow(10,8.00);
		case WHITE_BAND:  return pow(10,9.00);
		case GOLD_BAND:   return pow(10,-1.00);
		case SILVER_BAND: return pow(10,-2.00);
		case PINK_BAND:   return pow(10,-3.00);
	}

	return 0;
}

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

	return 0;
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
			r->multiplier  = GetMultiplier((double)(bands[2]));
			r->tolerance   = GetTolerance(bands[3]);
			break;
		}
		// resistor de presición
		case 5: {
			r->number     += (double)(bands[0])*100.00;
			r->number     += (double)(bands[1])*10.00;
			r->number     += (double)(bands[2]);
			r->multiplier  = GetMultiplier((double)(bands[3]));
			r->tolerance   = GetTolerance(bands[4]);
			break;
		}
	}

	// obtener valor del resistor en ohms:
	r->value = r->number*r->multiplier;
	
	// copiar bandas de color
	memcpy(r->bands,bands,numbands*sizeof(COLORBAND));
	
	return r;
}

// obtener informacion de resistor SMB
SMBRESISTORINFO * GetSMBResistorInfo(const char *code)
{
	SMBRESISTORINFO *r;
	char temp[10]={0};
	char *ptr;
	double cf[4];
	int len,a;

	len=strlen(code);

	if(!(len==3||len==4)) {
		return NULL;
	}

	// reservar memoria para la información del resistor
	if(!(r=calloc(1,sizeof(SMBRESISTORINFO)))) {
		return NULL;
	}

	if(strchr(code,'R')) {
		// valor de resistencia de coma flotante
		memcpy(temp,code,len);
		ptr=strchr(temp,'R');
		ptr[0]='.';

		r->value=atof(temp);
	}
	else {
		// obtener cifras significativas
		for(a=0; a<len; a++) {
			temp[0]=code[a];
			temp[1]='\0';

			cf[a]=(double)(atoi(temp));
		}

		// resistencia SMB de 3 cifras significativas
		if(len==3) {
			r->value += cf[0]*10.00;
			r->value += cf[1];
			r->value *= pow(10,cf[2]);
		}

		// resistencia SMB de 4 cifras significativas
		if(len==4) {
			r->value += cf[0]*100.00;
			r->value += cf[1]*10.00;
			r->value += cf[2];
			r->value *= pow(10,cf[3]);
		}
	}

	return r;
}
