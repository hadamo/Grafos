#include <stdlib.h>
#include <stdio.h>
/*
	Autor: Hadamo Egito
*/
typedef struct no
{
	int val;
	no *prox;
}vertice;
typedef struct grafo
{
	int v,e;
	vertice *adj;
}Grafo;

Grafo* criaGrafo(int v)
{
	Grafo *g = (Grafo*) malloc(sizeof(Grafo));
	g->v  = v;
	g->e = 0;
	g->adj = (vertice*)malloc(v*sizeof(vertice));
	return g;
}

vertice* novoVertice(int v)
{
	vertice *novo = (vertice*)malloc(sizeof(vertice));
	if(novo == NULL)
	{
		printf("Algo de errado não está certo, vertice não criado!\n");
		return NULL;
	}
	novo->val = v;
	novo->prox = NULL;
	return novo;
}

void insereAresta(Grafo *g, int v1, int v2)
{
	if(v1!=v2)//se nao for laco
	{
		vertice *p = g->adj[v1].prox;
		while(p!=NULL)
		{
			if(p->val == v2) break; //verifica se o vertice ja esta ligado
			p = p->prox; // para laco quando chegar no ultimo
		}
		if(p==NULL)
		{
			vertice *novo = novoVertice(v2);
			novo->prox = g->adj[v1].prox;
			g->adj[v1].prox = novo;
			g->e++;
		}
		p = g->adj[v2].prox
		while(p!=NULL)
		{
			if(p->val == v1) break; //verifica se o vertice ja esta ligado
			p = p->prox; // para laco quando chegar no ultimo
		}
		if(p==NULL)
		{
			vertice *novo = novoVertice(v1);
			novo->prox = g->adj[v2].prox;
			g->adj[v2].prox = novo;
		}
	}
}

void imprimeGrafo(Grafo *g)
{
	if(g!=NULL)
	{
		int i,j,tam= g->v,e= g->e;
		vertice *v;
		
		for(i=0;i<v;++i)
		{
			printf("\nv%d ->",g->adj[i].val );
			v = g->adj[i].prox
			while(v!=NULL)
			{
				printf(" %d |",v->val);
				v = v->prox;
			}

		}

	}
}
calcular grau
imprimir estrutura
veirifcar se seq de grau dos vertices de dois grafos sao iguais
funçao main pra testar td