#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define b branco
#define c cinza
#define p preto
#define MAX 12

typedef struct s{
	int indice;
	struct s* prox;
} VERTICE;


typedef struct s{
	VERTICE* adj[MAX];
	char [] cor; /*b=branco c=cinza p=preto*/
	int pai[MAX];
	int minor[MAX];
	int ordem[MAX];
	int ord;
} GRAFO;

void inicializar(GRAFO* G){
	int i;
	G->ord=0;
	for(i=1; i<=12; i++){
		G->adj=NULL;
		G->cor[i]=b;
		G->pai[i]=0;
		G->minor[i]=i;
		G->ordem[i]=0;
	}
}


void inserir(GRAFO G, VERTICE* v; int adjacencia){
	VERTICE* adjacente =(VERTICE*)malloc(sizeof(VERTICE));
	v->adj[v->indice]=
	G->adj[indice]=indice;
}




void DFS1(GRAFO* G, VERTICE* y, int* ord){
	VERTICE* p=G->adj[y];
	while(p!=NULL){
		int u=p->indice;
		if(cor[u]==b){
			cor[u]=c;
			*ord++;
			ordem[u]=ord;
			minor[u]=ordem[u];
			pai[u]=y->indice;
			DFS1(G, u, &ord);
		}
		p=p->prox;
	}
}

void DFS2(GRAFO* G, VERTICE* z){
	VERTICE* p=G->adj[z];
	int i;
	while(p!=NULL){
		int u=p->indice;
		if(pai[u]==z->indice) DFS2(G,p);
		p=p->prox;
	}

	p=G->adj[z];
	while(p!=NULL){
		u=p->indice;
		if( (u!=pai[z->indice]) && (minor[u]<minor[z->indice]) ) minor[z->indice]=minor[u];
	}

	}




bool DFST(GRAFO* G){
	int i;
	for(i=1; i<=12; i++){
		pai[i]=0;
		cor[i]=b;
		minor[i]=i;
		ordem[i]=0;
	}

	int ord=0;
	//VERTICE* vi=1;
	cor[i]=c;
	ord++;
	ordem[i]=ord;
	DFS1(G,v);

	if(ord==i){
		minor[i]=ordem[i];
		DFS2(G,v);
	}

	bool biconexo=true;
	for(i=1; i<=12; i++){
		if( && ordem[i]==minor[i]){
			biconexo=false;
		}
	}

	return biconexo;
}




int main(){
	GRAFO G;
	VERTICE* v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12;
	inserir(G, v1, 1);
	inserir(G,v2,2);
	inserir(G, v3,3);
	inserir(G,v4,4);
	inserir(G,v5,5);
	inserir(G,v6,6);
	inserir(G,v7,7);
	inserir(G,v8,8);
	inserir(G,v9,9);
	inserir(G,v10,10);
	inserir(G,v11,11);
	inserir(G,v12,12);

	GRAFO* G;
	G->adj[1]=1;
	







	return 0;
}