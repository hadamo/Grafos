#include <bits/stdc++.h>
using namespace std;

typedef struct vertice{
	int val, peso;
	char lugar; //c = castelo, v = vila
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
vertice* novoVertice(int v, int peso, int A)
{
	vertice *novo = (vertice*)malloc(sizeof(vertice));
	novo -> val = v;
	novo -> peso = peso;
	novo -> prox = NULL;
	if(v < A) novo -> lugar = 'v';
	else novo -> lugar = 'c';
	return novo;
}
void insereAresta(Grafo *g, int v1, int v2,int peso, int A)
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
			vertice *novo = novoVertice(v2,peso,A);
			novo->prox = g -> adj[v1].prox;
			g->adj[v1].prox = novo;
			g->e++;
			//repete para v2
			novo = novoVertice(v1,peso,A);
			novo->prox = g->adj[v2].prox;
			g->adj[v2].prox = novo;
		}
	}
}

void imprimeGrafo(Grafo *g)
{
	int i;
	vertice *w;
	printf("\nGrafo com %d vertices e %d arestas\n",g -> v, g -> e );
	for(i=0 ; i < g->v ; ++i)
	{
		// if(g->adj[i].val >= A) cout<<"\ncidade ";
		// else cout<<"\nvila ";
		cout <<"v"<<i+1;
		w = g -> adj[i].prox;
		while(w != NULL)
		{
			if(w->lugar == 'v')
				cout<< "( "<<w->lugar <<" "<<w->val+1 <<"|"<<w->peso<<" )";
			else
				cout<< "( "<<w->lugar <<" "<<w->val +1 <<"|"<<w->peso<<" )";
			w = w -> prox;
		}
		printf("¬\n");
	}

}

int main()
{
	int T,A,B,M,L,K,Xi,Yi,Li;
/*	T = num casos de teste
	A = vilas, B = castelos, M = ruas, 
	L = distancia possivel com bota, K = numero de usos da bota
	Xi,Yi pra ligar os vertices, Li peso das arestas*/
	Grafo *g;
	priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > > Abertos; // dist[],city
	//pi : predecessores,  dist: distancia de v0, verificado: vertice ja foi verificado
	int *pi, *dist, numVert;
	cin >> T;
	while(T--)
	{
		cin >> A >> B >> M >> L >> K;
		numVert = A+B;
		g = criaGrafo(numVert);
		pi = (int*)calloc(numVert,sizeof(int));
		dist = (int*)malloc(numVert* sizeof(int));
		for (int i = 0; i < M; ++i)
		{
			if(i<numVert)
			{
				dist[i] = INT_MAX;
			}
			cin >> Xi >> Yi >> Li;
			insereAresta(g,Xi-1,Yi-1,Li,A);
		}
		imprimeGrafo(g);
	}
	
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

		vertice *v = g->adj[u].prox;
		while(v!= NULL)
		{
			if(distU + v->peso < dist[v->val])
			{
				dist[v->val] = distU + v->peso;
				//insere os adjascentes a U na lista de prioridade minima
				Abertos.push(make_pair(dist[v->val],v->val));
				pi[v->val] = u;
			}
			v = v->prox;
		}
	}
}