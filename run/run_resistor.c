/*
	Información de resistor (Ejemplo de uso)
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

#include <stdio.h>
#include <string.h>

#include "../resistor/resistor.h"

void PrintHelp()
{
	printf(
		"Uso: resistor [-axial|-smd] <codigo>\n"
		"\n"
		"Parametros:\n\n"
		"   -axial   Especifica un resistor axial\n"
		"   -smd     Especifica un resistor SMD\n"
		"   codigo   Codigo del resistor. Para los resistores\n"
		"            axiales esta determidada por sus bandas\n"
		"            de color. Puede ser una combinacion de\n"
		"            los siguientes valores.\n"
		"\n"
		"               a = Negro\n"
		"               b = Marron\n"
		"               c = Rojo\n"
		"               d = Naranja\n"
		"               e = Amarillo\n"
		"               f = Verde\n"
		"               g = Azul\n"
		"               h = Violeta\n"
		"               i = Gris\n"
		"               j = Blanco\n"
		"\n"
		"            Para los resitores SMD es una combinacion de\n"
		"            cifras (0-9) y 'R'. Este ultimo indica\n"
		"            punto decimal.\n"
		"\n"
		"Por ejemplo. El comando 'resistor -axial gfakc' da\n"
		"como resultado la informacion de un resistor axial\n"
		"de 65 omhs con 2 porciento de tolerancia.\n"
		);
}

int main(int argc, char **argv)
{
	int len, a;

	printf("Informacion de resistor\n");
	printf("Copyright (c) 2022 Oscar Elias\n\n");

	if(argc<2) {
		PrintHelp();
		return 0;
	}

	len=strlen(argv[2]);

	if(!(len>=3&&len<=5)) {
		printf("ERROR: Codigo invalido\n");
		return 0;
	}

	// obtener inforacion de resistencia axial
	if(!strcmp(argv[1],"-axial")) {
		COLORBAND *bands;
		RESISTORINFO *info;

		// crear buffer de bandas de color
		bands=calloc(len,sizeof(COLORBAND));
		if(!bands) return 0;
		for(a=0; a<len; a++) {
			switch(argv[2][a]) {
				case 'a': bands[a]=BLACK_BAND;  break;
				case 'b': bands[a]=BROWN_BAND;  break;
				case 'c': bands[a]=RED_BAND;    break;
				case 'd': bands[a]=ORANGE_BAND; break;
				case 'e': bands[a]=YELLOW_BAND; break;
				case 'f': bands[a]=GREEN_BAND;  break;
				case 'g': bands[a]=BLUE_BAND;   break;
				case 'h': bands[a]=VIOLET_BAND; break;
				case 'i': bands[a]=GREY_BAND;   break;
				case 'j': bands[a]=WHITE_BAND;  break;
				case 'k': bands[a]=GOLD_BAND;   break;
			}
		}

		if(!(info=GetResistorInfo(bands,len))) {
			printf("ERROR: Imposible obtener informacion del resistor\n");
			return 0;
		}

		// mostrar informacion de resitor
		printf("Resistor axial: %.0f omhs, %.0f%% de tolerancia\n",
			info->value,
			info->tolerance);

		free(info);
		free(bands);
	}

	// obtener informacion de resistencia SMB
	else if(!strcmp(argv[1],"-smd")) {
		SMBRESISTORINFO *info;

		if(!(info=GetSMBResistorInfo(argv[2]))) {
			printf("ERROR: Imposible obtener informacion\n");
		}

		printf("Resistor SMB: %.3f omhs\n",info->value);

		free(info);
	}

	else {
		printf("ERROR: Tipo invalido '%s'\n",argv[2]);
	}


	return 0;
}