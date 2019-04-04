//Gabriel Andre Melo de Oliveira Silva
//Numero USP: 10724312

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define B 0
#define C 1
#define P 2
#define MAX 13

typedef struct s{
	int indice;
	struct s* prox;
} VERTICE;


typedef struct{
	VERTICE* adj[MAX];
	int cor[MAX];
	int pai[MAX];
	int minor[MAX];
	int ordem[MAX];
	int ord;
} GRAFO;

void inicializar(GRAFO* G){
	int i;
	G->ord=0;
	for(i=1; i<MAX; i++){
		G->adj[i]=NULL;
		G->cor[i]=B;
		G->pai[i]=0;
		G->minor[i]=MAX-1;
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
	VERTICE* p;
	for(i=1; i<MAX; i++){
		p = G->adj[i];
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
        if(G->cor[p->indice]==B){
			G->cor[p->indice]=C;
			G->ordem[p->indice]=++(G->ord);
			G->minor[p->indice]=G->ord;
			G->pai[p->indice]= y;
			DFS1(G, p->indice);
		}
		p=p->prox;
	} 
	G->cor[y]=P;
}

void DFS2(GRAFO* G, int z){
	VERTICE* p= G->adj[z];
	while(p){
		if(G->pai[p->indice]==z){
		    DFS2(G, p->indice);
		}
		p=p->prox;
	}

	p=G->adj[z];
	while(p){
		if(p->indice!=G->pai[z] && G->minor[p->indice] < G->minor[z]){
			G->minor[z]=G->minor[p->indice];
		}
		p=p->prox;
	}
}

bool DFST(GRAFO* G){
	G->cor[1]=C;
	G->ord=G->ord+1;
	G->ordem[1]=G->ord;
	G->minor[1]=G->ord;
	DFS1(G, 1);
	bool biconexo=true;
	if(G->ord==MAX-1){
		G->minor[1]=G->ordem[1];
		DFS2(G, 1);
		int i;
		for(i=1; i<MAX; i++){
			printf("O vertice %d tem ordem %d e minor %d\n", i, G->ordem[i], G->minor[i]);
			if(i!=1 && G->ordem[i]==G->minor[i]){
				printf("A ARESTA %i - %i EH CRITICA\n",G->pai[i],i);
				biconexo=false;
			}
		}
	}
	return biconexo;
}


int main(){
	GRAFO* G=(GRAFO*)malloc(sizeof(GRAFO));
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
	if(DFST(G)==true) printf("O GRAFO EH BICONEXO\n");
	else printf("O GRAFO NAO EH BICONEXO\n");
	return 0;
}
