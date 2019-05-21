////////////////////////////////////////////////////
/// Hádamo, Atividade Teoria dos grafos URI2404 ///
//////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct aresta
{
	int v1,v2,peso;
}Aresta;

typedef struct heap
{
	Aresta *arestas;
	int sizeAtual, sizeTotal; //sizeatual = espaços utilizados no vetor, sizetotal = verdadeiro tamanho do vetor.
}Heap;

int *conjunto;
Heap *heapArestas;


Heap* criaHeap(int tam)
{
	Heap *h = (Heap*) malloc(sizeof(Heap));
	h->sizeTotal = tam+1;
	h->sizeAtual = 0;
	h->arestas = (Aresta*)calloc(tam+1,sizeof(Aresta));
	return h;
}

void troca(int no1, int no2)
{
	Aresta aux = heapArestas->arestas[no1];
	heapArestas->arestas[no1] = heapArestas->arestas[no2];
	heapArestas->arestas[no2] = aux;
}

void sobeHeap(int no)
{
	//verifica se não é o topo
	if(no > 0)
	{
		//salva o pai
		int pai = no/2;
		//se o no atual for menor que o pai faz a troca e sobe
		if( heapArestas->arestas[no].peso <  heapArestas->arestas[pai].peso)
		{
			troca(no,pai);
			sobeHeap(pai);
		}
	}
}

void desceHeap( int no )
{
	int j = 2*no;
	int sizeAtual = heapArestas -> sizeAtual;
	
	if ( j>0 && j <= sizeAtual )
	{
		if ( ( j+1 <= sizeAtual ) && heapArestas->arestas[j+1].peso < heapArestas->arestas[j].peso  ) j++;
		if ( heapArestas->arestas[no].peso > heapArestas->arestas[j].peso )
		{
			troca( no, j );
			desceHeap( j );
		}
	}
}


void insereHeap(int v1, int v2, int peso)
{
	if(heapArestas->sizeAtual <= heapArestas->sizeTotal)
	{
		heapArestas->sizeAtual++;
		int size = heapArestas->sizeAtual;
		heapArestas->arestas[size].v1 = v1;
		heapArestas->arestas[size].v2 = v2;
		heapArestas->arestas[size].peso = peso;
		sobeHeap( heapArestas->sizeAtual);
		

	}
}

Aresta removeHeap()
{
	Aresta removida = heapArestas->arestas[1];
	if(heapArestas->sizeAtual >= 1)
	{
		troca(1,heapArestas->sizeAtual);
		heapArestas->sizeAtual--;
		desceHeap(1);

	}
	return removida;

}

void uniao(int no1, int no2)
{
	if(conjunto[no1] <= conjunto[no2])
	{
		
		if(conjunto[no1] == conjunto[no2])
			conjunto[no1]--;
		conjunto[no2] = no1;
	}
	else
	{
		conjunto[no1] = no2;
	}

}

int find(int no)
{
	int pai;
	if(conjunto[no] < 0)
	{
		return no;
	}
	else
	{
		pai = find(conjunto[no]);
		conjunto[no] = pai;
		return pai;
	}
}

int main()
{
	int n,m,u,v,c,i,soma = 0; // n cidades, m rodvias,  cidade u, cidade v, custo c
	scanf("%d %d",&n,&m);
	conjunto = (int*)calloc(n+1,sizeof(int));
	for(i = 1; i<= n; i++) conjunto[i]--;
	heapArestas = criaHeap(m);
	for(i=0 ; i < m ; i++)
	{
		scanf("%d %d %d",&u,&v,&c);
		insereHeap(u,v,c);
	}
	for ( i = 1; i <= m; i++)
	{
		Aresta w =  removeHeap();
		if(find(w.v1) != find(w.v2) )
		{
			uniao(find(w.v1), find(w.v2));
			soma += w.peso;
		}
	}
	printf("%d\n",soma );

}
