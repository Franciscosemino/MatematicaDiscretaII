/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com 
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

u32 NombreDelVertice(Grafo G, u32 i){
	return G->vertices[i].nombre;
}
u32 ColorDelVertice(Grafo G, u32 i){
	return G->vertices[i].color;
}
u32 GradoDelVertice(Grafo G, u32 i){
	return G->vertices[i].grado;
}
u32 ColorJotaesimoVecino(Grafo G, u32 i,u32 j){
	return G->vertices[i].vecinos[j]->color;
}
u32 NombreJotaesimoVecino(Grafo G, u32 i,u32 j){
	return G->vertices[i].vecinos[j]->nombre;
}
u32 GradoJotaesimoVecino (Grago G, u32 i, u32 j) {
  return G->vertices[u].vecinos[j]->grado;
}
u32 NumeroDeVerticesDeColor(Grafo G, u32 i) {
  u32 count = 0;
  for (u32 j = 0; j < G->nro_vertices; j++) {
    if (G->vertices[j].color == i) {
      count++;
    }
  }
  return count;
}
