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

#ifndef _MEMO_H_
#define _MEMO_H_

#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NUMPAIRS 127
#define MIN_NUMPAIRS 2

// codigos de estado de las cartas
#define MEMOCARD_HIDE 1
#define MEMOCARD_SHOW 2
#define MEMOCARD_USED 3

// codigos de error al elejir las cartas
#define CHOOSEMEMO_OK           0
#define CHOOSEMEMO_EQUALCARDS   1
#define CHOOSEMEMO_AGAIN        2
#define CHOOSEMEMO_OUTRANGE     3 
#define CHOOSEMEMO_USEDCARDS    4 

typedef uint16_t MEMOCARD;

typedef struct TagMemoStruct {
	int numpairs;        // numero de pares de cartas
	int flippairs;       // pares de cartas volteados
	int rempairs;        // pares de cartas restantes
	int attempts;        // intentos
	MEMOCARD cards[1];   // cartas :)
}MEMOSTRUCT;

int MixMemo(MEMOSTRUCT *memo);
MEMOSTRUCT * InitMemo(int numpairs);
int ChooseMemoCards(MEMOSTRUCT *memo, int card1, int card2);
void RestartMemo(MEMOSTRUCT *memo);
void ReleaseMemo(MEMOSTRUCT *memo);

#endif
