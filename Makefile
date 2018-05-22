
prueba: TheOutsider.h OrdenGrafo.c LinkedList.c InfoVertices.c InfoVertices.c InfoGrafos.c CreacionDestruccionGrafo.c Coloreo.c Cola.c
		gcc -Wall -Wextra -std=c99 -O3 -ggdb3 -o prueba *.c #-DNDEBUG

clean:
		rm prueba
