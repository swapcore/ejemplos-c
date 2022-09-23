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

#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include <math.h>

#define BLACK_BAND    0
#define BROWN_BAND    1
#define RED_BAND      2
#define ORANGE_BAND   3
#define YELLOW_BAND   4
#define GREEN_BAND    5
#define BLUE_BAND     6
#define VIOLET_BAND   7
#define GREY_BAND     8
#define WHITE_BAND    9
#define GOLD_BAND     10
#define SILVER_BAND   11
#define PINK_BAND     12

#define NORMAL_RESISTOR      1
#define PRECISION_RESISTOR   2

typedef int COLORBAND;

typedef struct TagResistorInfo {
	int type;              // tipo de resistor
	double number;         // nuemro resultante de las bandas de color
	double multiplier;     // multiplicador
	double value;          // valor de la resistencia (en ohms)
	double tolerance;      // tolerancia
	COLORBAND bands[1];    // bandas de color
}RESISTORINFO;

double GetTolerance(int color);
int VerifyResistor(COLORBAND *bands, int numbands);
RESISTORINFO * GetResistorInfo(COLORBAND *bands, int numbands);

#endif
