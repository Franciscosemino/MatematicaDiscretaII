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
