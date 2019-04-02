#include <stdio.h>
#include <stdlib.h>

int *conjDisjunto;

int* criaConj(int n)
{
	int *set = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		set[i]=-1;
	}
	return set;
}
//funcao que realiza uniao de conjuntos disjuntos eficientemente
/*
o menor valor encontrado em set[x] informa o conjunto com maior altura
o conjunto com menor altura deve ser colocado dentro do conjunto de maior altura
lembrando que valores em set[i] e set [j] são negativos, pois uniao é apenas entre conjuntos
*/void uniao(int *set,int i, int j)
{

		if(set[i] <= set[j])
		{
			printf("uniao %d no conj %d\n",j,i);
			set[j] = i;
			if(set[i]==set[j]) set[i]--;
		}else
		{
			printf("uniao %d no conj %d\n",i,j);
			set[i] = j;
		}
}
//funcao que retorna o conjunto disjunto do elemento especificado como argumento
// e diminuindo o nivel de vertices quando possivel em cada pesquisa
int find(int *set, int i)
{
	int conj=i,x,y;
	//acha topo que representa conj.Dij. que contem i
	while(set[conj]>-1 )
	{
		conj = set[conj];
	}
	/* Se o conj. encontrado nao for topo direto de i, e i tambem nao for topo de conj
	atualiza topo de i para o conj encontrado*/
	if(conj != set[i] && conj != i) set[i]=conj;
	printf(" %d Esta no conj. %d\n",i,conj ); 
	//falta atualizar altura do topo qd necessario
	return conj;
}
void imprime(int* set, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if(set[i]>=0)
			printf(" %d c= %d",i,set[i]);
		else
			printf(" %d c= %d ",i,i);
	}
	printf("\n");
}

int main()
{
	int *set = criaConj(7);
	uniao(set,0,1);
	uniao(set,2,3);
	uniao(set,4,5);
	uniao(set,0,6);
}