#include<stdio.h>
#include<limits.h>
#define max 20

int G[max][max];
int distance[max];
int ver=0;
int edges=0;

typedef struct edge{
    int u;
    int v;
    int w;
}edge;
edge E[max];

void printshortestpath(){
    printf("the shortest distances are: \n");
    for(int i=0;i<ver;i++){
        printf("%d - %d \n",i,distance[i]);
    }
}

void bellman(int s){
    for(int i=0;i<ver;i++){
        distance[i]=INT_MAX;
    }
    distance[s]=0;
    for(int i=0;i<edges;i++){
        if(distance[E[i].u] + E[i].w <distance[E[i].v] && distance[E[i].u]!=INT_MAX){
            distance[E[i].v] = distance[E[i].u] + E[i].w;
        }
    }
    for(int i=0;i<edges;i++){
        if(distance[E[i].u] + E[i].w <distance[E[i].v] && distance[E[i].u]!=INT_MAX){
            //distance[E[i].v] = distance[E[i].u] + E[i].w;
            printf(" negative cycle detected ");
            break;
        }
    }
    printshortestpath();
}
void printG(){
	printf("the adjacency matrix is :\n");
	for(int i=0;i<ver;i++){
		for(int j=0;j<ver;j++){
			printf("%d   ",G[i][j]);
		}
		printf("\n");
	}
}
int main(){
    FILE *fp=fopen("prim.txt","r");
	fscanf(fp,"%d",&ver);
	printf("the no of vertices is %d \n",ver);
	for(int i=0;i<ver;i++){
		for(int j=0;j<ver;j++){
			fscanf(fp,"%d",&G[i][j]);
			if(G[i][j]!=0 && i<j){
				E[edges].u=i;
				E[edges].v=j;
				E[edges].w=G[i][j];
				edges++;
			}
		}
	}
    printG();
}