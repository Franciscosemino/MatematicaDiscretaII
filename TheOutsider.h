#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef unsigned int u32;
typedef struct _Vertice_t *PVertice;
typedef struct _Grafo_t *Grafo;


struct _Vertice_t {
    u32 nombre;
    u32 grado;
    u32 color;
    u32 index;
		u32 mem_vecinos;
		u32 tag;
    PVertice *vecinos;
};

struct _Grafo_t {
    u32 nro_vertices;
    u32 nro_lados;
    u32 nro_colores;
    PVertice vertices;
		bool *facil_busqueda;
    PVertice *orden;
    PVertice *orden_natural;
};
// Funciones Auxiliares de Carga del Grafo
/*----------------------------------------------------------------------------------------------------*/
PVertice BuscoOAgregoVert(Grafo g,u32 v_nombre);
void NuevoVecino(PVertice vert_u, PVertice vert_v);
/*----------------------------------------------------------------------------------------------------*/

// Funciones de Carga y Destrucción del Grafo
/*----------------------------------------------------------------------------------------------------*/
Grafo ConstruccionDelGrafo(); /* Alloca memoria para un Nuevo Grado leido por entrada estándar */
void DestruccionDelGrafo(Grafo G); /* Destruye G y libera la memoria alocada */
/*----------------------------------------------------------------------------------------------------*/
// Funciones de Información del Grafo
/*----------------------------------------------------------------------------------------------------*/
u32 NumeroDeVertices(Grafo G); /* Retorna el número de Vértices del grafo G */
u32 NumeroDeLados(Grafo G); /* Retorna el número de lados del grafo G */
u32 NumeroDeColores(Grafo G); /* Retorna el número de colores del grafo G */
/*----------------------------------------------------------------------------------------------------*/
// Funciones de Información del Vértice
/*----------------------------------------------------------------------------------------------------*/
u32 NombreDelVertice(Grafo G, u32 i); /* Devuelve el nombre real del vértice número i en el orden guardado en ese momento en G */
u32 ColorDelVertice(Grafo G, u32 i); /* Devuelve el color con el que está coloreado el vértice número i en el orden guardado en ese momento en G */
u32 GradoDelVertice(Grafo G, u32 i); /* Devuelve el grado del vértice número i en el orden guardado en ese momento en G */
u32 ColorJotaesimoVecino(Grafo G, u32 i,u32 j); /* Devuelve el color del vecino numero j del vértice número i en el orden guardado en ese momento en G */
u32 NombreJotaesimoVecino(Grafo G, u32 i,u32 j); /*Devuelve el nombre del vecino numero j del vértice nu ́mero i en el orden guardado en ese momento en G */
/*----------------------------------------------------------------------------------------------------*/

// Funcionesd de Ordenación
/*----------------------------------------------------------------------------------------------------*/
void OrdenNatural(Grafo G); /* Ordena los vértices en orden creciente de sus “nombres” reales */
void OrdenWelshPowell(Grafo G); /* Ordena los vértices de G de acuerdo con el orden Welsh-Powell */
void AleatorizarVertices(Grafo G,u32 semilla); /* Esta función ordena pseudoaleatoriamente los vértices de G, usando alguna función pseudoaleatoria que dependa determinísticamente de semilla. */
void ReordenManteniendoBloqueColores(Grafo G,u32 x); /* */
/*----------------------------------------------------------------------------------------------------*/

// Funciones de Coloreo
/*----------------------------------------------------------------------------------------------------*/
u32 NotSoGreedy(Grafo G,u32 semilla); /* Corre la variación de greedy que se indica mas abajo en G con el orden interno que debe estar guardado de alguna forma dentro de G. Devuelve el numero de colores que se obtiene. */
int Bipartito(Grafo G); /* Si k es el número de componentes conexas de G, devuelve k si G es bipartito, y −k si no */
/*----------------------------------------------------------------------------------------------------*/
