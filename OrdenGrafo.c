/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

/* -----------------------------------------------------------------------------*/
/*
int CompOrdenNatural (const void *a, const void *b) {
   	PVertice fst = (PVertice)a;
    PVertice snd = (PVertice)b;
    if(fst->nombre > snd->nombre) return 1;
    if(fst->nombre < snd->nombre) return -1;
    return 0;
}

void OrdenNatural(Grafo G) {
	qsort(G->orden, G->nro_vertices, sizeof(PVertice), CompOrdenNatural);
}
*/
int cmpfunc (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = ( vertice_1->nombre )-(vertice_2->nombre);
	return resultado;
}

void OrdenNatural(Grafo G) {
    qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunc);
}

/* -----------------------------------------------------------------------------*/

int cmpfuncgrado (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = ( vertice_2->grado )-(vertice_1->grado);
	return resultado;
}
void OrdenWelshPowell(Grafo G){
	qsort(G->orden,G->nro_vertices,sizeof(PVertice), cmpfuncgrado);
}
/* -----------------------------------------------------------------------------*/
// FUNCIONA

bool sonTodosDistintos(PVertice* a, u32 size) {
  bool b = true;
  for (u32 i = 0; i < size; i++) {
    for (u32 j = 0; j < size && j != i; j++) {
      if (a[i] != a[j]) {
        b = b && true;
      } else {
        false;
      }
    }
  }
  return b;
}

void AleatorizarVertices(Grafo G,u32 semilla) {
  //seed = semilla;
  PVertice temp = NULL;
  u32 n_rand;

  for (int i = G->nro_vertices-1; i >= 0; i--) {
    n_rand = mi_rand(semilla) % (i+1);
    temp = G->orden[i];
    G->orden[i] = G->orden[n_rand];
    G->orden[n_rand] = temp;
  }
  assert(sonTodosDistintos(G->orden, G->nro_vertices));
}

/* -----------------------------------------------------------------------------*/

int cmpfunccolor (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = ( vertice_2->color )-(vertice_1->color);
	return resultado;
}

int cmpfuncaleat(const void * a, const void * b){
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
	vertice_1->aleatorio = mi_rand(vertice_1->color)-(vertice_1->x_aleatorio);
	vertice_2->aleatorio = mi_rand(vertice_2->color)-(vertice_2->x_aleatorio);
	int resultado = (vertice_1->aleatorio>vertice_2->aleatorio);
	return resultado;

}
void ReordenManteniendoBloqueColores(Grafo G,u32 x) {
    if (x == 0)
        qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccolor);
    else if (x == 1)
      printf("nada\n" );
      // for (u32 i = nro_colores; i>0; i--) {
      //   color_usado = elQueMasAparece(mi_orden, size, i);
      //   cantidad = NumeroDeVerticesDeColor(mi_orden, size, color_usado);
      //   printf("color_usado: %u cantidad: %u size: %u mi_orden: %u\n", color_usado, cantidad, size, mi_orden);
      //   // DO THE SORTING
      //   for (u32 j = 0; j < size-1 ;j++) {
      //     for (u32 x = j+1; x < size; x++) {
      //       if (G->orden[x]->color == color_usado) {
      //         n = x;
      //       }
      //     }
      //     temp = G->orden[j];
      //     G->orden[j] = G->orden[n];
      //     G->orden[n] = temp;
      //   }
      //   mi_orden = mi_orden + (cantidad - 1);
      //   size = size - cantidad;
      // }
    else if (x > 1) {
			for(u32 i = 0; i < G->nro_vertices; i++){
				G->vertices[i].x_aleatorio= x;
			}
			qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfuncaleat);
    }
}
/* -----------------------------------------------------------------------------*/
