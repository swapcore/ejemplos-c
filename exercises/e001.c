/*
	Insertar y leer en 5 listas enlazadas
	Copyright (c) 2022-2023 Oscar Elías
	
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

typedef struct TagNodoLista {
	int dato;
	struct TagNodoLista *siguiente;
}NODOLISTA;

NODOLISTA * lista1 = NULL;
NODOLISTA * lista2 = NULL;
NODOLISTA * lista3 = NULL;
NODOLISTA * lista4 = NULL;
NODOLISTA * lista5 = NULL;

// insertar valor en la lista indicada
int InsertarValor(int dato, int indice)
{
	NODOLISTA *nodo,**c;

	// seleccionar la lista
	switch(indice) {
		case 0: c=&lista1; break;
		case 1: c=&lista2; break;
		case 2: c=&lista3; break;
		case 3: c=&lista4; break;
		case 4: c=&lista5; break;
	}

	// crear nodo
	if(!(nodo=malloc(sizeof(NODOLISTA)))) {
		return -1;
	} 

	nodo->dato=dato;
	nodo->siguiente=NULL;

	// insertar elemento
	while(c[0]) c=&c[0]->siguiente;
	c[0]=nodo;

	return 1;
}

// buscar valor
int BuscarValor(int dato)
{
	NODOLISTA *nodo,**c;
	int indice=0;

	for(indice=0; indice<5; indice++) {
		// seleccionar la lista
		switch(indice) {
			case 0: c=&lista1; break;
			case 1: c=&lista2; break;
			case 2: c=&lista3; break;
			case 3: c=&lista4; break;
			case 4: c=&lista5; break;
		}

		// buscar elemento
		while(c[0]) {
			if(c[0]->dato==dato) {
				// valor encontrado
				return indice;
			}
			c=&c[0]->siguiente;
		}
	}

	return -1;
}

// liberar listas
void LiberarListas()
{
	NODOLISTA *nodo,*c,*siguiente;
	int indice;

	for(indice=0; indice<5; indice++) {
		// seleccionar la lista
		switch(indice) {
			case 0: c=lista1; break;
			case 1: c=lista2; break;
			case 2: c=lista3; break;
			case 3: c=lista4; break;
			case 4: c=lista5; break;
		}

		// liberar lista
		while(c) {
			siguiente=c->siguiente;
			free(c);
			c=siguiente;
		}
	}

	return;
}

int main(int argc, char ** argv)
{
	int ronda,indice;

	printf("Insertar y leer en 5 listas enlazadas\n"
	       "Copyright (c) 2022-2023 Oscar Elias\n\n");

	srand(time(NULL));

	for(ronda=0; ronda<10; ronda++) {
		/* Insertar un dato en una lista elegida
		 * aleatoriamente */
		indice = rand()%5;
		InsertarValor(ronda,indice);
		printf("Insertar valor '%i' en la lista %i\n",ronda,indice);
	}

	// leer los valores insertados en las listas
	for(ronda=0; ronda<10; ronda++) {
		if((indice=BuscarValor(ronda))>=0) {
			printf("Se ha encontrado el valor '%i' en la lista %i\n",
				ronda,indice);
		}
	}

	LiberarListas();

	return 0;
}