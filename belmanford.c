#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
typedef struct Edge
{
    int source, destination, weight;
} Edge;
 
typedef struct Graph
{
    int V, E;
    struct Edge* edge;
} Graph;
 
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc( sizeof(Graph));
 
    graph->V = V;
 
    graph->E = E;
 
    graph->edge = (Edge*) malloc( graph->E * sizeof(Edge ) );
 
    return graph;
}
 
void FinalSolution(int dist[], int n)
{
    printf("\nVertex\tDistancia do vertice de origem:\n");
    int i;
 
    for (i = 0; i < n; ++i){
		printf("%d \t\t %d\n", i, dist[i]);
	}
}
 
void BellmanFord(Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;
 
    int StoreDistance[V];
 
    int i,j;
 
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("O Grafo contem ciclo negativo de aresta\n");
    }
 
    FinalSolution(StoreDistance, V);
 
    return;
}
 
int main()
{
    int V,E,S;  
 
	printf("Numero de vertices no grafo:\n");
    scanf("%d",&V);
 
	printf("Numero de arestas no grafo:\n");
    scanf("%d",&E);
 
	printf("Numero do vertice raiz:\n");
	scanf("%d",&S);
 
    Graph* graph = createGraph(V, E);  
 
    int i;
    for(i=0;i<E;i++){
        printf("\nInforme vertice de origem da aresta %d, destino e peso:\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);
 
    return 0;
}