#include <bits/stdc++.h>
#include "listaAdjPeso.h"
using namespace std;

typedef struct vertice
{
	int x,y;
}Vertice;

Vertice* criaVertice(int x, int y)
{
	Vertice *novo = (Vertice*)calloc(1,sizeof(Vertice));
	if(novo)
	{
		novo->x = x;
		novo->y = y;
	}
	return novo;
}


int main(){
	/*c = casos de teste, n = pessoas
	x,y = posição das pessoas no plano
	*/
	Vertice *arvore;
	int c,n,x,y;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >>  n;
		arvore = (Vertice*)calloc(n,sizeof(Vertice));
		for (int j = 0; i < n; ++j)
			{
				cin >> x >> y;
				arvore[j] = criaVertice(x,y);
			}	

	}

}