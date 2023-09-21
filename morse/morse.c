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

#include "morse.h"

// converitir caracter a codigo morse
MORSECODE CharToMorse(wchar_t ch)
{
	switch(ch) {
		case 0x41: return A_MORSE_CODE;          // A
		case 0x42: return B_MORSE_CODE;          // B 
		case 0x43: return C_MORSE_CODE;          // C
		case 0x44: return D_MORSE_CODE;          // D
		case 0x45: return E_MORSE_CODE;          // E
		case 0x46: return F_MORSE_CODE;          // F
		case 0x47: return G_MORSE_CODE;          // G
		case 0x48: return H_MORSE_CODE;          // H
		case 0x49: return I_MORSE_CODE;          // I
		case 0x4A: return J_MORSE_CODE;          // J
		case 0x4B: return K_MORSE_CODE;          // K
		case 0x4C: return L_MORSE_CODE;          // L
		case 0x4D: return M_MORSE_CODE;          // M
		case 0x4E: return N_MORSE_CODE;          // N
		case 0x4F: return O_MORSE_CODE;          // O
		case 0x50: return P_MORSE_CODE;          // P
		case 0x51: return Q_MORSE_CODE;          // Q
		case 0x52: return R_MORSE_CODE;          // R
		case 0x53: return S_MORSE_CODE;          // S
		case 0x54: return T_MORSE_CODE;          // T
		case 0x55: return U_MORSE_CODE;          // U
		case 0x56: return V_MORSE_CODE;          // V
		case 0x57: return W_MORSE_CODE;          // W
		case 0x58: return X_MORSE_CODE;          // X
		case 0x59: return Y_MORSE_CODE;          // Y
		case 0x5A: return Z_MORSE_CODE;          // Z
		case 0x30: return N0_MORSE_CODE;         // 0
		case 0x31: return N1_MORSE_CODE;         // 1
		case 0x32: return N2_MORSE_CODE;         // 2
		case 0x33: return N3_MORSE_CODE;         // 3
		case 0x34: return N4_MORSE_CODE;         // 4
		case 0x35: return N5_MORSE_CODE;         // 5
		case 0x36: return N6_MORSE_CODE;         // 6
		case 0x37: return N7_MORSE_CODE;         // 7
		case 0x38: return N8_MORSE_CODE;         // 8
		case 0x39: return N9_MORSE_CODE;         // 9
		case 0x2E: return POINT_MORSE_CODE;      // Punto
		case 0x2C: return COMMA_MORSE_CODE;      // Coma
		case 0x22: return QUOTE_MORSE_CODE;      // Commilla doble
		case 0x3F: return QUESTION_MORSE_CODE;   // Interrogación
		case 0xD1: return NN_MORSE_CODE;         // Ñ
		case 0x20: return WORD_SEPARATOR;        // Espacio en blanco
	}
	
	return 0;
}

// converitir codigo morse a caracter
wchar_t MorseToChar(MORSECODE ch)
{
	switch(ch) {
		case A_MORSE_CODE:        return 0x41;   // A
		case B_MORSE_CODE:        return 0x42;   // B 
		case C_MORSE_CODE:        return 0x43;   // C
		case D_MORSE_CODE:        return 0x44;   // D
		case E_MORSE_CODE:        return 0x45;   // E
		case F_MORSE_CODE:        return 0x46;   // F
		case G_MORSE_CODE:        return 0x47;   // G
		case H_MORSE_CODE:        return 0x48;   // H
		case I_MORSE_CODE:        return 0x48;   // I
		case J_MORSE_CODE:        return 0x4A;   // J
		case K_MORSE_CODE:        return 0x4B;   // K
		case L_MORSE_CODE:        return 0x4C;   // L
		case M_MORSE_CODE:        return 0x4D;   // M
		case N_MORSE_CODE:        return 0x4E;   // N
		case O_MORSE_CODE:        return 0x4F;   // O
		case P_MORSE_CODE:        return 0x50;   // P
		case Q_MORSE_CODE:        return 0x51;   // Q
		case R_MORSE_CODE:        return 0x52;   // R
		case S_MORSE_CODE:        return 0x53;   // S
		case T_MORSE_CODE:        return 0x54;   // T
		case U_MORSE_CODE:        return 0x55;   // U
		case V_MORSE_CODE:        return 0x56;   // V
		case W_MORSE_CODE:        return 0x57;   // W
		case X_MORSE_CODE:        return 0x58;   // X
		case Y_MORSE_CODE:        return 0x59;   // Y
		case Z_MORSE_CODE:        return 0x5A;   // Z
		case N0_MORSE_CODE:       return 0x30;   // 0
		case N1_MORSE_CODE:       return 0x31;   // 1
		case N2_MORSE_CODE:       return 0x32;   // 2
		case N3_MORSE_CODE:       return 0x33;   // 3
		case N4_MORSE_CODE:       return 0x34;   // 4
		case N5_MORSE_CODE:       return 0x35;   // 5
		case N6_MORSE_CODE:       return 0x36;   // 6
		case N7_MORSE_CODE:       return 0x37;   // 7
		case N8_MORSE_CODE:       return 0x38;   // 8
		case N9_MORSE_CODE:       return 0x39;   // 9
		case POINT_MORSE_CODE:    return 0x2E;   // Punto
		case COMMA_MORSE_CODE:    return 0x2C;   // Coma
		case QUOTE_MORSE_CODE:    return 0x22;   // Comilla doble
		case QUESTION_MORSE_CODE: return 0x3F;   // Interrogación
		case NN_MORSE_CODE:       return 0xD1;   // Ñ
		case WORD_SEPARATOR:      return 0x20;   // Espacio en blanco
	}
	
	return 0;
}

// agregar o eliminar elementos en buffer de codigo morse
int ReallocMorseBuffer(MORSECODE **buf, size_t elements)
{
	MORSECODE *c;
	
	// revisión de parametros
	if(elements<0) return 0;
	
	// agregar o eliminar elementos
	if(!(c=realloc(buf[0],
		elements*sizeof(MORSECODE)))) {
			return 0;
	}
	buf[0]=c;
	
	return 1;
}

// convertir texto a mayusculas
wchar_t * TextToMayus(const wchar_t *str)
{
	wchar_t *c;
	size_t wlen, a;
	
	// verificación de parametros
	if(!str) return NULL;
	if(!(wlen=wcslen(str))) return NULL;
	
	if(!(c=malloc((wlen+1)*sizeof(wchar_t)))) {
		return NULL;
	}

	// convertir a mayusculas
	for(a=0; a<wlen; a++) c[a] = towupper(str[a]);
	c[a]=L'\0';
	
	return c;
}

// convertir texto a codigo morse
MORSECODE * TextToMorse(const wchar_t *str)
{
	MORSECODE *morsetext=NULL;
	wchar_t *uppertext;
	size_t elems=0;
	size_t buffsize,a;
	size_t wlen;
	
	// verificación de parametros
	if(!str) {
		return NULL;
	}
	
	if(!(wlen=wcslen(str))) {
		// el buffer no contiene texto
		return NULL;
	}
	
	/* Convertir texto a maysculas: El codigo morse
	 * solo soporta caracteres en mayuscula */
	if(!(uppertext=TextToMayus(str))) {
		return NULL;
	}
	
	if(wlen<wcsspn(str,MORSE_CHARSET))
	{
		/* El buffer contiene caracteres no
		 * especificados en el codigo morse */
		return NULL;
	}
	
	// convertir a codigo morse
	for(a=0; a<wlen; a++) {
		if(uppertext[a]==0x20) {
		 	// el caracter es un espacio en blanco
			if(!ReallocMorseBuffer(&morsetext,elems+1)) {
				if(morsetext) free(morsetext);
				free(uppertext);
				return NULL;
			}
			morsetext[elems+0] = WORD_SEPARATOR;
			elems += 1;
		}
		else if(uppertext[a+1]!=0x20&&
		 	uppertext[a+1]!=0x00)
		{
		 	/* El caracter es una letra que inicia o
		 	 * esta contenida en una palabra */
			if(!ReallocMorseBuffer(&morsetext,elems+2)) {
				if(morsetext) free(morsetext);
				free(uppertext);
				return NULL;
			}
			morsetext[elems+0] = CharToMorse(uppertext[a]);
			morsetext[elems+1] = LETTER_SEPARATOR;
			elems += 2;
		}
		else {
			/* El caracter es una letra que esta
			 * al final de una palabra o del texto */
			if(!ReallocMorseBuffer(&morsetext,elems+1)) {
				if(morsetext) free(morsetext);
				free(uppertext);
				return NULL;
			}
			morsetext[elems+0] = CharToMorse(uppertext[a]);
			elems += 1;
		}
	}
	
	// insertar fin del codigo morse
	if(!ReallocMorseBuffer(&morsetext,elems+1)) {
		if(morsetext) free(morsetext);
		free(uppertext);
		return NULL;
	}
	morsetext[elems+0] = 0x0;
	elems += 1;
	
	free(uppertext);
	
	return morsetext;
}

// convertir codigo morse a texto
wchar_t * MorseToText(MORSECODE *code)
{
	wchar_t * textbuf;
	MORSECODE * offset;
	size_t wlen=0;
	size_t a;
	
	// contar los caracteres del codigo morse
	for(offset=code; *offset; offset++) {
		if(offset[0]!=LETTER_SEPARATOR) {
			wlen++;
		}
	}
	
	// reservar memoria para el buffer de texto
	if(!(textbuf=calloc(wlen+1,sizeof(wchar_t)))) {
		return NULL;
	}
	
	// obtener texto del codigo morse
	for(offset=code; *offset; offset++) {
		if(offset[0]!=LETTER_SEPARATOR) {
			textbuf[a++] = MorseToChar(offset[0]);
		}
	}
	
	return textbuf;
}
