/*
	Ejemplo de memorama
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

#include "memo.h"

// revolver memorama
int MixMemo(MEMOSTRUCT *memo)
{
	/* Este ejemplo implementa al memorama como un conjunto de
	 * numeros. Cada numero es una carta.
	 * 
	 * Dado que se deben formar pares de cartas el memorama esta
	 * formado a partir de dos series numericas identicas contenidas
	 * en un mismo buffer. Luego estas series se revuelven dentro del
	 * buffer para simular que se revuelve el memorama.
	 *
	 * Al realizar estas operaciones se obtiene un conjunto en donde
	 * se encuentran pares de numeros iguales, tal como se ve un
	 * memoriama.
	 * 
	 * Ademas, cada identificador de carta se empaqueta con un valor
	 * que indica si la carta esta oculta, volteada, o se ha
	 * encontrado la carta con la que forma un par identico */
	
	MEMOCARD num;
	int a,index1,index2;

	if(!memo) {
		return 0;
	}
	
	if(!(memo->numpairs>=MIN_NUMPAIRS||
		memo->numpairs<=MAX_NUMPAIRS))
	{
		// rango de pares invalido
		return 0;
	}
	
	// crear la primera serie numerica
	for(a=0; a<memo->numpairs; a++) {
		memo->cards[a] = MEMOCARD_HIDE<<8|a&0xFF;
	}
	
	// crear la seguanda serie numerica
	for(a=0; a<memo->numpairs; a++) {
		memo->cards[a+memo->numpairs] = MEMOCARD_HIDE<<8|a&0xFF;
	}
	
	// revolver series
	srand(time(NULL));
	for(a=0; a<memo->numpairs*2; a++) {
		index1 = rand()%(memo->numpairs*2);
		index2 = rand()%(memo->numpairs*2);
		
		num=memo->cards[index1];
		memo->cards[index1]=memo->cards[index2];
		memo->cards[index2]=num;
	}
	
	// memorama revuelto
	return 1;
}

// iniciar memorama
MEMOSTRUCT * InitMemo(int numpairs)
{	
	MEMOSTRUCT *newmemo;
	size_t memosize;
	
	// verificación de parametros
	if(!(numpairs>=MIN_NUMPAIRS||numpairs<=MAX_NUMPAIRS)) {
		// rango de pares invalido
		return NULL;
	}
	
	// reservar memoria para el memorama
	memosize=sizeof(MEMOSTRUCT)+(numpairs*2*sizeof(MEMOCARD));
	if(!(newmemo=malloc(memosize))) {
		return NULL;
	}
	memset(newmemo,0,memosize);
	
	newmemo->numpairs = numpairs;
	newmemo->rempairs = numpairs;
	
	// revolver memorama
	MixMemo(newmemo);
	
	return newmemo;
}

// elegir cartas
int ChooseMemoCards(MEMOSTRUCT *memo, int card1, int card2)
{
	int flag=0;
	int a,c1,c2;
	
	// verificación de parametros
	if(!memo) {
		return 0;
	}
	
	if(card1==card2) {
		// cartas iguales
		return CHOOSEMEMO_EQUALCARDS;
	}
	
	if(!(card1>=0&&card2>=0)) {
		// cartas fuera del rango
		return CHOOSEMEMO_OUTRANGE;
	}
	
	if(!(card1<MAX_NUMPAIRS*2&&card2<MAX_NUMPAIRS*2)) {
		// cartas fuera del rango
		return CHOOSEMEMO_OUTRANGE;
	}
	
	// obtener cartas elegidas
	c1=memo->cards[card1]&0xFF;
	c2=memo->cards[card2]&0xFF;
	
	/* Comprobrabar si las cartas elegidas fueron
	 * descubiertas anteriormente */
	if((c1>>8)==MEMOCARD_USED||(c2>>8)==MEMOCARD_USED) {
		return CHOOSEMEMO_USEDCARDS;
	}
	
	// comprobar si las cartas elegidas son iguales
	if(c1==c2) {
		// par de cartas descubierta
		memo->cards[card1] = MEMOCARD_USED<<8 | c1&0xFF;
		memo->cards[card2] = MEMOCARD_USED<<8 | c2&0xFF;
		
		memo->flippairs += 1;
		memo->rempairs  -= 1;

		flag=CHOOSEMEMO_OK;
	}
	else {
		/* El par de cartas seleccionado contiene
		 * elementos diferentes. */
		 
		memo->attempts += 1;
		
		flag=CHOOSEMEMO_AGAIN;
	}
	
	return flag;
}

// reiniciar memorama
void RestartMemo(MEMOSTRUCT *memo)
{
	int a;
	int index1,index2;
	MEMOCARD num;
	
	if(!memo) return;
	
	// revolviendo nuevamente el memorama
	MixMemo(memo);
	
	// reiniciando contadores
	memo->attempts  = 0;
	memo->flippairs = 0;
	memo->rempairs  = memo->numpairs;
}

// liberar memorama
void ReleaseMemo(MEMOSTRUCT *memo)
{
	if(memo) free(memo);
}

