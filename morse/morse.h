/*
	Ejemplo de un interprete de codigo morse
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

#ifndef _MORSE_H_
#define _MORSE_H_

#include <stdint.h>

typedef uint32_t MORSECODE; 

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <memory.h>

#define MORSE_CHARSET L"ABCDEFGHIJKLNMOPQRSTUVWXYZ0123456789\"?\xD1 "

// alfabeto morse

#define A_MORSE_CODE 0x1D        // A
#define B_MORSE_CODE 0x157       // B
#define C_MORSE_CODE 0x5D7       // C
#define D_MORSE_CODE 0x57        // D
#define E_MORSE_CODE 0x1         // E
#define F_MORSE_CODE 0x175       // F
#define G_MORSE_CODE 0x177       // G
#define H_MORSE_CODE 0x55        // H
#define I_MORSE_CODE 0x5         // I
#define J_MORSE_CODE 0x1DDD      // J
#define K_MORSE_CODE 0x1D7       // K
#define L_MORSE_CODE 0x15D       // L
#define M_MORSE_CODE 0x77        // M
#define N_MORSE_CODE 0x17        // N
#define O_MORSE_CODE 0x777       // O
#define P_MORSE_CODE 0x5DD       // P
#define Q_MORSE_CODE 0x1D77      // Q
#define R_MORSE_CODE 0x5D        // R
#define S_MORSE_CODE 0x15        // S
#define T_MORSE_CODE 0x7         // T
#define U_MORSE_CODE 0x75        // U
#define V_MORSE_CODE 0x3A5       // V
#define W_MORSE_CODE 0x1DD       // W
#define X_MORSE_CODE 0x757       // X
#define Y_MORSE_CODE 0x1DD7      // Y
#define Z_MORSE_CODE 0x577       // Z

#define N0_MORSE_CODE 0x77777    // 0
#define N1_MORSE_CODE 0x1DDDD    // 1
#define N2_MORSE_CODE 0x7775     // 2
#define N3_MORSE_CODE 0x1DD5     // 3
#define N4_MORSE_CODE 0xEA5      // 4
#define N5_MORSE_CODE 0x2A5      // 5
#define N6_MORSE_CODE 0x557      // 6
#define N7_MORSE_CODE 0x1577     // 7
#define N8_MORSE_CODE 0x5777     // 8
#define N9_MORSE_CODE 0x17777    // 9

#define POINT_MORSE_CODE 0x1DD75D   // Punto
#define COMMA_MORSE_CODE 0xEEA77    // Coma
#define QUOTE_MORSE_CODE 0x5D5D     // Commilla doble

#define QUESTION_MORSE_CODE 0x5775  // Interrogación

#define NN_MORSE_CODE 0x1DD77    // Ñ
#define CH_MORSE_CODE 0x7777     // Ch

#define LETTER_SEPARATOR 0xFFFFFFF8   // Separador de letras
#define WORD_SEPARATOR 0xFFFFFE00     // Separador de palabras

MORSECODE CharToMorse(wchar_t ch);
wchar_t MorseToChar(MORSECODE ch);
int ReallocMorseBuffer(MORSECODE **buf, size_t elements);
wchar_t * TextToMayus(const wchar_t *str);
MORSECODE * TextToMorse(const wchar_t *str);
wchar_t * MorseToText(MORSECODE *code);

#endif
