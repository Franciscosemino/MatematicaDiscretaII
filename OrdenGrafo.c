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
   return ( (int)a - (int)b );
}

void OrdenNatural(Grafo G) {
    qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunc);
}


/* -----------------------------------------------------------------------------*/

void OrdenWelshPowell(Grafo G) {
  u32 grande;
  PVertice temp;
  for(u32 i = 0; i < (G->nro_vertices)-1 ;i++){
      grande = i;
      for (u32 d = i + 1; d < G->nro_vertices; d++) {
          if ((G->vertices[grande]).grado < (G->vertices[d].grado)) {
              grande = d;
              // busco el vertice con valencia mas grande
          }
      }
      if (grande != i) {
          // si el mas grande es distinto a donde estoy parado entonces lo swapeo
          temp = G->orden[i];
          G->orden[i] = G->orden[grande];
          G->orden[grande] = temp;
      }
  }
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
void BloquesCero(Grafo G) {
  u32 grande;
  PVertice temp;
  for (u32 i = 0; i < (G->nro_vertices)-1 ;i++){
      grande = i;
      for (u32 d = i + 1; d < G->nro_vertices; d++) {
          if (G->orden[grande]->color < G->orden[d]->color) {
              grande = d;
              // busco el vertice con color mas grande
          }
      }
      if (grande != i) {
          // si el mas grande es distinto a donde estoy parado entonces lo swapeo
          temp = G->orden[i];
          G->orden[i] = G->orden[grande];
          G->orden[grande] = temp;
      }
  }
}

void ReordenManteniendoBloqueColores(Grafo G,u32 x) {
    u32 color_usado;
    PVertice temp;
    PVertice *mi_orden = G->orden;
    u32 size = G->nro_vertices;
    u32 nro_colores = G->nro_colores;
    u32 n_veces = 0;;
    if (x == 0)
        BloquesCero(G);
    else if (x == 1)
        printf("ReordenManteniendoBloqueColores con 1 - NO LO TENEMOS \n");
    else if (x > 1)
        printf("ReordenManteniendoBloqueColores con mas grande que uno - NO LO TENEMOS \n");
}
/* -----------------------------------------------------------------------------*/

