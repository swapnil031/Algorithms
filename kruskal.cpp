#include<stdio.h>
#include<stdlib.h>
#define max 20
int G[max][max];
int edges=0;
int ver=0;
int mst=0;
int e=0;

typedef struct vertex{
	int p;
	int r;
}vertex;

vertex v[max];

typedef struct edge{
	int u;
	int v;
	int w;
}edge;
edge E[max*max];
edge A[max];

void makeset(int x){
	v[x].p=x;
	v[x].r=0;
}
int compare(const void *a,const void *b){
	edge* e1=(edge*) a;
	edge* e2=(edge*) b;
	return e1->w - e2->w;
}
int find(int x){
	if(v[x].p==x)
		return v[x].p;
	else find(v[x].p);
}
void unions(int x,int y){
	int a=find(x);
	int b=find(y);
	if(v[a].r>v[b].r){
		v[b].p=x;
	}
	else{
		v[a].p=b;
		if(v[x].r==v[y].r){
			v[y].r+=1;
		}
	}
}
void kruskal(){
	for(int i=0;i<ver;i++){
		makeset(i);
	}
	//int a=edges+1;
	qsort(E,edges,sizeof(edge),compare);
	for(int i=0;i<edges;i++){
		if(find(E[i].u)!=find(E[i].v)){
			A[e]=E[i];
			e++;
			unions(E[i].u,E[i].v);
		}
	}
}
void printmst(){
	for(int i=0;i<e;i++){
		printf("%d - %d ->%d \n",A[i].u,A[i].v,A[i].w);
	}
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
	kruskal();
	printmst();
}