/*
	Calculo de área
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

#include "area.h"

// obtener área de figura en un plano cartesiano
int GetCoordArea(COORDSTRUCT *vertex,
	size_t elements, double *area)
{
	size_t a;
	
	// verificación de parametros
	if(!(vertex&&elements>=3)) {
		return 0;
	}
	
	// obtener área
	for(a=0; a<elements; a++) 
		*area += (vertex[a].x*vertex[(a+1)%elements].y);
	for(a=0; a<elements; a++) 
		*area -= (vertex[(a+1)%elements].x*vertex[a].y);

	*area  = fabs(*area);
	*area *= 0.5;
	
	// area obtenida
	return 1;
}
