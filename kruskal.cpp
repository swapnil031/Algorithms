#include <stdio.h>
#include<limits.h>

#define MAX 100

int parent[MAX];

//finding the parent vertex
int findparent(int vertex){
	while(parent[vertex]!=vertex){
		vertex=parent[vertex];
	}
	return vertex;
}

//finding union
void union_set(int u,int v){
	int a=findparent(u);
	int b=findparent(v);
	parent[a]=b;
}

void kruskal(int G[][MAX],int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	int u,v;
	int mincost=0;
	int edge=0;
	while(edge<n-1){
		int minwt=INT_MAX;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(findparent(i) != findparent(j) && G[i][j]<minwt){
					minwt=G[i][j];
					u=i;
					v=j;
				}
			}
		}
		if(findparent(u) != findparent(v)){
			printf("%d - %d -> %d \n",u,v,minwt);
			mincost+=minwt;
			union_set(u,v);
			edge++;
		}
		G[u][v]=G[u][v]=INT_MAX;
	}
	printf("the minimum cost is %d",mincost);
}



void print(int G[][MAX],int n){
	printf("the adjacency matrix is \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n;
	int G[MAX][MAX];
	printf("enter the no of vertices : ");
	scanf("%d",&n);
	printf("enter the adjacency matrix ");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0){
				G[i][j]=INT_MAX;
			}
		}
	}
	print(G,n);
	kruskal(G,n);
}
