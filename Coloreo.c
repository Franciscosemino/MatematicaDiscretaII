/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

u32 mi_rand(u32 semilla) {
	if(semilla==0){
		semilla+=217;
	}
   u32 bit;
	 u32 seed = semilla;
	 bit  = ((seed >> 0) ^ (seed >> 2) ^ (seed >> 3) ^ (seed >> 5) ) & 1;
   return seed =  (seed >> 1) | (bit << 31);
}

u32 NotSoGreedy(Grafo G, u32 semilla) {
		u32 seed = semilla;
		u32 n = NumeroDeVertices(G);
    u32 color;
    u32 color_maximo = 1;
    bool colores_usados[n+1];
    u32 grado = 0;
		bool use_rand=false;

    G->orden[0]->color = 1;
    for (u32 u = 1; u < n; u++) {
			memset(colores_usados, false, (n+1)*sizeof(bool));
			grado = G->orden[u]->grado;
      for (u32 i = 0; i < grado; i++) {
        color = G->orden[u]->vecinos[i]->color;
        if (color!=0) {
            colores_usados[color] = true;
        }
      }
      for (u32 j = 1; j < n + 1; j++) {
        if (!colores_usados[j]) {
					if(j>=color_maximo){
						G->orden[u]->color=j;
						color_maximo = j;
						break;
					}else if(j<color_maximo){
							use_rand= true;
							break;
					}
				}
      }
			if(use_rand){
				bool pintado=false;
				u32 color_a_usar = 0;
				u32 x = seed;
				seed = mi_rand(x);
				color_a_usar = seed % color_maximo;
				if(color_a_usar==0){
					color_a_usar++;
				}
				while(!pintado){
					if(!colores_usados[color_a_usar]){
						G->orden[u]->color = color_a_usar;
						pintado = true;
					}else{
						if(color_a_usar>=color_maximo){
							color_a_usar=1;
						}else{
							color_a_usar++;
						}
					}
				}

			}

  }
	G->nro_colores=color_maximo;
	return color_maximo;
}



int Bipartito (Grafo G) {
		PVertice x;
    PVertice vertice = NULL;
    u32 indice = 0;
    u32 n = G->nro_vertices;
    for(u32 i = 0; i < n; i++) {
        G->vertices[i].color = 0;
    }
    u32 vertices_coloreados = 0;
    while (vertices_coloreados < n) {
        x = &G->vertices[indice];
        if(x->color == 0) {
            x->color = 1;
            vertices_coloreados++;
						Queue q = calloc(1, sizeof(Queue));
						q->head = -1;
						q->tail = -1;
				    q->theQueue = calloc(n, sizeof(PVertice));
            Enqueue(q, x);
            // While para desencolar q
            while(!isEmpty(q)) {
                vertice = Dequeue(q);
                // For para recorrer los vecinos.
                for(u32 i = 0; i < vertice->grado; i++) {
                    // Si el vecino no tiene color, se encola y se colorea.
                    if(vertice->vecinos[i]->color == 0) {
                        Enqueue(q, vertice->vecinos[i]);
                        vertice->vecinos[i]->color = (3 - vertice->color);
                        //aumento los vertices coloreados
                        vertices_coloreados++;
                    }
                    // Si un vecino ya tenia el mismo color entonces no es bipartito. Hago return 0
                    else if (vertice->color == vertice->vecinos[i]->color) {
                        DestruirQueue(q);
                        return 0;
                    }
                }
            }
            DestruirQueue(q);
        }
        indice++;
    }

    // For que revisa que sea un coloreo propio.
    for(u32 i = 0; i < n; i++) {
        vertice = &G->vertices[i];
        for(u32 j = 0; j < vertice->grado; j++) {
            if(vertice->color == vertice->vecinos[j]->color)
                return -1;
        }
    }
		G->nro_colores=2;
    return 1;
}
