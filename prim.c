#include <stdio.h>
#include <stdlib.h>
/*
	Autor: Hádamo Egito
	Implementação de Algoritmo Prim
*/
//////////////////Estruturas////////////////////////
typedef struct vert
{
	int val,peso;
	struct Vertice *prox;
}Vertice;
//estrutura do grafo com num de vertices e arestas e lista de adj
typedef struct grafo
{
	int v,e;
	Vertice *adj;
}Grafo;
//heap de prioridade minima para vertices
typedef struct heap
{
	//vetor de vertices, preciso pois cada vertice é um ponteiro do tipo Vertice
	Vertice **v;
	int tamHeap;
}Heap;
//estrutura para arvore geradora minima
//com predecessores e estimativas.
//no algoritmo prim deve haver um heap minimo de 
typedef struct arvmin
{
	Vertice *pred;
	int d;
}*ArvoreGMin;
/////////////////////PROTOTIPOS/////////////////////
// cria novo grafo E: qtd de vertices, S: ponteiro de grafo
Grafo* criaGrafo(int);
// cria novo vertice para lista de adj, E: num do vertice, peso da aresta, S: ponteiro de vertice
Vertice* novoVertice(int,int);
// insere aresta na lista de adj de um grafo, E: grafo, 2 vertices da aresta, peso, S: nao possui 
void insereAresta(Grafo*,int,int,int);
// cria novo heap para vertices de um grafo, E: grafo, S: ponteiro de heap
Heap* criaHeap(Grafo*);
//sobe vertices no heap recursivamente de acordo, mantendo a invariante de acordo com as estimativas
//E: heap, Arv.Ger.Min, inteiro para posicao S: nao possui
void sobeHeap(Heap*,ArvoreGMin*, int pos);
//desce vertices no heap recursivamente de acordo, mantendo a invariante de acordo com as estimativas
//E: heap, Arv.Ger.Min, inteiro para posicao S: nao possui
void desceHeap(Heap*,ArvoreGMin*, int pos);
// inicia heap ja criado, com prioridade minima das estimativas presentes na Arv.Ger.Min
// E: heap e Arv.Ger.Min, S: nao possui
void iniciaHeap(Heap*,ArvoreGMin*);
//retira o vertice no topo do heap, E: heap e Arv.Ger.Min, S: vertice retirado
Vertice* removeMin(Heap*, ArvoreGMin*);
//verifica se vertice esta no heap, E: Heap e vertice, S: inteiro = 1 se true, 0 se false
int pertenceHeap(Heap*,Vertice*);
// cria e inicia estrutura para Arv.Ger.Min a partir dos vertices de um grafo
//E: grafo, S: ponteiro de estrutura de arvore
ArvoreGMin* criaArvore(Grafo*);
//Encontra UMA Arv.Ger.Min de um grafo para determinado vertice como raiz.
//E: Grafo e vertice raiz, S: ponteiro de estrutura de arvore
ArvoreGMin* prim(Grafo*,int);
////////////////////////////////////////////////////
////////////////////////GRAFO///////////////////////
Grafo* criaGrafo(int v)
{
	Grafo *g = (Grafo*) malloc(sizeof(Grafo));
	if (g!=NULL)
	{
		g->v  = v;
		g->e = 0;
		g->adj = (Vertice*)calloc(v,sizeof(Vertice));
		//todas as adjacencias estarao vazias neste momento
		for (int i = 0; i <v; ++i)
		{
			g->adj[i].prox = NULL;
		}
	}
	return g;
}
Vertice* novoVertice(int v, int peso)
{
	Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
	if(novo == NULL)
	{
		printf("Algo de errado não está certo, Vertice não criado!\n");
	}else
	{
		novo -> val = v;
		novo -> peso = peso;
		novo -> prox = NULL;
	}
	return novo;
}
void insereAresta(Grafo *g, int v1, int v2,int peso)
{
	if(v1!=v2)//se nao for laco
	{
		Vertice *p = g->adj[v1].prox;
		while(p!=NULL)
		{
			if(p->val == v2) break; //verifica se o Vertice ja esta ligado
			p = p->prox;
		}
		/*se terminou de percorrer lista e não achou ocorrencia
		do novo Vertice, insere o Vertice na lista
		so verifica uma vez pois se trata de grafo simples
		*/
		if(p==NULL)
		{
			//insere novo Vertice na adj de v1
			Vertice *novo = novoVertice(v2,peso);
			novo->prox = g -> adj[v1].prox;
			g->adj[v1].prox = novo;
			//incrementa num de arestas do grafo
			g->e++;
			// repete o processo para v2
			novo = novoVertice(v1,peso);
			novo->prox = g->adj[v2].prox;
			g->adj[v2].prox = novo;
		}
	}
}
////////////////////////////////////////////////////
////////////////////////HEAP////////////////////////
Heap* criaHeap(Grafo *g)
{
	Heap *h = (Heap*)calloc(g->v,sizeof(Heap));
	if(h!= NULL)
	{
		h ->v = (Vertice**)calloc(g->v,sizeof(Vertice*));
		for (int i = 0; i < g->v; ++i)
		{
			h->v[i] == NULL
		}
	}
	return h;
}
void sobeHeap(Heap *h, ArvoreGMin *arv, int pos)
{

}
void desceHeap(Heap *h, ArvoreGMin *arv, int pos)
{

}
void iniciaHeap(Heap *h, ArvoreGMin *arv)
{

}
////////////////////////////////////////////////////
////////////////////////ARVGMIN/////////////////////
ArvoreGMin* criaArvore(Grafo *g)
{
	ArvoreGMin *arv = (ArvoreGMin*)calloc(g->v,sizeof(ArvoreGMin));
	if(arv != NULL)
	{
		for (int i = 0; i < g->v; ++i)
		{
			arv[i] -> pred=NULL;
			arv[i] -> d = INT_MAX; 
		}
	}
	return arv;
}
////////////////////////////////////////////////////
////////////////////////PRIM////////////////////////
ArvoreGMin* prim(Grafo *g, int r)
{
	Vertice *u;
	ArvoreGMin *arv = criaArvore(g);
	arv[r]->d =0;
	Heap *Q = criaHeap(g);
	while(Q->size > 0)
	{
		u = removeMin(Q);
		for (Vertice v = u->prox; v!=NULL; v = v->prox)
		{
			if(pertenceHeap(Q,v) && (v->peso < arv[u->val]->d) )
			{
				arv[v->val]->pred = u;
				arv[v->val]->d = v->peso;
			}
		}
	}
	return arv;
}
////////////////////////////////////////////////////
////////////////////////MAIN////////////////////////
void main()
{

}
////////////////////////////////////////////////////