/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

int main(){
		clock_t tiempo_inicio;
		clock_t tiempo_final;
		double segundos;
		tiempo_inicio = clock();
		Grafo g = ConstruccionDelGrafo();


		printf("cant vertices %u\n",NumeroDeVertices(g) );
		printf("cant lados %u\n", NumeroDeLados(g));
		printf("cant colores %u\n", NumeroDeColores(g));
		printf("Nombre del vertice 1: %u\n",NombreDelVertice(g,1) );
		printf("grado del vertice 1: %u\n",GradoDelVertice(g,1) );
		printf("color del vertice 1: %u\n",ColorDelVertice(g,1) );
		printf("color del vecino 0 del vertice 1: %u\n",ColorJotaesimoVecino(g,1,0) );
		printf("nombre del vecino 0 del vertice 1: %u\n",NombreJotaesimoVecino(g,1,0) );
		printf("Es bipartito: %u\n",Bipartito(g));
		printf("cant colores %u\n", NumeroDeColores(g));
		for(u32 i= 0; i<10;i++) // 10 Cortidas de NotSoGreedy
			printf("cantida de colores NotSoGreedy: %u\n", NotSoGreedy(g,i));

/* ------------------------------- CUESTIONES DE ORDEN -------------------------------*/

/*--------------------------------------------------------------- */
		printf("Sin aplicar Orden\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy SIN ORDENAR con semilla 1: %u\n", NotSoGreedy(g,1));

/*--------------------------------------------------------------- */

		OrdenNatural(g);
		printf("Orden Natural\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy Inmediatamente despues de aplicar Orden Natural con semilla 1 : %u\n", NotSoGreedy(g,1));
/*--------------------------------------------------------------- */

		OrdenWelshPowell(g);
		printf("Orden Orden Wesh Powell\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("Nombre: %u Grado: %u\n", g->orden[i]->nombre, g->orden[i]->grado);
		printf("NotSoGreedy Inmediatamente despues de aplicar Wesh Powell con semilla 1 : %u\n", NotSoGreedy(g,1));

/*--------------------------------------------------------------- */

		AleatorizarVertices(g, 1);
		printf("AleatorizarVertices\n");
		for(u32 i = 0; i< NumeroDeVertices(g); i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy Inmediatamente despues de aplicar Aleatorizar Vertices con semilla 1 : %u\n", NotSoGreedy(g,1));
/*--------------------------------------------------------------- */

		ReordenManteniendoBloqueColores(g, 0);
		for(u32 i = 0; i< NumeroDeVertices(g); i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy Inmediatamente despues de aplicar ReordenManteniendoBloqueColores con semilla 0 y NotSoGreedy con semilla 1: %u\n", NotSoGreedy(g,1));
		ReordenManteniendoBloqueColores(g, 1);
		//for(u32 i = 0; i< NumeroDeVertices(g); i++)
			//printf("%u\n", g->orden[i]->nombre);
		ReordenManteniendoBloqueColores(g, 2);
		//for(u32 i = 0; i< NumeroDeVertices(g); i++)
			//printf("%u\n", g->orden[i]->nombre);

		/* --------------------------------------*/

		tiempo_final = clock();
		segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
		printf("TIEMPO : %f\n",segundos);
		DestruccionDelGrafo(g);

}
