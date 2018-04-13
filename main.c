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
		//printf("Nombre del vertice 1: %u\n",NombreDelVertice(g,1) );
		//printf("grado del vertice 1: %u\n",GradoDelVertice(g,1) );
		//printf("color del vertice 1: %u\n",ColorDelVertice(g,1) );
		//printf("color del vecino 0 del vertice 1: %u\n",ColorJotaesimoVecino(g,1,0) );
		//printf("nombre del vecino 0 del vertice 1: %u\n",NombreJotaesimoVecino(g,1,0) );
		//printf("Es bipartito: %u\n",Bipartito(g));
		//printf("cant colores %u\n", NumeroDeColores(g));
		for(u32 i= 0; i<10;i++)
			printf("cantida de colores NotSoGreedy: %u\n", NotSoGreedy(g,i));
		//for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			//printf("vertice: %u \tColor: %u\n",NombreDelVertice(g,i),ColorDelVertice(g,i) );
		tiempo_final = clock();
		segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
		printf("TIEMPO : %f\n",segundos);
		DestruccionDelGrafo(g);

}
