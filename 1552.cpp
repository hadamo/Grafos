#include <bits/stdc++.h>
using namespace std;

typedef struct vertice
{
	int val;
	double x,y;
	vertice(double a, double b, int c):
		x(a),y(b),val(c){}
}pessoa;
typedef struct aresta
{
	int p1,p2;
	double dist;
	aresta(int a, int b, double c):
		p1(a), p2(b), dist(c){}
	//Usado para função de ordenação
	bool operator<(const aresta &e) const  {  
		return dist < e.dist; 
	} 
}Aresta;
vector<pessoa> V;
vector<Aresta> E;

int find( int i)
{
	int conj=i;
	//acha topo que representa conj.Dij. que contem i
	while(V[conj].val>-1 )
	{
		conj = V[conj].val;
	}
	/* Se o conj. encontrado nao for topo direto de i, e i tambem nao for topo de conj
	atualiza topo de i para o conj encontrado*/
	if(conj != V[i].val && conj != i) V[i].val=conj;
	// printf(" %d Esta no conj. %d\n",i,conj ); 
	return conj;
}
void uniao(int i, int j)
{
	if(V[i].val <= V[j].val)
	{
		V[j].val = i;
		if(V[i].val==V[j].val) V[i].val--;
	}else
	{
		V[i].val = j;
	}
}
int main(){
	//como grafo eh completo, num de arestas - n(n-1)/2
	int casos, numPessoas,numArestas;
	double dist, distMinTotal=0,posX,posY;
	cin >> casos;
	while(casos--)
	{
		cin >> numPessoas;
		numArestas = numPessoas*(numPessoas-1)/2;
		for (int i = 0; i < numPessoas; ++i)
		{
			cin >>posX>>posY;
			V.push_back(vertice(posX,posY,-1));
		}

		for (int i = 0; i < numPessoas; ++i)
		{
			for (int j = 0; j < numPessoas; ++j)
			{
				if(i!=j)
				{
					dist = sqrt(pow(V[j].x - V[i].x,2) + pow(V[j].y - V[i].y,2));
					E.push_back(aresta(i,j,dist));
				}
			}
		}
		sort(E.begin(), E.end());
		numPessoas--;
		//////////Kruskal
		for (int i = 0; i < numArestas && numPessoas > 0; ++i)
		{
			if(find(E[i].p1) != find(E[i].p2) )
			{
				uniao(E[i].p1,E[i].p2);
				distMinTotal += E[i].dist;
				numPessoas--;
			}
		}
		distMinTotal /= 100;
		printf("%.2lf\n",distMinTotal);
	}

}
