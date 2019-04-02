/*
	Autor: Hadamo Egito
*/
#include <stdlib.h>
#include <stdio.h>



typedef struct vert
{
	int val,peso;
	struct vertice *prox;
}vertice;
//estrutura do grafo com num de vertices e arestas e lista de adj
typedef struct grafo
{
	int v,e;
	vertice *adj;
}Grafo;

