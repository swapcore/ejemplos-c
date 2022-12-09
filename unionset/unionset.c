/*
	Unión de conjuntos
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

#include "unionset.h"

// iniciar el conjunto
CONJUNTO * InitConjunto()
{
	CONJUNTO * newset;
	
	// reservar memoria para el conjunto
	if(!(newset=malloc(sizeof(CONJUNTO)))) {
		return NULL;
	}
	
	// poner nuevo conjunto a cero
	memset(newset,0,sizeof(CONJUNTO));
	
	return newset;
}

// agregar numero al conjunto
int AddConjunto(CONJUNTO *pset, int value)
{
	int *c;
	
	// verificar parametro
	if(!pset) {
		return 0;
	}
	
	// reasignar memoria para el conjunto
	c=realloc(pset->nums,(pset->elements+1)*sizeof(int));
	if(!c) {
		// error de asignación de memoria
		free(pset->nums);
		pset->nums = NULL;
		pset->elements = 0;
		return 0;
	}
	pset->nums=c;
	
	// agregar elemento al final del conjunto
	pset->nums[pset->elements] = value;
	
	// actualizar numero de elementos
	pset->elements += 1;
	
	// reasignacion completada
	return 1;
}

// unir conjuntos
CONJUNTO * UnirConjunto(CONJUNTO *set1, CONJUNTO *set2)
{
	CONJUNTO *uset;
	int a;
	
	// verificar parametros
	if(!(set1&&set2)) {
		return NULL;
	}
	
	if(!set1->nums&&!set2->nums) {
		// no har elementos para insertar en la unión
		return NULL;
	}
	
	// crear conjunto unión de set1 y set2
	if(!(uset=InitConjunto())) {
		return NULL;
	}
	
	if(set1->nums) {
		// copiar valores del conjunto 1
		for(a=0; a<set1->elements; a++)
			AddConjunto(uset, set1->nums[a]);	
	}
	
	if(set2->nums) {
		// copiar valores del conjunto 2
		for(a=0; a<set2->elements; a++)
			AddConjunto(uset, set2->nums[a]);
	}
	
	return uset;
}

// liberar conjunto
void ReleaseConjunto(CONJUNTO *c)
{
	if(c) {
		free(c->nums);
		free(c);
	}
}
