#include<stdio.h>
#include<limits.h>
#define max 20
#define INF 99

int G[max][max];
int v;

int min(int a,int b){
    a<b?a:b;
}

void floydwarshall(){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(G[i][j]>G[i][k]+G[k][j]){
                    G[i][j]= G[i][k]+G[k][j];
                }
            }
        }
    }
}

void printG(){
	printf("the adjacency matrix is :\n");
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("%d \t\t",G[i][j]);
		}
		printf("\n");
	}
}
int main(){
    FILE *fp=fopen("floyd.txt","r");
	fscanf(fp,"%d",&v);
	printf("the no of vertices is %d \n",v);
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			fscanf(fp,"%d",&G[i][j]);
            if(G[i][j]==0 && i!=j){
                G[i][j]=INF;
            }
		}
	}
    printG();
    floydwarshall();
    printG();
}