#include <stdlib.h>
#include <stdio.h>
/*
	Autor: Hadamo Egito
*/
//estrutura de no para vertices
typedef struct no
{
	int val;
	no *prox;
}vertice;
//estrutura do grafo com num de vertices e arestas e lista de adj
typedef struct grafo
{
	int v,e;
	vertice *adj;
}Grafo;

//função para criar grafo, dado numero de vertices v
Grafo* criaGrafo(int v)
{
	Grafo *g = (Grafo*) malloc(sizeof(Grafo));
	if (g!=NULL)
	{
		g->v  = v;
		g->e = 0;
		g->adj = (vertice*)malloc(v*sizeof(vertice));
	}
	return g;
}
//função para criar vertice dado valor do vertice v
vertice* novoVertice(int v)
{
	vertice *novo = (vertice*)malloc(sizeof(vertice));
	if(novo == NULL)
	{
		printf("Algo de errado não está certo, vertice não criado!\n");
	}else
	{
		g->v  = v;
		g->e = 0;
		g->adj = (vertice*)malloc(v*sizeof(vertice));
	}
	return novo;
}
//função para criar aresta entre dois vertices distintos num grafo
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
		/*se terminou de percorrer lista e não achou ocorrencia
		do novo vertice, insere o vertice na lista
		so verifica uma vez pois se trata de grafo simples
		*/
		if(p==NULL)
		{
			//insere novo vertice na adj de v1
			vertice *novo = novoVertice(v2);
			novo->prox = g->adj[v1].prox;
			g->adj[v1].prox = novo;
			g->e++;
			// repete o processo para v2
			novo = novoVertice(v1);
			novo->prox = g->adj[v2].prox;
			g->adj[v2].prox = novo;
		}
	}
}

void imprimeGrafo(Grafo *g)
{
	if(g!=NULL)
	{
		int i;
		vertice *w;
		printf("Grafo com %d vertices e %d arestas",g -> v, g -> e );
		for(i=0 ; i < g->v ; ++i)
		{
			printf("\nv%d ->",i);
			w = g -> adj[i].prox;
			while(w != NULL)
			{
				printf(" %d |",w -> val);
				w = w -> prox;
			}
			printf("¬");
		}
	}
}
//função que calcula o grau de um vertice v num simples grafo g
int calcularGrau(Grafo *g, int v)
{
	vertice *w =  g -> adj[v].prox;
	int grau = 0;
	while(w != NULL)
	{
		grau++;
		w = w -> prox;
	}	
	return grau;
}

int sequenciaGrau(Grafo *g, Grafo *h)
{
	int grauG = 0, 
		grauH
		grauH = 0
		v = g -> v,
		w = g -> v,
		i = 0,
		resp = 0;
	while(grauG == grauH)
	{
		if(i < v && i < w)
		{
			grauG = calcularGrau(g, g -> adj[i]);
			grauH = calcularGrau(h, h -> adj[i]);
		}else break;
	}
	if(grauG == grauH)
	{
		printf("Sequencia de grau dos vertices entre os grafos sao iguais\n");
		resp = 1 ;
	}else printf("Sequencia de grau dos vertices entre os grafos sao diferentes\n");
	return resp;

}

void main()
{

}
/*
calcular grau
imprimir estrutura
veirifcar se seq de grau dos vertices de dois grafos sao iguais
funçao main pra testar td
*/