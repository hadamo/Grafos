#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int v,e,**adj;
}Grafo;

int **alocaMatriz(int r, int c, int val)
{
    int i,j,
    **m = (int**)malloc(c * sizeof(int*));
    for(i=0;i < r;i++)
    {
        m[i] = (int*) malloc(c*sizeof(int));
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        {
          m[i][i] = val;
        }
    }
    return m;
}

Grafo *criaGrafo(int v)
{
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->v = v;
    g->e = 0;
    g->adj = alocaMatriz(v,v,0);
    return g;
}
void insereAresta( Grafo *g, int v, int w)
{
	if(v!= w && g->adj[v][w]==0)
	{
		g->adj[v][w]=1;
		g->adj[w][v]=1;
		g->e++;
	}
	printf("Inserida aresta \n");
}
void imprime(Grafo *g)
{
	int i,j, r;
	if(g)
	{
		 r= g -> v;
		printf("G|");
		for(int i=0;i<r;++i)
		{
			printf("v%d ",i);
		}
		printf("\n");
		for (int i = 0; i < r; ++i)
		{
			printf("v%d ",i);
			for (int j = 0; j < r; ++j)
			{
				printf("%d ", g->adj[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Grafo não existe!");
}
void removeAresta(Grafo *g, int v1, int v2)
{
	printf("Removida Aresta %d%d",v1,v2);
	g->adj[v1][v2] = 0;
	g->adj[v2][v1] = 0;
	g->e--;
}
Grafo* destroiGrafo(Grafo *g)
{
	int i;
	if(g)
	{
		printf("Removento vertices: ");
		for(i=0;i<g->v;++i)
		{
			printf("%d, ",i);
			free(g->adj[i]);
		}
		free(g->adj);
		free(g);
		g = NULL;
		printf("\n Grafo Removido\n");
	}
	else
		printf("Grafo não foi iniciado, impossível remover!\n");
	return g;
}
void main()
{
	Grafo *h,*g = criaGrafo(3);
	//destroiGrafo(h);
	insereAresta(g,1,2);
	insereAresta(g,0,2);
	insereAresta(g,0,1);
	imprime(g);
	removeAresta(g,1,2);
	imprime(g);
	destroiGrafo(g);
	
	
}

