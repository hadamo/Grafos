#include <bits/stdc++.h>
using namespace std;

typedef struct vertice{
	int val, peso;
	struct vertice *prox;
}Vertice;
typedef struct grafo
{
	int v,e;
	vertice *adj;
}Grafo;
Grafo* criaGrafo(int v)
{
	Grafo *g = (Grafo*) malloc(sizeof(Grafo));
	if (g!=NULL)
	{
		g->v  = v;
		g->e = 0;
		g->adj = (vertice*)calloc(v,sizeof(vertice));
		//todas as adjacencias estarao vazias neste momento
		for (int i = 0; i <v; ++i)
		{
			g->adj[i].prox = NULL;
		}
	}
	return g;
}
vertice* novoVertice(int v, int peso)
{
	vertice *novo = (vertice*)malloc(sizeof(vertice));
	novo -> val = v;
	novo -> peso = peso;
	novo -> prox = NULL;
	return novo;
}
void insereAresta(Grafo *g, int v1, int v2,int peso)
{
	if(v1!=v2)//se nao for laco
	{
		vertice *p = g->adj[v1].prox;
		while(p!=NULL)
		{
			if(p->val == v2) break; //verifica se o vertice ja esta ligado
			p = p->prox;
		}
		/*se terminou de percorrer lista e não achou ocorrencia
		do novo vertice, insere o vertice na lista
		so verifica uma vez pois se trata de grafo simples
		*/
		if(p==NULL)
		{
			//insere novo vertice na adj de v1
			vertice *novo = novoVertice(v2,peso);
			novo->prox = g -> adj[v1].prox;
			g->adj[v1].prox = novo;
			//repete para v2
			novo = novoVertice(v1,peso);
			novo->prox = g->adj[v2].prox;
			g->adj[v2].prox = novo;

			g->e++;
		}
	}
}

int main(){
	int cities,estrada,c1,c2,peso, i;
	cin >> cities >> estrada;
	Vertice *v;
	//essa bagulheira aqui é pra deixar prioridade minima
	priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > > Abertos; // dist[],city
	Grafo *g = criaGrafo(cities);
	//pi : predecessores,  dist: distancia de v0, verificado: vertice ja foi verificado
	int *pi, *dist,*numPedagios;
	pi = (int*)calloc(cities,sizeof(int));
	dist = (int*)malloc(cities* sizeof(int));
	numPedagios = (int*)calloc(cities, sizeof(int));
	//gera grafo com as arestas de entrada
	for (i = 0; i < estrada;i++)
	{
		if(i < cities)
		{
			dist[i] = INT_MAX;
			// numPedagios[i] = -1;
		}
		cin >> c1 >>c2 >>peso;
		insereAresta(g, c1-1, c2-1,peso);
		cin.clear();		
	}
	//prepara origem
	pi[0]--;
	dist[0] = 0;
	Abertos.push(make_pair(dist[0],0) );
	int u,distU;
	//dijkstra
	while(Abertos.size()>0)
	{
		u = Abertos.top().second;
		distU = Abertos.top().first;
		Abertos.pop();

		v = g->adj[u].prox;
		while(v!= NULL)
		{
			if(distU + v->peso < dist[v->val])
			{
				Abertos.push(make_pair(dist[v->val],v->val));
				dist[v->val] = distU + v->peso;	
				numPedagios[v->val]++;
				if(v->val != cities-1)
				{
					pi[v->val] = u;
					//insere os adjascentes a U na lista de prioridade minima
				}
	
			}
			v = v->prox;
		}
	}
	for (int i = 0; i < cities; ++i)
	{
		cout<<dist[i]<<"\t";
	}cout<<"\n";
	//se conseguiu chegar ao fim com numero par de pedagios há um caminho minimo para la
	
	return 0;

}

