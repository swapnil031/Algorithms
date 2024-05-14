#include<stdio.h>
#include<limits.h>
#define MAX 10

int findmindistanceindex(int n,int distance[],int visited[]){
	int mindistance=INT_MAX,minindex;
	for(int v=0;v<n;v++){
		if(visited[v]==0 && distance[v]<mindistance){
			mindistance=distance[v];
			minindex=v;
		}
	}
	return minindex;
}

void printshortestpath(int n,int distance[]){
    printf("the shortest distances are: \n");
    for(int i=0;i<n;i++){
        printf("%d - %d \n",i,distance[i]);
    }
}

void dijkstra(int n,int G[][MAX],int source){
    int distance[MAX];
    int visited[MAX];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=0;
    }
    distance[source]=0;

    for(int count=0;count<n-1;count++){
        int u=findmindistanceindex(n,distance,visited);
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(G[u][v] && visited[v]==0 && distance[v]>distance[u]+G[u][v]){
                distance[v]=distance[u]+G[u][v];
            }
        }
    }
    printshortestpath(n,distance);
}

void print(int n,int G[][MAX]){
	printf("the adjacency matrix is :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d   ",G[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n,source;
	int G[MAX][MAX];
	FILE *fp=fopen("dijkstra.txt","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&G[i][j]);
		}
	}
	print(n,G);
    printf("enter the source vertex : ");
    scanf("%d",&source);
	dijkstra(n,G,source);
}