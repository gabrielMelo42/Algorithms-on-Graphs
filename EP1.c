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


typedef struct{
	VERTICE* adj[MAX];
	char cor[MAX]; /*b=branco c=cinza p=preto*/
	int pai[MAX];
	int minor[MAX];
	int ordem[MAX];
	int ord;
} GRAFO;

void inicializar(GRAFO* G){
	int i;
	G->ord=0;
	for(i=1; i<=12; i++){
		G->adj[i]=NULL;
		G->cor[i]='b';
		G->pai[i]=0;
		G->minor[i]=MAX;
		G->ordem[i]=0;
	}
}


void inserir(GRAFO* G, int eu, int adjacencia){
	VERTICE* vert=(VERTICE*)malloc(sizeof(VERTICE));
	vert->indice=adjacencia;
	vert->prox=NULL;

	VERTICE* aux;
	aux=G->adj[eu];
	if(aux){
		while(aux->prox){
			aux=aux->prox;
		}
		aux->prox=vert;
	}

	else G->adj[eu]=vert;
}

void imprimir(GRAFO* G){
	int i;
	for(i=1; i<=12; i++){
		VERTICE* p = G->adj[i];
		printf("%d tem como adjacentes ", i);
		while(p!=NULL){
			printf("%d ", p->indice);
			p=p->prox;
		}
		printf("\n");
	}
}




void DFS1(GRAFO* G, int y){
	VERTICE* p= G->adj[y];
	while(p){
		int u=p->indice;
		if(G->cor[u]=='b'){
			G->cor[u]='c';
			G->ord++;
			G->ordem[u]= G->ord;
			G->minor[u]= G->ord;
			G->pai[u]= y;
			DFS1(G, u);
		}
		p=p->prox;
	} G->cor[y]='p';
}

void DFS2(GRAFO* G, int z){
	VERTICE* p= G->adj[z];
	int u;
	while(p){
		u=p->indice;
		if(G->pai[u]==z) DFS2(G, u);
		p=p->prox;
	}

	p=G->adj[z];
	while(p){
		u=p->indice;
		if(u!=G->pai[z] && G->minor[u] < G->minor[z]){
			G->minor[z]=G->minor[u];
		}
		p=p->prox;
	}
}

	




bool DFST(GRAFO* G){
	/*int i;
	for(i=1; i<=12; i++){
		pai[i]=0;
		cor[i]='b';
		minor[i]=i;
		ordem[i]=0;
	}

	int ord=0;*/
	
	G->cor[1]='c';
	G->ord++;
	G->ordem[1]=G->ord;
	DFS1(G, 1);

	if(G->ord==MAX){
		G->minor[1]=G->ordem[1];
		DFS2(G, 1);
	}

	bool biconexo=true;
	int i;
	for(i=1; i<=12; i++){
		if(i==1 && G->ordem[i]==G->minor[i]) biconexo=false;
	}
	return biconexo;
}



int main(){
	GRAFO* G;
	inicializar(G);
	inserir(G, 1, 2);
	inserir(G, 1, 3);
	inserir(G, 2, 1);
	inserir(G, 2, 4);
	inserir(G, 2, 5);
	inserir(G, 3, 1);
	inserir(G, 3, 5);
	inserir(G, 4, 2);
	inserir(G, 4, 6);
	inserir(G, 4, 7);
	inserir(G, 5, 2);
	inserir(G, 5, 3);
	inserir(G, 5, 6);
	inserir(G, 6, 4);
	inserir(G, 6, 5);
	inserir(G, 7, 4);
	inserir(G, 7, 8);
	inserir(G, 7, 9);
	inserir(G, 7, 12);
	inserir(G, 8, 7);
	inserir(G, 8, 9);
	inserir(G, 9, 7);
	inserir(G, 9, 10);
	inserir(G, 10, 9);
	inserir(G, 10, 11);
	inserir(G, 10, 12);
	inserir(G, 11, 9);
	inserir(G, 11, 10);
	inserir(G, 12, 7);
	inserir(G, 12, 10);
	imprimir(G);
	DFST(G);
	return 0;
}