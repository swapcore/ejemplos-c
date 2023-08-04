#	Makefile de Ejemplos C
#	Copyright (c) 2022 Oscar El�as
#	
#	This file is part of Ejemplos C.
#	
#	Ejemplos C is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published
#	by the Free Software Foundation, either version 3 of the License,
#	or (at your option) any later version.
#	
#	Ejemplos C is distributed in the hope that it will be useful, but
#	WITHOUT ANY WARRANTY; without even the implied warranty of 
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#	General Public License for more details.
#	
#	You should have received a copy of the GNU General Public License
#	along with Ejemplos C. If not, see 
#	<https://www.gnu.org/licenses/>.

# rhombus
run_rhombus:
	gcc -o rhombus run/run_rhombus.c rhombus/rhombus.c

# textrect
run_textrect:
	gcc -o textrect run/run_textrect.c textrect/textrect.c

# romanconv
run_romanconv:
	gcc -o romanconv run/run_romanconv.c romanconv/romanconv.c

# fibonacci
run_fibonacci:
	gcc -o fibonacci run/run_fibonacci.c fibonacci/fibonacci.c

# tempconv
run_tempconv:
	gcc -o tempconv run/run_tempconv.c tempconv/tempconv.c