#include<stdio.h>
#define MAX 50

int adjacencyM[MAX][MAX];
int visited[MAX];
int n;
int stack[MAX];
int top=-1;

void push(int a){
    stack[++top]=a;
    return;
}
int pop(){
    int item=stack[top];
    top--;
    return item;
}

void dfs(int n,int start_node){
	int current_node;
	push(start_node);
	visited[start_node]=1;
	while(top>=0){
		current_node=pop();
		printf("%d -> ",current_node);
		for(int i=0;i<n;i++){
			if(adjacencyM[current_node][i] && !visited[i]){
				push(i);
				visited[current_node]=1;
			}
		}
	}
	printf("end");
}

int main(){
    FILE *fp=fopen("ip.txt","r");
	fscanf(fp,"%d",&n);
	printf("%d \n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&adjacencyM[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",adjacencyM[i][j]);
		}
		printf("\n");
	}
	int start_node;
	printf("enter the starting node : ");
	scanf("%d",&start_node);
	printf("The BFS traversal is ");
	dfs(n,start_node);
}