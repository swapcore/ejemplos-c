/*
	Conversor de temperatura
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

#include "tempconv.h"

// Obtener temperatura en diferentes escalas
TEMPSCALE * GetTempScale(float *temp)
{
	TEMPSCALE *tmpscl;
	
	if(!(tmpscl=malloc(sizeof(TEMPSCALE)))) {
		return NULL;
	}
	
	tmpscl->sclcelsius    = *temp;
	tmpscl->sclfahrenheit = (*temp*1.8) + 32.0;
	tmpscl->sclkelvin     = *temp + 273.15;
	
	return tmpscl;
}
