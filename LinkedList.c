/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

void LLconsecutiva(linklist ll, u32 n){
	ll->next= NULL;
	ll->value = 1;
	node cursor=ll;
	for(u32 i=2;i<=n;i++){
		cursor->next=(node)calloc(1,sizeof(struct _Node_t));
		cursor=cursor->next;
		cursor->next=NULL;
		cursor->value= i;
	}
}


bool FindAndRemove(linklist ll,u32 valuetoremove){
	linklist cursor = ll;
	while(cursor->next!=NULL){
		if(cursor->next->value==valuetoremove){
			linklist aux=cursor->next;
			cursor->next=aux->next;
			aux->next=NULL;
			free(aux);
			aux=NULL;
			return true;
		}
		cursor=cursor->next;
	}
	return false;

}
void DestroyLL(linklist ll){
	node cursor = ll;
	node next;
	while(cursor!=NULL){
		next= cursor->next;
		cursor->next=NULL;
		free(cursor);
		cursor = next;
	}
	ll = NULL;
}
u32 randmon_color_ll(linklist ll,u32 index){
	linklist cursor = ll;
	u32 color_return;
	if(index==0){
		color_return=ll->value;
		return color_return;
	}
	for(u32 i=0;i<index;i++){
		cursor=cursor->next;
	}
	color_return=cursor->value;
	return color_return;
}
